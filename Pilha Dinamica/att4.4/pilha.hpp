#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <string> // Para formatar impressão da pilha

struct NoPilha
{
    int dado; // Informação do nó (usado para char cast)
    NoPilha *prox; // Próximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha() { // Construtor - inicia pilha vazia
        topo = nullptr;
    }
};

bool vaziaP(Pilha *p)
{
    return p->topo == NULL;
}

// Empilha (push)
bool empilhaP(Pilha *p, int dado)
{
    NoPilha *novo = new NoPilha();
    if (novo == NULL) return false; // Falha alocação memória

    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

// Desempilha (pop)
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

// Espia topo sem remover
int espiaP(Pilha *p)
{
    return vaziaP(p) ? 0 : p->topo->dado;
}

void mostraP(Pilha *p, string nome = "")
{
    cout << "PILHA " << nome << ":" << endl;
    cout << "TOPO: " << p->topo << endl;
    if (!vaziaP(p)) {
        cout << "------------" << endl;
        NoPilha *no = p->topo;
        while (no != NULL) {
            cout << no << "|" << no->prox << "|" << (char)no->dado << endl; // Cast char para expr
            cout << "------------" << endl;
            no = no->prox;
        }
    } else {
        cout << "VAZIA" << endl;
    }
    cout << "------------" << endl;
}

void destroiP(Pilha *p)
{
    while (!vaziaP(p)) desempilhaP(p);
}

#endif
