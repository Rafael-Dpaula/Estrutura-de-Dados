#include <iostream>
#include <clocale>
using namespace std;
#include "pilha.hpp"

/**
 * att3.6 - Lista 3 ex6: Intercalar P1 P2 to P3.
 * Alt desemp P1 then P2 emp P3 topo.
 * Test exemplo PDF sim.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha p1, p2, p3;
    inicializaP(&p1, 5);
    inicializaP(&p2, 5);
    
    // Ex PDF P1 topo 20 5 4 3 2 base
    empilhaP(&p1, 2); empilhaP(&p1, 3); empilhaP(&p1, 4); empilhaP(&p1, 5); empilhaP(&p1, 20);
    // P2 topo 20 5 4 3 2 ? Exemplo parece mesmo, adjust
    empilhaP(&p2, 2); empilhaP(&p2, 3); empilhaP(&p2, 4); empilhaP(&p2, 5); empilhaP(&p2, 20);
    
    cout << "P1: ";
    mostraP(&p1);
    cout << "P2: ";
    mostraP(&p2);

    intercalaPilha(&p1, &p2, &p3);

    cout << "P3 intercalada: ";
    mostraP(&p3);
    // P1 P2 intact? No, desemp altered! Fix: use aux copy first?
    // Task preserve? PDF not say, assume OK desemp.
    
    destroiP(&p1);
    destroiP(&p2);
    destroiP(&p3);
    cout << "Ex6 OK!" << endl;

    return 0;
}

