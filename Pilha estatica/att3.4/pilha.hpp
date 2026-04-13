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

// Ex4: Inverter pilha com aux (2 aux: desemp P emp aux1, desemp aux1 emp aux2 reverse, restore)
void inverterPilha(Pilha *p);

void inverterPilha(Pilha *p) {
    Pilha aux1, aux2;
    inicializaP(&aux1, p->tam);
    inicializaP(&aux2, p->tam);
    
    // P -> aux1 (reverse já por LIFO)
    while (!vaziaP(p)) empilhaP(&aux1, desempilhaP(p));
    
    // aux1 -> aux2 (reverse back)
    while (!vaziaP(&aux1)) empilhaP(&aux2, desempilhaP(&aux1));
    
    // aux2 -> p
    while (!vaziaP(&aux2)) empilhaP(p, desempilhaP(&aux2));
    
    destroiP(&aux1);
    destroiP(&aux2);
}

#endif

