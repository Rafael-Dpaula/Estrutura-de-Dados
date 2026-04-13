#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    int cod, idade, saldo;
    string nome;
};

struct NoPilha
{
    Cliente dado;
    NoPilha *prox;
};

struct Pilha
{
    NoPilha *topo;
    Pilha() { topo = nullptr; }
};

bool vaziaP(Pilha *p) { return p->topo == NULL; }

bool empilhaP(Pilha *p, Cliente dado) {
    NoPilha *novo = new NoPilha();
    if (!novo) return false;
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

Cliente desempilhaP(Pilha *p) {
    Cliente c = {0,0,0,""};
    if (!vaziaP(p)) {
        c = p->topo->dado;
        NoPilha *apagar = p->topo;
        p->topo = p->topo->prox;
        delete apagar;
    }
    return c;
}

Cliente espiaP(Pilha *p) {
    Cliente c = {0,0,0,""};
    if (!vaziaP(p)) c = p->topo->dado;
    return c;
}

void mostraP(Pilha *p, string nome = "") {
    cout << "PILHA " << nome << ":" << endl;
    cout << "TOPO: " << p->topo << endl;
    if (!vaziaP(p)) {
        cout << "------------" << endl;
        NoPilha *no = p->topo;
        while (no) {
            Cliente c = no->dado;
            cout << c.nome << ", cod " << c.cod << ", idade " << c.idade << ", saldo " << c.saldo << endl;
            cout << "------------" << endl;
            no = no->prox;
        }
    } else {
        cout << "VAZIA" << endl;
    }
    cout << "------------" << endl;
}

bool buscaCod(Pilha *p, int cod) {
    NoPilha *no = p->topo;
    while (no) {
        if (no->dado.cod == cod) return true;
        no = no->prox;
    }
    return false;
}

void destroiP(Pilha *p) {
    while (!vaziaP(p)) desempilhaP(p);
}

#endif
