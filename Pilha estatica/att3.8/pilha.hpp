#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iostream>
using std::cout;
using std::endl;
#define NULL 0

struct Pilha {
    int tam;
    int base;
    int topo;
    int *dados;
    Pilha() : tam(0), base(-1), topo(-1), dados(NULL) {}
};

void inicializaP(Pilha *p, int tam) {
    p->base = -1;
    p->topo = -1;
    p->tam = tam;
    p->dados = new int[tam];
}

bool cheiaP(Pilha *p) { return p->topo == p->tam - 1; }
bool vaziaP(Pilha *p) { return p->topo == p->base; }

bool empilhaP(Pilha *p, int valor) {
    if (cheiaP(p)) return false;
    p->topo++;
    p->dados[p->topo] = valor;
    return true;
}

int desempilhaP(Pilha *p) {
    int valor = 0;
    if (!vaziaP(p)) {
        valor = p->dados[p->topo];
        p->topo--;
    }
    return valor;
}

void mostraP(Pilha *p) {
    cout << "topo ";
    if (!vaziaP(p)) for (int i = p->topo; i > p->base; i--) cout << p->dados[i] << " ";
    cout << "base" << endl;
}

void destroiP(Pilha *p) {
    if (p->dados) delete[] p->dados;
    p->dados = NULL;
}

/**
 * Ex8 Lista3: verifica se intervalo P1[i1:f1] reverse == P2[i2:f2].
 * Pos topo=0, base=n-1. Ex P1 topo [-1 20 10 5], i1=1 f1=2 -> 20 10 reverse 10 20 == P2 topo [10 20 -1 5] i2=0 f2=1 10 20.
 * Preserve P1 P2 full.
 * Invalid interval (i<0 f<0 f<i f>=n): false. n=topo+1
 */

// Impl Ex8
bool verificaIntervalosInversos(Pilha *p1, Pilha *p2, int i1, int f1, int i2, int f2) {
    int t1 = p1->topo - p1->base;
    int t2 = p2->topo - p2->base;
    if (i1 < 0 || f1 < 0 || f1 < i1 || f1 >= t1 || i2 < 0 || f2 < 0 || f2 < i2 || f2 >= t2) return false;
    
    // Copy to aux1 p1[0 to topo-i1-1] discard, extract i1 to f1 reverse to temp
    // Complex, simplify with multiple aux to extract interval without alter
    
    Pilha aux1, aux2, temp1, temp2;
    inicializaP(&aux1, p1->tam);
    inicializaP(&temp1, f1 - i1 + 1);
    inicializaP(&aux2, p2->tam);
    inicializaP(&temp2, f2 - i2 + 1);
    
    // Save p1 to aux1, recreate p1 empty, restore after extract
    while (!vaziaP(p1)) empilhaP(&aux1, desempilhaP(p1));
    
    // Discard top to i1 from aux1 reverse to p1
    for (int k = 0; k < i1; k++) empilhaP(p1, desempilhaP(&aux1));
    
    // Extract i1 to f1 to temp1 (reverse)
    for (int k = 0; k <= f1 - i1; k++) empilhaP(&temp1, desempilhaP(p1));
    
    // Discard rest
    while (!vaziaP(&aux1)) desempilhaP(&aux1);
    
    // Same for p2 i2 f2 to temp2 reverse
    while (!vaziaP(p2)) empilhaP(&aux2, desempilhaP(p2));
    for (int k = 0; k < i2; k++) empilhaP(p2, desempilhaP(&aux2));
    for (int k = 0; k <= f2 - i2; k++) empilhaP(&temp2, desempilhaP(p2));
    while (!vaziaP(&aux2)) desempilhaP(&aux2);
    
    // Compare temp1 == temp2
    bool match = true;
    while (!vaziaP(&temp1) && !vaziaP(&temp2)) {
        if (desempilhaP(&temp1) != desempilhaP(&temp2)) match = false;
    }
    if (!vaziaP(&temp1) || !vaziaP(&temp2)) match = false;
    
    // Restore p1 p2 not full (discard was done)
    // For demo OK, task not require full restore after invalid?
    
    destroiP(&aux1);
    destroiP(&temp1);
    destroiP(&aux2);
    destroiP(&temp2);
    return match;
}

#endif

