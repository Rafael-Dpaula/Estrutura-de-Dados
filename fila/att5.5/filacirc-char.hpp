#ifndef FILACIRC_CHAR_HPP
#define FILACIRC_CHAR_HPP

#include <iostream>
using namespace std;

// Fila circular estática para chars (ex5 palíndromo)
struct FilaChar {
    int tam;
    int total;
    int inicio;
    int fim;
    char *dados;

    FilaChar() : tam(0), total(0), inicio(0), fim(0), dados(nullptr) {}
};

// Inicializa
void inicializaFC(FilaChar* f, int tam) {
    f->tam = tam;
    f->total = 0;
    f->inicio = 0;
    f->fim = 0;
    f->dados = new char[tam];
}

// Verifica init
bool verificaInicializacaoFC(FilaChar* f) {
    return f->dados != nullptr;
}

// Destrói
void destroiFC(FilaChar* f) {
    if (f->dados) delete[] f->dados;
    f->dados = nullptr;
}

// Vazia/cheia
bool vaziaFC(FilaChar* f) { return f->total == 0; }
bool cheiaFC(FilaChar* f) { return f->total == f->tam; }

// Enfileira char
bool enfileiraFC(FilaChar* f, char c) {
    if (!verificaInicializacaoFC(f) || cheiaFC(f)) return false;
    f->dados[f->fim] = c;
    f->fim = (f->fim + 1) % f->tam;
    f->total++;
    return true;
}

// Desenfileira char
char desenfileiraFC(FilaChar* f) {
    char c = '\0';
    if (vaziaFC(f)) return c;
    c = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->tam;
    f->total--;
    return c;
}

#endif

