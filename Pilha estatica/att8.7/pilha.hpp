#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iostream>
using namespace std;

struct Pilha
{
    int tam;
    int base;
    int topo;
    int *dados; //Vetor que será alocado para armazenar os elementos da pilha

    Pilha() //Construtor. Usado para inicializar os dados das variáveis da struct
    {
        tam=0;
        base = -1;
        topo = -1;
        dados = nullptr; // Ponteiro nulo para dados não alocados
    }
};

void inicializaP(Pilha *p, int tam)
{
    p->base = -1;
    p->topo = -1;
    p->tam  =  tam;
    p->dados = new int[tam]; // Aloca memória dinamicamente para os dados
}

bool verificaInicializacaoP(Pilha *p) //verifica se a pilha foi inicializada
{
    if(p->dados != nullptr) // Verifica se dados foram alocados
        return true;
    else
        return false;
}

void destroiP(Pilha *p)
{
    p->base = -1;
    p->topo = -1;
    p->tam = 0;

    if(p->dados != nullptr) // Verifica se há memória alocada
    {
        delete[] (p->dados);
        p->dados = nullptr; // Limpa ponteiro
    }
}

bool cheiaP(Pilha *p)
{
    if (p->topo == p->tam - 1)
        return true;
    else
        return false;
}

bool vaziaP(Pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}

///push - adiciona elemento no topo
bool empilhaP(Pilha *p, int valor) 
{
    /// retorna false se a pilha não foi inicializada ou se ela está cheia
    if (verificaInicializacaoP(p)==false || cheiaP(p)==true)
        return false;
    else{
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}

///pop - remove elemento do topo
int desempilhaP(Pilha *p)
{
    int valor = 0; //inicializar a variável valor, a qual será retornada

    ///se a pilha foi inicializada && se não estiver vazia, retira valor
    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
        p->topo--;
    }

    return valor;
}

///peek - vê o elemento do topo sem remover
int espiaP(Pilha *p)
{
    int valor = 0; //inicializar a variável valor, a qual será retornada

    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
    }

    return valor;
}

void mostraP(Pilha *p)
{
    cout << "PILHA: " << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO: " << p->topo << endl;
    if(vaziaP(p) == false)
    {
        cout << "------------" << endl;
        for(int i = p->topo; i > p->base; i--){
            cout << i << "| " << p->dados[i]  << endl;
            cout << "------------" << endl;
        }
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor não existe na pilha
bool buscaP(Pilha *p, int valor)
{
   for(int i = p->topo ; i > p->base; i--)
   {
       if (valor == p->dados[i])
          return true;
   }
   return false;
}

#endif // _HPP_PILHA

