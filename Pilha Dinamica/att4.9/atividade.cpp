#include "pilha.hpp"

/**
 * att4.9 - Lista 4 exercício 9: Remover todos elementos ÍMPARES de pilha P, mantém ordem relativa PARES.
 * Exemplo topo 10(par) 1(imp) 2(par) 8(par) 3(imp) 4(par) -> topo 10 2 8 4
 * Lógica com 2 aux:
 * 1. Desempilha P -> pares_aux se par, descarta imp.
 * 2. pares_aux -> pares_rev (reverse ordem)
 * 3. pares_rev -> P (ordem original relativa)
 */

void removeImpares(Pilha *p) {
    Pilha pares, pares_rev;
    
    // Passo 1: Filtra pares ordem topo-base
    while (!vaziaP(p)) {
        int val = desempilhaP(p);
        if (val % 2 == 0) { // Par?
            empilhaP(&pares, val);
        } // Imp descarta
    }
    
    // Passo 2: Reverse pares para ordem relativa original
    while (!vaziaP(&pares)) {
        empilhaP(&pares_rev, desempilhaP(&pares));
    }
    
    // Passo 3: Restaura em P
    while (!vaziaP(&pares_rev)) {
        empilhaP(p, desempilhaP(&pares_rev));
    }
    
    destroiP(&pares); // Limpa (vazio)
    destroiP(&pares_rev);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    cout << "=== REMOVE ÍMPARES MANTE ORD RELATIVA PARES ===" << endl;
    cout << "Ex: 10 1 2 8 3 4 -> 10 2 8 4" << endl << endl;
    
    Pilha p;
    cout << "Empilhando exemplo:" << endl;
    empilhaP(&p, 4);
    empilhaP(&p, 3);
    empilhaP(&p, 8);
    empilhaP(&p, 2);
    empilhaP(&p, 1);
    empilhaP(&p, 10); // topo 10
    
    mostraP(&p, "Antes");
    
    removeImpares(&p);
    
    mostraP(&p, "Após (só pares ordem relativa)");
    
    cout << "=== FIM ===" << endl;
    
    destroiP(&p);
    return 0;
}

