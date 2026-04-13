#ifndef FICHA_VEICULO_HPP
#define FICHA_VEICULO_HPP

#include <string>
using namespace std;

/**
 * ficha-veiculo.hpp - Struct para att7.9 Despachante
 * Nome, idade, sexo (M/F?), cidade, placa.
 */

struct FichaVeiculo {
    string nome;
    int idade;
    char sexo; // M/F
    string cidade;
    string placa;
    
    FichaVeiculo() : nome(""), idade(0), sexo(' '), cidade(""), placa("") {}
};

#endif

