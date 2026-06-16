#ifndef _HPP_LISTA_DUPLA_13_4
#define _HPP_LISTA_DUPLA_13_4

#include <iostream>
using namespace std;

struct No
{
    int dado;
    No *prox;
    No *ant;
    No()
    {
        prox = nullptr;
        ant = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista()
    {
        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }
};

void destroiL(Lista *l)
{
    No *n = l->inicio;
    while (n)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = nullptr;
    l->inicio = nullptr;
    l->tamanho = 0;
}

bool vaziaL(Lista *lista)
{
    if (!lista)
        return true;
    return (lista->inicio == nullptr);
}

bool insereInicioL(Lista *lista, int valor)
{
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = nullptr;
    novo->prox = lista->inicio;

    if (lista->fim == nullptr)
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;
    return true;
}

bool insereFimL(Lista *lista, int valor)
{
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = nullptr;
    novo->ant = lista->fim;

    if (lista->fim == nullptr)
        lista->inicio = novo;
    else
        lista->fim->prox = novo;

    lista->fim = novo;
    lista->tamanho++;
    return true;
}

void mostrarMovimentosDireita(Lista *lista, const char *rotulo)
{
    cout << rotulo;
    No *n = lista->inicio;
    while (n)
    {
        cout << n->dado;
        n = n->prox;
        if (n)
            cout << ", ";
    }
    cout << endl;
}

void mostrarInversoMovimentos(Lista *lista, const char *rotulo)
{
    cout << rotulo;
    No *n = lista->fim;
    while (n)
    {
        cout << n->dado;
        n = n->ant;
        if (n)
            cout << ", ";
    }
    cout << endl;
}

#endif

