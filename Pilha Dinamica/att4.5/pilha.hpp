#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <string>

struct NoPilha
{
    int dado;
    NoPilha *prox;
};

struct Pilha
{
    NoPilha *topo;
    Pilha() { topo = nullptr; }
};

bool vaziaP(Pilha *p) { return p->topo == NULL; }

bool empilhaP(Pilha *p, int dado) {
    NoPilha *novo = new NoPilha();
    if (!novo) return false;
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

int desempilhaP(Pilha *p) {
    int dado = 0;
    if (!vaziaP(p)) {
        dado = p->topo->dado;
        NoPilha *apagar = p->topo;
        p->topo = p->topo->prox;
        delete apagar;
    }
    return dado;
}

int espiaP(Pilha *p) { return vaziaP(p) ? 0 : p->topo->dado; }

void mostraP(Pilha *p, string nome = "") {
    cout << "PILHA " << nome << ":" << endl;
    cout << "TOPO: " << p->topo << endl;
    if (!vaziaP(p)) {
        cout << "------------" << endl;
        NoPilha *no = p->topo;
        while (no) {
            cout << no << "|" << no->prox << "|" << no->dado << endl;
            cout << "------------" << endl;
            no = no->prox;
        }
    } else {
        cout << "VAZIA" << endl;
    }
    cout << "------------" << endl;
}

void destroiP(Pilha *p) {
    while (!vaziaP(p)) desempilhaP(p);
}

#endif
