#include "pilha.hpp"

/**
 * att4.7 - Lista 4 exercício 7: Função RECURSIVA para imprimir elementos pilha na ordem inversa.
 * Ordem inversa: base primeiro, topo último (oposto mostraP).
 * Lógica recursão simples:
 * void printInverso(NoPilha* no) {
 *   if (no == NULL) return; // Caso base
 *   printInverso(no->prox); // Primeiro recursa no próximo (base)
 *   cout << no->dado << " "; // Depois printa atual (topo por último)
 * }
 * Não altera pilha. Demo empilha 1-2-3-4 topo=4, printInverso: 1 2 3 4
 */

void printInverso(NoPilha *no) {
    if (no == NULL) return; // Para quando chega no fim (base)
    
    printInverso(no->prox); // Chama recursivo no próximo nó (vai até base primeiro)
    
    cout << no->dado << " "; // Printa dado APÓS recursão (topo por último)
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    cout << "=== PRINT INVERSO RECURSIVO PILHA ===" << endl;
    
    Pilha p;
    cout << "Empilhando 1,2,3,4 (topo=4):" << endl;
    empilhaP(&p, 1);
    empilhaP(&p, 2);
    empilhaP(&p, 3);
    empilhaP(&p, 4);
    
    mostraP(&p, "Pilha normal (topo 4 primeiro)");
    
    cout << "Print inverso recursivo (base 1 primeiro): ";
    printInverso(p.topo);
    cout << endl;
    
    cout << "=== FIM ===" << endl;
    
    destroiP(&p);
    return 0;
}

