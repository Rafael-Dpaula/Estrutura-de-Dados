#include<iostream>
using namespace std;
#include "pilha.hpp"

int main(){
    Pilha p, aux;
    srand(time(NULL));
    inicializaP(&p, 4);
    empilhaP(&p, rand()%100);
    empilhaP(&p, rand()%100);
    empilhaP(&p, rand()%100);
    empilhaP(&p, rand()%100);
    mostraP(&p);

    cout << "informe o valor a buscar: ";
    int v;
    cin >> v;
    if(buscaP(&p, &aux, v))
        cout << "Achou o valor!" << endl;
    else
        cout << "Não achou o valor!" << endl;
}