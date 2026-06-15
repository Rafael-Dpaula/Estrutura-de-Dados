#ifndef PILHA_CHAR_HPP
#define PILHA_CHAR_HPP

#include <iostream>
using namespace std;

// Pilha estática para chars (adaptada do exemplo para exercício 5 lista5)
// Usada para verificar palíndromo junto com fila
struct PilhaChar {
    int tam;
    int base;
    int topo;
    char *dados;  // Vetor char

    PilhaChar() : tam(0), base(-1), topo(-1), dados(nullptr) {}
};

// Inicializa pilha com tamanho
void inicializaPC(PilhaChar *p, int tam) {
    p->base = -1;
    p->topo = -1;
    p->tam = tam;
    p->dados = new char[tam];
}

// Verifica inicialização
bool verificaInicializacaoPC(PilhaChar *p) {
    return p->dados != nullptr;
}

// Destrói
void destroiPC(PilhaChar *p) {
    if (p->dados) delete[] p->dados;
    p->dados = nullptr;
    p->topo = -1;
    p->base = -1;
    p->tam = 0;
}

// Cheia?
bool cheiaPC(PilhaChar *p) {
    return p->topo == p->tam - 1;
}

// Vazia?
bool vaziaPC(PilhaChar *p) {
    return p->topo == p->base;
}

// Push char
bool empilhaPC(PilhaChar *p, char valor) {
    if (!verificaInicializacaoPC(p) || cheiaPC(p)) return false;
    p->topo++;
    p->dados[p->topo] = valor;
    return true;
}

// Pop char
char desempilhaPC(PilhaChar *p) {
    char valor = '\0';
    if (!vaziaPC(p)) {
        valor = p->dados[p->topo];
        p->topo--;
    }
    return valor;
}

#endif

