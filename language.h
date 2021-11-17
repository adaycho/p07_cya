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
* Archivo language.h: clase lenguaje
* @brief Contiene la clase lenguaje
*/

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "chain.h"

const Symbol kEpsilon ("&");
const std::vector<Symbol> kEmptyV {kEpsilon};
const Alphabet kEmptyAlphabet {kEmptyV};
const Chain kEmptyChain {"&", kEmptyAlphabet};

/**
* @brief Clase que almacena un conjunto de cadenas y un alfabeto
*/
class Language{
 public:
  Language(void) : language_(), alphabet_() {};
  Language(const std::vector<Chain>& chains,const Alphabet& alphabet) :
  language_(chains), alphabet_(alphabet) {};
  Alphabet GetAlphabet(void) const;
  int GetSize(void) const;
  friend std::ostream& operator<<(std::ostream& out,
  const Language& language);
  friend std::istream& operator>>(std::istream& in, Language& language);

 private:
  std::vector<Chain> language_;
  Alphabet alphabet_;
};

#endif