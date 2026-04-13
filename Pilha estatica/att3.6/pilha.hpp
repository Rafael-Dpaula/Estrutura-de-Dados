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
 * Ex6 Lista3: intercala P1 P2 to P3 alternado topo P1 then P2 (P1 first).
 * Preserve P1 P2 usando aux1 aux2 copy double reverse.
 * P3 novo tam P1+P2.
 */
void intercalaPilha(Pilha *p1, Pilha *p2, Pilha *p3) {
    // Passo1: copy P1 to aux1 preserve ordem (double reverse)
    Pilha aux1, aux2;
    inicializaP(&aux1, p1->tam);
    inicializaP(&aux2, p2->tam);
    while (!vaziaP(p1)) empilhaP(&aux1, desempilhaP(p1));  // reverse1
    while (!vaziaP(&aux1)) empilhaP(p1, desempilhaP(&aux1));  // restore P1, aux1 destroy later
    
    // Copy P2 to aux2 preserve
    while (!vaziaP(p2)) empilhaP(&aux2, desempilhaP(p2));
    while (!vaziaP(&aux2)) empilhaP(p2, desempilhaP(&aux2));  // restore
    
    // No, better: copy to aux without restore yet? Wait, for preserve, copy then use aux for intercala
    // Correct: 
    // Copy P1 to aux1 preserve P1 (double LIFO)
    Pilha cp1, cp2;
    inicializaP(&cp1, p1->tam);
    inicializaP(&cp2, p2->tam);
    
    // Copy P1 to cp1 preserve
    Pilha temp;
    inicializaP(&temp, p1->tam);
    while (!vaziaP(p1)) empilhaP(&temp, desempilhaP(p1));
    while (!vaziaP(&temp)) empilhaP(&cp1, desempilhaP(&temp));  // cp1 = P1 ordem topo
    while (!vaziaP(&temp)) empilhaP(p1, desempilhaP(&temp));  // restore P1
    destroiP(&temp);
    
    // Same for P2 cp2
    inicializaP(&temp, p2->tam);
    while (!vaziaP(p2)) empilhaP(&temp, desempilhaP(p2));
    while (!vaziaP(&temp)) empilhaP(&cp2, desempilhaP(&temp));
    while (!vaziaP(&temp)) empilhaP(p2, desempilhaP(&temp));
    destroiP(&temp);
    
    // Now intercala cp1 cp2 to P3
    inicializaP(p3, p1->tam + p2->tam);
    while (!vaziaP(&cp1) || !vaziaP(&cp2)) {
        if (!vaziaP(&cp1)) empilhaP(p3, desempilhaP(&cp1));
        if (!vaziaP(&cp2)) empilhaP(p3, desempilhaP(&cp2));
    }
    
    destroiP(&cp1);
    destroiP(&cp2);
}

#endif

