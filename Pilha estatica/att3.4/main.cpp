#include <iostream>
#include <clocale>
using namespace std;
#include "pilha.hpp"

/**
 * att3.4 - Lista 3 ex4: Inverter ordem elementos pilha com aux pilhas.
 * Usa 2 aux preserve funcs emp/desemp, no dados[i].
 * Menu fill rand, mostra before/after inverterPilha.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha p;
    int tam;
    cout << "Tam: ";
    cin >> tam;
    inicializaP(&p, tam);

    // Fill rand
    for(int i = 0; i < tam/2; i++) empilhaP(&p, rand() % 10 + 1);

    cout << "ANTES: ";
    mostraP(&p);

    inverterPilha(&p);

    cout << "DEPOIS invertida: ";
    mostraP(&p);

    destroiP(&p);
    cout << "Lista3 ex4 OK!" << endl;

    return 0;
}

