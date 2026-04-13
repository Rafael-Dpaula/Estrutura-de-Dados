#ifndef PILHA_FICHA_HPP
#define PILHA_FICHA_HPP

#include "ficha.hpp"
#include <iostream>
using namespace std;

/**
 * pilha-ficha.hpp - Pilha dinâmica para Ficha (adaptada).
 */

struct NoPilhaFicha {
    Ficha dado;
    NoPilhaFicha *prox;
};

struct PilhaFicha {
    NoPilhaFicha *topo;
    
    PilhaFicha() : topo(nullptr) {}
};

bool vaziaP(PilhaFicha *p) {
    return p->topo == nullptr;
}

bool empilhaP(PilhaFicha *p, Ficha fich) {
    NoPilhaFicha *novo = new NoPilhaFicha();
    if (!novo) return false;
    
    novo->dado = fich;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

Ficha desempilhaP(PilhaFicha *p) {
    Ficha fich;
    if (!vaziaP(p)) {
        fich = p->topo->dado;
        NoPilhaFicha *apagar = p->topo;
        p->topo = p->topo->prox;
        delete apagar;
    }
    return fich;
}

void mostraP(PilhaFicha *p) {
    cout << "Pilha: TOPO [";
    if (!vaziaP(p)) {
        NoPilhaFicha *no = p->topo;
        while (no) {
            cout << no->dado.nome << "(" << no->dado.idade << "," << no->dado.tipo << "," << no->dado.quadro << ") ";
            no = no->prox;
        }
    }
    cout << "]" << endl;
}

void destroiP(PilhaFicha *p) {
    while (!vaziaP(p)) desempilhaP(p);
}

#endif

