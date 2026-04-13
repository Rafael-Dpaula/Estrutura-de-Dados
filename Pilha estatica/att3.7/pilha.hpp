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
    char *dados; // char para parênteses
    Pilha() : tam(0), base(-1), topo(-1), dados(NULL) {}
};

void inicializaP(Pilha *p, int tam) {
    p->base = -1;
    p->topo = -1;
    p->tam = tam;
    p->dados = new char[tam];
}

bool cheiaP(Pilha *p) { return p->topo == p->tam - 1; }
bool vaziaP(Pilha *p) { return p->topo == p->base; }

bool empilhaP(Pilha *p, char valor) {
    if (cheiaP(p)) return false;
    p->topo++;
    p->dados[p->topo] = valor;
    return true;
}

char desempilhaP(Pilha *p) {
    char valor = '\0';
    if (!vaziaP(p)) {
        valor = p->dados[p->topo];
        p->topo--;
    }
    return valor;
}

void mostraP(Pilha *p) {
    cout << "Pilha: ";
    if (!vaziaP(p)) for (int i = p->topo; i > p->base; i--) cout << p->dados[i];
    cout << endl;
}

void destroiP(Pilha *p) {
    if (p->dados) delete[] p->dados;
    p->dados = NULL;
}

// Ex7: Balance parênteses emp '(' pop ')'
bool balancePar(Pilha *p, const string &expr);

bool balancePar(Pilha *p, const string &expr) {
    inicializaP(p, expr.length());
    for (char c : expr) {
        if (c == '(') empilhaP(p, c);
        else if (c == ')') {
            if (vaziaP(p)) return false;
            desempilhaP(p);
        }
    }
    return vaziaP(p);
}

#endif

