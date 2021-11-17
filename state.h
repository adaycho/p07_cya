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
* Archivo state.h: clase estado
* @brief Contiene la clase estado
*/

#ifndef STATE_H
#define STATE_H

#include <fstream>

/**
* @brief Clase que define los estados de un automata
*/
class State {
 public:
  State() : value_(-1) {};
  State(const int& value) : value_(value) {};
  int GetVal() const;
  friend bool operator==(const State& state1, const State& state2);
  friend bool operator<(const State& state1, const State& state2);
  friend bool operator>(const State& state1, const State& state2);
  friend bool operator!=(const State& state1, const State& state2);
  friend std::ostream& operator<<(std::ostream& out, const State& state);

 private:
  int value_;
};

#endif
