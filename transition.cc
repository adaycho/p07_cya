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
* Archivo transition.cc: clase transición
* @brief Contiene las definiciones de la clase transición
*/

#include "transition.h"

/**
* @brief onstructor del arco
* @param start estado inicial del arco 
* @param symbol símbolo del arco
* @param end estado final del arco 
*/
Transition::Transition(const State& start, const State& end, const Symbol& symbol) {
  start_ = start;
  end_.push_back(end);
  symbol_ = symbol;
}

/**
* @brief Método que comprueba si el arco es el buscado
* @param start estado inicial del arco buscado
* @param symbol símbolo del arco buscado
* @return true si se encuentra el arco, false si si no
*/
bool Transition::CheckArc(const State& start, const Symbol& symbol) const {
  bool flag {false};
  if(start == start_ && symbol == symbol_) {
    flag = true;
  }
  return flag;
}

/**
* @brief Método que devuelve el estado final del arco
* @return devuelve el estado final del arco
*/
std::vector<State> Transition::GetEnd() const {
  return end_;
}

/**
* @brief Añade un estado final a la transición
* @param state añade estado final
*/
void Transition::AddFinalState(const State& state) {
  end_.push_back(state);
}

/**
* @brief Sobrecarga del operador de salida
*/
std::ostream& operator<<(std::ostream& out, const Transition& transition) {
  out << transition.start_ << " " << transition.symbol_ << " " <<  "{";
  for (int j{0}; j < transition.end_.size(); ++j) {
    out << transition.end_[j];
    if (j != transition.end_.size() - 1) {
      out << ",";
    }
  }
  std::cout << "}" << std::endl;
  return out;
}