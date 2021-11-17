/**
* Universidad de La Laguna
* Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 7: Simulación de NFAs
* Correo: alu0101437538@ull.edu.es
* @author Aday Chocho Aisa
* @date 14/11/2021
* Archivo nfa.cc: clase nfa
* @brief Contiene las definiciones de la clase nfa
*/

#include "nfa.h"

/**
* @brief Constructor a partir de un fichero
* @param file archivo donde se encuentra el nfa
*/
Nfa::Nfa(const std::string file) {
  std::ifstream infile(file);
  std::string target;
  std::set<State> state_set;
  getline(infile, target);
  for (int i = 0; i < std::stoi(target); ++i) {
    states_.push_back(i);
    state_set.insert(i);
  }
  getline(infile, target);
  SetInicialState(target);
  while (getline(infile, target)) {
    SetTransitions(target);
    int found;
    State state;
    found = target.find_first_of(kSpace);
    state = std::stoi(target.substr(0, found));
    state_set.erase(state);
  }
  if (state_set.empty() == false) {
    std::cout << "Faltan declaraciones del estado" << std::endl;
    exit( 1 );
  }
  infile.close();
}

/**
* @brief Función que analiza la cadena con el recorrido del NFA
* @param file cadena a analizar
* @return true si es aceptada la cadena, false si no
*/
bool Nfa::Analyze(const Chain& chain) {
  Symbol symbol;
  std::vector<State> state {start_};
  if(chain == kEmptyChain){
    for (int i{0}; i < finish_.size(); ++i) {
      if (finish_[i] == start_) {
        return true;
      }
    }
    return false;
  }
  for (int i{0}; i < chain.GetSize(); ++i) {
    symbol = chain.GetChain()[i];
    std::vector<State> next_state;
    ETransitions(state);
    for (int j{0}; j < state.size(); ++j) {
      for (int k{0}; k < func_.size(); ++k) {
        if (func_[k].CheckArc(state[j], symbol)) {
          std::vector<State> transition_state = func_[k].GetEnd();
          next_state.insert(next_state.end(), transition_state.begin(),
          transition_state.end());
          break;
        }
      }
    }
    state = next_state;
  }
  for (int i{0}; i < finish_.size(); ++i) {
    for (int j{0}; j < state.size(); ++j) {
      if (finish_[i] == state[j]) {
        return true;
      }
    }
  }
  return false;
}

/**
* @brief Método para imprimir el nfa
*/
void Nfa::Print() const {
  std::cout << alphabet_ << std::endl;
  std::cout << start_ << std::endl;
  for (int i{0}; i < finish_.size(); ++i) {
    std::cout << finish_[i] << " ";
  }
  std::cout << std::endl;
  for (int i{0}; i < func_.size(); ++i) {
    std::cout << func_[i];
  };
}

/**
* @brief Metodo para establecer el estado inicial
* @param string cadena del fichero donde se encuentra el estado inicial
*/
void Nfa::SetInicialState(const std::string& string) {
  if (string.find_first_of(kSpace) == -1) {
    start_ = std::stoi(string); 
  }
  else {
    std::cout << "Error, hay más de un estado inicial" << std::endl;
    exit( 1 );
  }
}

/**
* @brief Método para establecer las transiciones
* @param target del fichero donde se encuentra las transiciones
*/
void Nfa::SetTransitions(std::string target) {
  int found;
  State state, start, finish;
  found = target.find_first_of(kSpace);
  start = std::stoi(target.substr(0, found));
  target = target.substr(found +1);
  found = target.find_first_of(kSpace);
  std::string symbol = target.substr(0, found);
  target = target.substr(found +1);
  if (symbol == "1") {
    finish_.push_back(start);
  }
  found = target.find_first_of(kSpace);
  symbol = target.substr(0, found);
  target = target.substr(found +1);
  state = std::stoi(symbol);
  for (int i{0}; i < state; ++i) {
    found = target.find_first_of(kSpace);
    symbol = target.substr(0, found);
    target = target.substr(found +1);
    alphabet_.Insert(symbol);
    found = target.find_first_of(kSpace);
    finish = std::stoi(target.substr(0, found));
    target = target.substr(found +1);
    bool flag = true;
    for (int j{0}; j < func_.size(); ++j) {
      if (func_[j].CheckArc(start, symbol)) {
        func_[j].AddFinalState(finish);
        flag = false;
      }
    }
    if (flag) {
      Transition transition (start, finish, symbol);
      func_.push_back(transition);
    }
  }
}

/**
* @brief Método para comprobar si hay E-transiciones
* @param state vector de estados actuales
*/
void Nfa::ETransitions(std::vector<State> state) {
  bool flag = true;
  while (flag) {
    flag = false;
    std::vector<State> next_state;
    for (int j{0}; j < state.size(); ++j) {
      for (int k{0}; k < func_.size(); ++k) {
        if (func_[k].CheckArc(state[j], kEpsilon)) {
          std::vector<State> transition_state = func_[k].GetEnd();
          next_state.insert(next_state.end(), transition_state.begin(),
          transition_state.end());
          flag = true;
          break;
        }
      }
    }
    state = next_state;
  }
}