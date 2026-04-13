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
    int *dados; // Vetor que armazena os elementos da pilha

    Pilha() // Construtor padrão da pilha - inicializa tudo como vazio
    {
        tam = 0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};

// Função para inicializar a pilha com um tamanho específico
// Aloca memória para o vetor dados e define base e topo iniciais
void inicializaP(Pilha *p, int tam)
{
    p->base = -1; // Base sempre -1 para pilha vazia
    p->topo = -1; // Topo igual base quando vazia
    p->tam = tam; // Armazena o tamanho máximo
    p->dados = new int[tam]; // Aloca dinamicamente o vetor de inteiros
}

// Verifica se a pilha está cheia (topo == tam-1)
bool cheiaP(Pilha *p)
{
    if (p->topo == p->tam - 1)
        return true;
    else
        return false;
}

// Verifica se a pilha está vazia (topo == base)
bool vaziaP(Pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}

// Empilha um valor (push) - adiciona no topo se possível
bool empilhaP(Pilha *p, int valor)
{
    if (cheiaP(p)==true)
        return false; // Falha se cheia
    p->topo++; // Incrementa topo
    p->dados[p->topo] = valor; // Coloca valor no novo topo
    return true;
}

// Desempilha (pop) - remove e retorna valor do topo
int desempilhaP(Pilha *p)
{
    int valor = 0;
    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo]; // Pega valor do topo
        p->topo--; // Decrementa topo
    }
    return valor;
}

// Busca se um valor existe na pilha (não usada aqui)
bool buscaP(Pilha *p, int valor)
{
    for(int i = p->topo; i > p->base; i--)
    {
        if (valor == p->dados[i])
            return true; // Encontrou
    }
    return false; // Não encontrou
}

// Mostra a pilha completa, do topo à base
void mostraP(Pilha *p)
{
    cout << "PILHA: " << endl;
    cout << "Tamanho total: " << p->tam << endl;
    cout << "Posição do topo: " << p->topo << endl;
    if(vaziaP(p) == false)
    {
        cout << "------------" << endl;
        for(int i = p->topo; i > p->base; i--)
        {
            cout << "[" << i << "] " << p->dados[i] << endl;
            cout << "------------" << endl;
        }
    }
    else
    {
        cout << "Pilha vazia!" << endl;
    }
}

// Destrói a pilha, liberando memória
void destroiP(Pilha *p)
{
    p->base = -1;
    p->topo = -1;
    p->tam = 0;
    if(p->dados != NULL)
    {
        delete[] (p->dados); // Libera memória alocada
        p->dados = NULL;
    }
}

#endif

