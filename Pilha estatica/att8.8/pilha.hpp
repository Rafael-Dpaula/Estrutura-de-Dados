#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iostream>
using namespace std;

struct Pilha
{
    int tam;
    int base;
    int topo;
    int *dados;

    Pilha()
    {
        tam=15; // Máximo 15 para att8.8
        base = -1;
        topo = -1;
        dados = nullptr;
    }
};

void inicializaP(Pilha *p)
{
    p->base = -1;
    p->topo = -1;
    p->dados = new int[p->tam];
}

bool vaziaP(Pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}

bool empilhaP(Pilha *p, int valor)
{
    if (p->topo == p->tam - 1) // cheia
        return false;
    p->topo++;
    p->dados[p->topo] = valor;
    return true;
}

int desempilhaP(Pilha *p)
{
    int valor = 0;
    if (!vaziaP(p))
    {
        valor = p->dados[p->topo];
        p->topo--;
    }
    return valor;
}

void mostraP(Pilha *p)
{
    cout << "Pilha: ";
    if (!vaziaP(p))
    {
        cout << "TOPO ";
        for (int i = p->topo; i >= 0; i--) {
            cout << p->dados[i];
            if (i > 0) cout << " ";
        }
        cout << " BASE" << endl;
    } else {
        cout << "vazia" << endl;
    }
}

void destroiP(Pilha *p)
{
    p->topo = -1;
    delete[] p->dados;
    p->dados = nullptr;
}

#endif

