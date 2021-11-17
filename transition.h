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
* Archivo transition.h: clase transición
* @brief Contiene la clase transición
*/

#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include "state.h"
#include "language.h"

/**
* @brief Clase transición, que representa un arco entre nodos
*/
class Transition {
 public:
  Transition(const State& start, const State& end, const Symbol& symbol);
  Transition() : start_(-1), end_(-1), symbol_() {};
  bool CheckArc(const State& start, const Symbol& symbol) const;
  void AddFinalState(const State& state);
  std::vector<State> GetEnd() const;
  friend std::ostream& operator<<(std::ostream& out, const Transition& transition);
 private:
  State start_;
  std::vector<State> end_;
  Symbol symbol_;
};
#endif