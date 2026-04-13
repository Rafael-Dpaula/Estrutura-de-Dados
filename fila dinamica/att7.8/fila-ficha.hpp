#ifndef FILA_FICHA_HPP
#define FILA_FICHA_HPP

#include "ficha.hpp"
#include <iostream>
using namespace std;

/**
 * fila-ficha.hpp - Fila dinâmica para Ficha (adaptada para att7.8).
 * Métodos básicos + mostraF custom.
 */

struct NoFilaFicha {
    Ficha dado;
    NoFilaFicha *prox;
};

struct FilaFicha {
    NoFilaFicha *inicio;
    NoFilaFicha *fim;
    
    FilaFicha() : inicio(nullptr), fim(nullptr) {}
};

bool vaziaF(FilaFicha *f) {
    return f->inicio == nullptr;
}

bool enfileiraF(FilaFicha *f, Ficha fich) {
    NoFilaFicha *novo = new NoFilaFicha();
    if (!novo) return false;
    
    novo->dado = fich;
    novo->prox = nullptr;
    if (vaziaF(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return true;
}

Ficha desenfileiraF(FilaFicha *f) {
    Ficha fich;
    if (!vaziaF(f)) {
        fich = f->inicio->dado;
        NoFilaFicha *apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;
        if (vaziaF(f)) f->fim = nullptr;
    }
    return fich;
}

void mostraF(FilaFicha *f) {
    cout << "Fila: [";
    if (!vaziaF(f)) {
        NoFilaFicha *no = f->inicio;
        while (no) {
            cout << no->dado.nome << "(" << no->dado.idade << "," << no->dado.tipo << "," << no->dado.quadro << ") ";
            no = no->prox;
        }
    }
    cout << "]" << endl;
}

void destroiF(FilaFicha *f) {
    while (!vaziaF(f)) desenfileiraF(f);
}

#endif

