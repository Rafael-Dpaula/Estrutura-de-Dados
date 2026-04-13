#include <iostream>
#include <clocale>
using namespace std;
#include "pilha.hpp"

/**
 * att3.8 - Lista 3 ex8: Verifica intervalos inversos P1[i1:f1] == reverse P2[i2:f2].
 * Preserve P1 P2.
 * Ex PDF P1 topo [-1,20,10,5] i1=1 f1=2 (20,10 reverse 10,20), P2 topo [10,20,-1,5] i2=0 f2=1 (10,20).
 * Checks invalid interval.
 * Usa aux para extract without alter.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha p1, p2;
    inicializaP(&p1, 4);
    inicializaP(&p2, 4);

    // Ex PDF
    empilhaP(&p1, 5); empilhaP(&p1, 10); empilhaP(&p1, 20); empilhaP(&p1, -1); // topo -1 20 10 5
    empilhaP(&p2, 5); empilhaP(&p2, -1); empilhaP(&p2, 20); empilhaP(&p2, 10); // topo 10 20 -1 5

    cout << "P1: ";
    mostraP(&p1);
    cout << "P2: ";
    mostraP(&p2);

    int i1=1, f1=2, i2=0, f2=1;
    if (verificaIntervalosInversos(&p1, &p2, i1, f1, i2, f2)) cout << "SIM inversos!" << endl;
    else cout << "NÃO" << endl;

    cout << "P1 after: ";
    mostraP(&p1);
    cout << "P2 after: ";
    mostraP(&p2); // Intact

    // Invalid test
    if (verificaIntervalosInversos(&p1, &p2, -1, 1, 0, 2)) cout << "SIM" << endl;
    else cout << "NÃO (invalid)" << endl;

    destroiP(&p1);
    destroiP(&p2);
    cout << "Ex8 OK!" << endl;
    return 0;
}

