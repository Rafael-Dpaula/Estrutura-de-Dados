#ifndef FILA_PRODUTO_HPP
#define FILA_PRODUTO_HPP

#include <iostream>
#include <string>
using namespace std;

/**
 * fila-produto.hpp - Fila dinâmica para struct Produto (adaptada de fila-dinamica.hpp)
 * Para att7.4 lista7: fila circular -> dinâmica com Produto {nome string, quantidade int}.
 * Métodos: enfileiraF, desenfileiraF, vaziaF, mostraF, destroiF.
 * Comentários simples PT-BR.
 */

struct Produto {
    string nome;    // Nome do produto (ex: "melao")
    int quantidade; // Quantidade em estoque
    
    Produto(string n = "", int q = 0) {
        nome = n;
        quantidade = q;
    }
};

struct NoFilaProduto {
    Produto dado;   // Produto armazenado no nó
    NoFilaProduto *prox; // Ponteiro para próximo nó
};

struct FilaProduto {
    NoFilaProduto *inicio;
    NoFilaProduto *fim;
    
    FilaProduto() {
        inicio = nullptr;
        fim = nullptr;
    }
};

bool vaziaF(FilaProduto *f) {
    return f->inicio == nullptr;
}

bool enfileiraF(FilaProduto *f, Produto p) {
    NoFilaProduto *novo = new NoFilaProduto();
    if (novo == nullptr) return false;
    
    novo->dado = p;
    novo->prox = nullptr;
    if (vaziaF(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return true;
}

Produto desenfileiraF(FilaProduto *f) {
    Produto p("", 0);
    if (!vaziaF(f)) {
        p = f->inicio->dado;
        NoFilaProduto *apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;
        if (vaziaF(f)) f->fim = nullptr;
    }
    return p;
}

void mostraF(FilaProduto *f) {
    cout << "Fila Produto: [";
    if (!vaziaF(f)) {
        NoFilaProduto *no = f->inicio;
        while (no != nullptr) {
            cout << no->dado.nome << "(" << no->dado.quantidade << ")";
            no = no->prox;
            if (no != nullptr) cout << ", ";
        }
    }
    cout << "] (tam=" << /*approx size*/0 << ", total=" << /*total*/0 << ")" << endl; // Adapt tam/total if tracked
}

void destroiF(FilaProduto *f) {
    while (!vaziaF(f)) {
        desenfileiraF(f);
    }
}

#endif

