#ifndef _HPP_PILHA_CLIENTE
#define _HPP_PILHA_CLIENTE

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
#define NULL 0

struct Cliente {
    int codigo;
    string nome;
    int idade;
};

struct Pilha
{
    int tam;
    int base;
    int topo;
    Cliente *dados;

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
    p->dados = new Cliente[tam];
}

bool cheiaP(Pilha *p)
{
    return (p->topo == p->tam - 1);
}

bool vaziaP(Pilha *p)
{
    return (p->topo == p->base);
}

bool empilhaP(Pilha *p, Cliente c)
{
    if (cheiaP(p))
        return false;
    p->topo++;
    p->dados[p->topo] = c;
    return true;
}

Cliente desempilhaP(Pilha *p)
{
    Cliente c = {0, "", 0};
    if (!vaziaP(p))
    {
        c = p->dados[p->topo];
        p->topo--;
    }
    return c;
}

Cliente espiaP(Pilha *p)
{
    Cliente c = {0, "", 0};
    if (!vaziaP(p))
        c = p->dados[p->topo];
    return c;
}

bool buscaP(Pilha *p, Cliente c)
{
    for(int i = p->topo; i > p->base; i--)
        if (p->dados[i].codigo == c.codigo)
            return true;
    return false;
}

// Função específica do Ex7: busca por codigo
bool buscaCliente(Pilha *p, int codigo)
{
    Cliente temp = {codigo, "", 0};
    return buscaP(p, temp);
}

void mostraP(Pilha *p)
{
    cout << "topo {";
    if(!vaziaP(p)) {
        for(int i = p->topo; i > p->base; i--) {
            cout << "[" << p->dados[i].codigo << "," << p->dados[i].nome << "," << p->dados[i].idade << "] ";
        }
    }
    cout << "} base" << endl;
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

