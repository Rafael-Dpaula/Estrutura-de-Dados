#ifndef _HPP_PILHA_STRING
#define _HPP_PILHA_STRING

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
#define NULL 0

struct Pilha
{
    int tam;
    int base;
    int topo;
    string *dados; // Agora string em vez de int

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
    p->dados = new string[tam]; // Aloca strings
}

bool cheiaP(Pilha *p)
{
    return (p->topo == p->tam - 1);
}

bool vaziaP(Pilha *p)
{
    return (p->topo == p->base);
}

bool empilhaP(Pilha *p, string valor)
{
    if (cheiaP(p))
        return false;
    p->topo++;
    p->dados[p->topo] = valor;
    return true;
}

string desempilhaP(Pilha *p)
{
    string valor = "";
    if (!vaziaP(p))
    {
        valor = p->dados[p->topo];
        p->topo--;
    }
    return valor;
}

string espiaP(Pilha *p)
{
    string valor = "";
    if (!vaziaP(p))
        valor = p->dados[p->topo];
    return valor;
}

bool buscaP(Pilha *p, string valor)
{
    for(int i = p->topo; i > p->base; i--)
        if (p->dados[i] == valor)
            return true;
    return false;
}

void mostraP(Pilha *p)
{
    cout << "Pilha topo->base: ";
    if(!vaziaP(p)) {
        for(int i = p->topo; i > p->base; i--) {
            cout << "\"" << p->dados[i] << "\" ";
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

