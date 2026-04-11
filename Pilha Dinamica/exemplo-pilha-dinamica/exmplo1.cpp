#include <iostream>
using namespace std;

#include "pilha-dinamica.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Pilha p1;
    int valor;
    bool resultado;

    empilhaP(&p1, 5);
    empilhaP(&p1, 10);
    empilhaP(&p1, 20);
    empilhaP(&p1, -1);

    mostraP(&p1);

    cout << "Desempilhado: " << desempilhaP(&p1) << endl;


    mostraP(&p1);


    //desalocar memória
    destroiP(&p1);


    return EXIT_SUCCESS;

}//final do main

