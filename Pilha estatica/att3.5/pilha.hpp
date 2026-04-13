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

// Ex5: Copiar P1 to P2 ordem relativa (mesma ordem topo-base)
void copiaPilha(Pilha *p1, Pilha *p2);

void copiaPilha(Pilha *p1, Pilha *p2) {
    // Inverter p1 to aux1, inverter aux1 to p2 (double reverse = copy ordem topo)
    Pilha aux1;
    inicializaP(&aux1, p1->tam);
    inicializaP(p2, p1->tam);
    
    // p1 -> aux1 reverse
    while (!vaziaP(p1)) empilhaP(&aux1, desempilhaP(p1));
    
    // aux1 -> p2 reverse back (original ordem)
    while (!vaziaP(&aux1)) empilhaP(p2, desempilhaP(&aux1));
    
    destroiP(&aux1);
}

#endif

