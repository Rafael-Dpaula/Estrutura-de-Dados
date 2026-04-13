#ifndef _HPP_PILHA_CHAR
#define _HPP_PILHA_CHAR

#include <iostream>
#include <cctype> // Para tolower, ispunct
using std::cout;
using std::endl;
#define NULL 0

struct Pilha
{
    int tam;
    int base;
    int topo;
    char *dados;

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
    p->dados = new char[tam];
}

bool cheiaP(Pilha *p)
{
    return (p->topo == p->tam - 1);
}

bool vaziaP(Pilha *p)
{
    return (p->topo == p->base);
}

bool empilhaP(Pilha *p, char valor)
{
    if (cheiaP(p))
        return false;
    p->topo++;
    p->dados[p->topo] = valor;
    return true;
}

char desempilhaP(Pilha *p)
{
    char valor = '\0';
    if (!vaziaP(p))
    {
        valor = p->dados[p->topo];
        p->topo--;
    }
    return valor;
}

void mostraP(Pilha *p)
{
    cout << "Pilha chars topo->base: ";
    if(!vaziaP(p)) {
        for(int i = p->topo; i > p->base; i--) {
            cout << p->dados[i] << " ";
        }
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

