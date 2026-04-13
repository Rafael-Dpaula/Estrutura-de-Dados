#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iostream>
using std::cout;
using std::endl;
#define NULL 0

struct Pilha
{
    int tam;
    int base;
    int topo;
    int *dados;

    Pilha()
    {
        tam = 0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};

void inicializaP(Pilha *p, int tam)
{
    p->base = -1;
    p->topo = -1;
    p->tam = tam;
    p->dados = new int[tam];
}

bool cheiaP(Pilha *p)
{
    return (p->topo == p->tam - 1);
}

bool vaziaP(Pilha *p)
{
    return (p->topo == p->base);
}

bool empilhaP(Pilha *p, int valor)
{
    if (cheiaP(p))
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

bool buscaP(Pilha *p, int valor)
{
    for(int i = p->topo; i > p->base; i--)
        if (valor == p->dados[i])
            return true;
    return false;
}

void mostraP(Pilha *p)
{
    cout << "PILHA topo->base: ";
    if(!vaziaP(p)) {
        for(int i = p->topo; i > p->base; i--) {
            cout << p->dados[i] << " ";
        }
    } else {
        cout << "vazia";
    }
    cout << endl;
}

void destroiP(Pilha *p)
{
    p->base = -1;
    p->topo = -1;
    p->tam = 0;
    if(p->dados != NULL) {
        delete[] p->dados;
        p->dados = NULL;
    }
}

#endif
