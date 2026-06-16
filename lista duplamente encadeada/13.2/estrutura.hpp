#ifndef _HPP_LISTA_DUPLA_13_2
#define _HPP_LISTA_DUPLA_13_2

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

// Exercicio 13.2 - RemoveFim (proibido percorrer e listas auxiliares)
// Usa-se o ponteiro ant do ultimo nó.
bool RemoveFim(Lista *lista)
{
    if (vaziaL(lista))
        return false;

    No *ultimo = lista->fim;
    No *ant = ultimo->ant;

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

    delete ultimo;
    lista->tamanho--;
    return true;
}

#endif

