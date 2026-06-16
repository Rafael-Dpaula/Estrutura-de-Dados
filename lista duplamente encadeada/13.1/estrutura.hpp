#ifndef _HPP_LISTA_DUPLA_13_1
#define _HPP_LISTA_DUPLA_13_1

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
    if (!(lista->inicio))
        return true;
    return false;
}

void mostraL(Lista *lista, const char *rotulo)
{
    No *n = lista->inicio;
    cout << rotulo << " L[" << lista->tamanho << "]:{";
    while (n)
    {
        cout << n->dado;
        n = n->prox;
        if (n)
            cout << ", ";
    }
    cout << "}\n";
}

void mostrarInversoL(Lista *lista, const char *rotulo)
{
    No *n = lista->fim;
    cout << rotulo << " L[" << lista->tamanho << "]:{";
    while (n)
    {
        cout << n->dado;
        n = n->ant;
        if (n)
            cout << ", ";
    }
    cout << "}" << endl;
}

bool insereInicioL(Lista *lista, int valor)
{
    No *novo = new No();
    if (novo == nullptr)
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

No *buscaL(Lista *lista, int valor)
{
    if (!lista)
        return nullptr;

    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;
        n = n->prox;
    }
    return nullptr;
}

bool removerNoL(Lista *lista, No *no)
{
    if (!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant)
    {
        lista->inicio = no->prox;
        if (!lista->inicio)
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;
    }
    else
    {
        no->ant->prox = no->prox;
        if (!no->prox)
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;
    }

    lista->tamanho--;
    delete no;
    return true;
}

// Exercicio 13.1 - inserir no final da lista (sem percorrer)
bool insereFimL(Lista *lista, int valor)
{
    No *novo = new No();
    if (novo == nullptr)
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

// Exercicio 13.1 - remover primeiro elemento (sem percorrer)
bool removeInicioL(Lista *lista)
{
    if (vaziaL(lista))
        return false;

    No *rem = lista->inicio;
    lista->inicio = rem->prox;

    if (!lista->inicio)
        lista->fim = nullptr;
    else
        lista->inicio->ant = nullptr;

    delete rem;
    lista->tamanho--;
    return true;
}

// Exercicio 13.1 - remover ultimo elemento (sem percorrer)
bool removeFimL(Lista *lista)
{
    if (vaziaL(lista))
        return false;

    No *rem = lista->fim;
    No *ant = rem->ant;

    if (!ant)
    {
        lista->inicio = nullptr;
        lista->fim = nullptr;
    }
    else
    {
        ant->prox = nullptr;
        lista->fim = ant;
    }

    delete rem;
    lista->tamanho--;
    return true;
}

#endif

