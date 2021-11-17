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
* Archivo state.cc: clase estado
* @brief Contiene las definiciones de la clase estado
*/

#include "state.h"

/**
* @brief Método que retorna el valor que marca al estado
*/
int State::GetVal() const {
  return value_;
}

/**
* @brief Sobrecarga del operador menor que
*/
bool operator<(const State& state1, const State& state2) {
  return state1.value_ < state2.value_;
}

/**
* @brief Sobrecarga del operador mayor que
*/
bool operator>(const State& state1, const State& state2) {
  return state1.value_ > state2.value_;
}

/**
* @brief Sobrecarga del operador de igualdad
*/
bool operator==(const State& state1, const State& state2) {
  return state1.value_ == state2.value_;
}

/**
* @brief Sobrecarga del operador de desigualdad
*/
bool operator!=(const State& state1, const State& state2) {
  return state1.value_ != state2.value_;
}

/**
* @brief Sobrecarga del operador de salida
*/
std::ostream& operator<<(std::ostream& out, const State& state) {
  out << state.GetVal();
  return out;
}
