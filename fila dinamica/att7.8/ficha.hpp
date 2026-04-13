#ifndef FICHA_HPP
#define FICHA_HPP

#include <string>
using namespace std;

/**
 * ficha.hpp - Struct para att7.8 Veterinária
 * Ficha: nome, idade, tipo (S/D), quadro (E/G).
 */

struct Ficha {
    string nome;
    int idade;
    char tipo; // S-selvagem, D-doméstico
    char quadro; // E-estável, G-grave
    
    Ficha() : nome(""), idade(0), tipo(' '), quadro(' ') {}
};

#endif

