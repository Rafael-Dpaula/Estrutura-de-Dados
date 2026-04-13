#include <iostream>
#include <clocale>
using namespace std;
#include "pilha.hpp"

/**
 * att3.5 - Lista 3 ex5: Copiar P1 para P2 mantendo ordem relativa.
 * Usa 1 aux + double reverse emp/desemp.
 * Test P1 fill rand, copia, mostra before/after.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha p1, p2;
    int tam;
    cout << "Tam P1: ";
    cin >> tam;
    inicializaP(&p1, tam);

    // Fill P1 rand
    for(int i = 0; i < tam/2; i++) empilhaP(&p1, rand() % 10 + 1);

    cout << "P1 antes copia: ";
    mostraP(&p1);

    copiaPilha(&p1, &p2);

    cout << "P2 copia: ";
    mostraP(&p2);
    cout << "P1 intacta: ";
    mostraP(&p1);

    destroiP(&p1);
    destroiP(&p2);
    cout << "Ex5 OK!" << endl;

    return 0;
}

