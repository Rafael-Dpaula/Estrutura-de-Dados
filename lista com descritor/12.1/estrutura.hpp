#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

#include <iostream>

using namespace std;

struct No
{
    int dado;
    struct No *prox;
    No() // construtor
    {
        prox = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista() // construtor
    {
        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }
};

void mostraL(Lista *lista)
{
    No *n = lista->inicio;

    cout << "L:[" << lista->tamanho << "]{";
    while (n != NULL)
    {
        cout << n->dado;
        n = n->prox;

        if (n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

void destroiL(Lista *lista)
{
    No *n = lista->inicio;
    while (n != nullptr)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

bool vaziaL(Lista *lista)
{
    if (lista->inicio == NULL)
        return true;
    else
        return false;
}

bool insereInicioL(Lista *lista, int valor)
{
    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}

bool insereFimL(Lista *lista, int valor)
{
    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = NULL;

    if (vaziaL(lista))
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return true;
}

bool removeL(Lista *lista, int valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    while (atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (!atual)
        return false;

    if (!anterior)
    {
        lista->inicio = atual->prox;
        if (!lista->inicio)
            lista->fim = lista->inicio;
    }
    else
    {
        anterior->prox = atual->prox;
        if (!atual->prox)
            lista->fim = anterior;
    }

    lista->tamanho--;

    delete (atual);
    return true;
}

No *buscaL(Lista *lista, int valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

#endif // _HPP_LISTA_DESCRITOR

