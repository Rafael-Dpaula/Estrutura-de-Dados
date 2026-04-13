#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA

#include "pessoa.hpp"

struct NoFila
{
    Pessoa dado; 
    NoFila *prox; 
};

struct Fila
{
    NoFila *inicio;
    NoFila *fim;

    Fila(){  
        inicio = nullptr;
        fim = nullptr;
    } 
};

bool vaziaF(Fila *f)
{
    return f->inicio == nullptr;
}

bool enfileiraF(Fila *f, Pessoa pessoa)
{
    NoFila *novo = new NoFila(); 
    if (novo == nullptr) return false;

    novo->dado = pessoa;
    novo->prox = nullptr;
    if (vaziaF(f)) 
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

Pessoa desenfileiraF(Fila *f)
{
    Pessoa p; 
    if (!vaziaF(f)) {
        p = f->inicio->dado;
        NoFila *apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;
        if (vaziaF(f)) f->fim = nullptr;
    }
    return p;
}

void mostraF(Fila *f)
{
    cout << "Fila: inicio{";
    if (!vaziaF(f)) {
        NoFila *no = f->inicio;
        while (no != nullptr) {
            cout << "[" << no->dado.nome << ", " << fixed << setprecision(2) << no->dado.salario << "]";
            no = no->prox;
            if (no != nullptr) cout << ", ";
        }
    }
    cout << "}fim" << endl;
}

void destroiF(Fila *f)
{
    while (!vaziaF(f)) {
        desenfileiraF(f);
    }
}

#endif

