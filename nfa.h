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
* Archivo nfa.h: clase nfa
* @brief Contiene la clase nfa
*/

#ifndef NFA_H
#define NFA_H

#include "transition.h"
#include <string>

/**
* @brief Clase que almacena un Autómata Finito Determinista
*/
class Nfa {
 public:
  Nfa() : alphabet_(), states_(), start_(0), finish_(), func_() {};
  Nfa(const std::string file);
  bool Analyze (const Chain& chain);
  void Print() const;
  void SetInicialState(const std::string& string);
  void SetTransitions(std::string target);
  void ETransitions(std::vector<State> state);
 private:
  Alphabet alphabet_;
  std::vector<State> states_;
  State start_;
  std::vector<State> finish_;
  std::vector<Transition> func_;
};

#endif