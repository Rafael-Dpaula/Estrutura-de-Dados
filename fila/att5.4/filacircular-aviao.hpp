#ifndef FILA_CIRCULAR_AVIAO_HPP
#define FILA_CIRCULAR_AVIAO_HPP

#include <iostream>
#include <string>
using namespace std;

#include "aviao.hpp"  // Struct Aviao

// Fila circular estática para aviões (máx 5)
struct FilaAviao {
    int tam;       // Sempre 5 para pista
    int total;     // Elementos atuais
    int inicio;
    int fim;
    Aviao *dados;  // Vetor de aviões

    FilaAviao() : tam(5), total(0), inicio(0), fim(0), dados(nullptr) {}  // tam fixo 5
};

// Inicializa fila aeroporto (tam=5 fixo)
void inicializaFA(FilaAviao* f) {
    f->total = 0;
    f->inicio = 0;
    f->fim = 0;
    f->dados = new Aviao[f->tam];
}

// Verifica inicialização
bool verificaInicializacaoFA(FilaAviao* f) {
    return f->dados != nullptr;
}

// Destrói fila
void destroiFA(FilaAviao* f) {
    if (f->dados) {
        delete[] f->dados;
        f->dados = nullptr;
    }
    f->total = 0;
}

// Vazia?
bool vaziaFA(FilaAviao* f) {
    return f->total == 0;
}

// Cheia?
bool cheiaFA(FilaAviao* f) {
    return f->total == f->tam;
}

// Conta aviões (total)
int contaFA(FilaAviao* f) {
    return f->total;
}

// Enfileira avião (fila para decolar)
bool enfileiraFA(FilaAviao* f, Aviao aviao) {
    if (!verificaInicializacaoFA(f) || cheiaFA(f)) return false;
    f->dados[f->fim] = aviao;
    f->fim = (f->fim + 1) % f->tam;
    f->total++;
    return true;
}

// Desenfileira (decola)
Aviao desenfileiraFA(FilaAviao* f) {
    Aviao aviao;
    if (vaziaFA(f)) return aviao;
    aviao = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->tam;
    f->total--;
    return aviao;
}

// Peek: próximo a decolar (sem remover)
Aviao proximoFA(FilaAviao* f) {
    Aviao aviao;
    if (vaziaFA(f)) return aviao;
    return f->dados[f->inicio];
}

// Lista todos esperando
void listaFA(FilaAviao* f) {
    if (vaziaFA(f)) {
        cout << "Nenhum avião na pista!" << endl;
        return;
    }
    cout << "Aviões na pista (da frente ao trás):" << endl;
    int idx = f->inicio;
    for (int i = 0; i < f->total; i++) {
        cout << "- ";
        f->dados[idx].mostrar();
        idx = (idx + 1) % f->tam;
    }
}

#endif

