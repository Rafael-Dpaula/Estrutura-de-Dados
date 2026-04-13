#ifndef PILHA_VEICULO_HPP
#define PILHA_VEICULO_HPP

#include "ficha-veiculo.hpp"
#include <iostream>
using namespace std;

/**
 * pilha-veiculo.hpp - Pilha dinâmica para FichaVeiculo (PF e GERAL).
 */

struct NoPilhaVeiculo {
    FichaVeiculo dado;
    NoPilhaVeiculo *prox;
};

struct PilhaVeiculo {
    NoPilhaVeiculo *topo;
    
    PilhaVeiculo() : topo(nullptr) {}
};

bool vaziaP(PilhaVeiculo *p) {
    return p->topo == nullptr;
}

bool empilhaP(PilhaVeiculo *p, FichaVeiculo fich) {
    NoPilhaVeiculo *novo = new NoPilhaVeiculo();
    if (!novo) return false;
    
    novo->dado = fich;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

FichaVeiculo desempilhaP(PilhaVeiculo *p) {
    FichaVeiculo fich;
    if (!vaziaP(p)) {
        fich = p->topo->dado;
        NoPilhaVeiculo *apagar = p->topo;
        p->topo = p->topo->prox;
        delete apagar;
    }
    return fich;
}

void mostraP(PilhaVeiculo *p, string nome) {
    cout << nome << ": TOPO [";
    if (!vaziaP(p)) {
        NoPilhaVeiculo *no = p->topo;
        while (no) {
            cout << no->dado.nome << "(" << no->dado.idade << "," << no->dado.sexo << "," << no->dado.cidade << "," << no->dado.placa << ") ";
            no = no->prox;
        }
    }
    cout << "]" << endl;
}

void destroiP(PilhaVeiculo *p) {
    while (!vaziaP(p)) desempilhaP(p);
}

#endif

