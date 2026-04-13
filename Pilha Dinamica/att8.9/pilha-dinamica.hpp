#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iostream>
#include <string>
using namespace std;

struct NoPilha
{
    int dado;
    NoPilha *prox;
};

struct Pilha
{
    NoPilha *topo;

    Pilha(){
        topo = nullptr;
    }
};

bool vaziaP(Pilha *p)
{
    return p->topo == nullptr;
}

bool empilhaP(Pilha *p, int dado)
{
    NoPilha *novo = new NoPilha();
    if (novo == nullptr) return false;

    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

int desempilhaP(Pilha *p)
{
    int dado = 0;
    if (!vaziaP(p)) {
        dado = p->topo->dado;
        NoPilha *apagar = p->topo;
        p->topo = p->topo->prox;
        delete apagar;
    }
    return dado;
}

int espiaP(Pilha* p)
{
    return vaziaP(p) ? 0 : p->topo->dado;
}

void mostraP(Pilha *p, string nome="")
{
    cout << "PILHA " << nome << ": " << endl;
    if(vaziaP(p)) {
        cout << "VAZIA" << endl;
        return;
    }
    NoPilha *no = p->topo;
    cout << "TOPO ";
    while (no != nullptr) {
        cout << no->dado << " ";
        no = no->prox;
    }
    cout << "BASE" << endl;
}

bool buscaP(Pilha *p, int dado)
{
    NoPilha *no = p->topo;
    while (no != nullptr) {
        if (no->dado == dado) return true;
        no = no->prox;
    }
    return false;
}

void destroiP(Pilha *p)
{
    while (!vaziaP(p)) {
        desempilhaP(p);
    }
}

#endif
