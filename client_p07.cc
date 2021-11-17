/**
* Universidad de La Laguna
* Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 7: Simulación de NFAs
* Autor: Aday Chocho Aisa
* Correo: alu0101437538@ull.edu.es
* Fecha: 14/11/2021
* Archivo client_p06.cc: programa cliente
* Contiene la función principal del proyecto
* Referencias:
* Enlaces de interés:
*/

#include <iostream>
#include "nfa.h"

void Help(char* argv[]) {
  std::cout << argv[0] << std::endl;
  std::cout << "El programa pide por parámetros tres ficheros: un fichero "
  << ".nfa que creará el autómata, un fichero de entrada que contendrá "
  << "cadenas a analizar y un fichero de salida donde devolverá las "
  << "cadenas y si son aceptadas o no por el nfa. ";
  std::cout << "Modo de empleo: " << std::endl << argv[0] <<
  " [Fichero NFA] [Fichero de entrada] [Fichero de salida]" << std::endl;
}

void MissingParameters(char* argv[]) {
  std::cout << argv[0] << std::endl;
  std::cout << "Modo de empleo: " << std::endl << argv[0] <<
  " [Fichero NFA] [Fichero de entrada] [Fichero de salida]" << std::endl;
  std::cout << "Para más información, use " << argv[0] << " --help";
  std::cout << std::endl;
}

void MainFuction(const int& argc, char* argv[]) {
  if (argc == 4) {
    Nfa nfa(argv[1]);
    std::string target;
    std::ifstream infile(argv[2]);
    std::ofstream outfile(argv[3]);
    while (getline(infile, target)) {
      outfile << target << " -- ";
      if (nfa.Analyze(target)) {
        outfile << "Accepted" << std::endl;
      }
      else {
        outfile << "Rejected" << std::endl;
      }
    }
    infile.close();
    outfile.close();
  }
  else if (argc == 2) {
    std::string option = argv[1];
    if (option == "--help" || option == "-h") {
      Help(argv);
    }
    else {
      MissingParameters(argv);
    }
  }
  else {
    MissingParameters(argv);
  }
}

int main(int argc, char* argv[]) {
  MainFuction(argc, argv);
  return 0;
}