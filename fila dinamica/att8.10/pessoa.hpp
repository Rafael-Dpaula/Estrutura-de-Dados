#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
using namespace std;

struct Pessoa{
    string nome; 
    float salario; 
    Pessoa(){
        nome = "";
        salario = 0;
    } 
    Pessoa(string n, float s){
        nome = n;
        salario = s;
    } 
};

#endif

