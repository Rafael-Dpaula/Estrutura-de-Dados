#include <iostream>
using namespace std;
#include "pilha.hpp"

/**
 * att4.5 - Lista 4 exercício 5: Copiar dados de P1 para P2 preservando P1 (mesma ordem).
 * Lógica simples com pilha auxiliar AUX:
 * 1. Desempilha P1 -> AUX (inverte ordem em AUX)
 * 2. Desempilha AUX -> P2 (P2 agora = original P1 ordem topo-base)
 * 3. Desempilha P2 -> P1 (P1 restaurada)
 * Result: P1 e P2 idênticos, mesma ordem.
 * Demo: Empilha valores em P1, copia P2, mostra ambas.
 */

void copia(Pilha *p1, Pilha *p2) {
    Pilha aux;
    
    // Passo 1: Move P1 para AUX (inverte)
    while (!vaziaP(p1)) {
        empilhaP(&aux, desempilhaP(p1));
    }
    
    // Passo 2: Move AUX para P2 (P2 = original P1)
    while (!vaziaP(&aux)) {
        empilhaP(p2, desempilhaP(&aux));
    }
    
    // Passo 3: Move P2 para P1 (restaura P1)
    while (!vaziaP(p2)) {
        empilhaP(p1, desempilhaP(p2));
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    cout << "=== COPIAR PILHA P1 -> P2 (PRESERVANDO P1) ===" << endl;
    
    Pilha p1, p2;
    
    // Demo: Empilha valores exemplo em P1
    cout << "Empilhando em P1: 10, 20, 30, 40" << endl;
    empilhaP(&p1, 10);
    empilhaP(&p1, 20);
    empilhaP(&p1, 30);
    empilhaP(&p1, 40);
    
    mostraP(&p1, "P1 antes copia");
    mostraP(&p2, "P2 antes copia (vazia)");
    
    copia(&p1, &p2);
    
    mostraP(&p1, "P1 após copia (preservada!)");
    mostraP(&p2, "P2 após copia (igual P1)");
    
    cout << "=== FIM - COPIA OK ===" << endl;
    
    destroiP(&p1);
    destroiP(&p2);
    return 0;
}

