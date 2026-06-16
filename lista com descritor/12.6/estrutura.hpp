#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

#include <iostream>
#include <string>

using namespace std;

struct Reuniao
{
    string titulo;
    int duracao; // minutos
};

struct No
{
    Reuniao dado;
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
        cout << "(" << n->dado.titulo << ", " << n->dado.duracao << ")";
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

bool insereInicioL(Lista *lista, Reuniao valor)
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

bool insereFimL(Lista *lista, Reuniao valor)
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

#endif // _HPP_LISTA_DESCRITOR

