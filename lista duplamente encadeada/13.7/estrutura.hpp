#ifndef _HPP_LISTA_DUPLA_13_7
#define _HPP_LISTA_DUPLA_13_7

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

void mostraL(Lista *lista, const char *rotulo)
{
    cout << rotulo << " L[" << lista->tamanho << "]:{";
    No *n = lista->inicio;
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
    cout << rotulo << " L[" << lista->tamanho << "]:{";
    No *n = lista->fim;
    while (n)
    {
        cout << n->dado;
        n = n->ant;
        if (n)
            cout << ", ";
    }
    cout << "}" << endl;
}

// Exercicio 13.7:
// concatenarListas(L1, L2, L3) sem estruturas auxiliares e sem lacos de repeticao.
// - Se L1 ou L2 estiver vazia, nao concatena.
// - Os nos sao os mesmos: conecta fim de L1 ao inicio de L2.
// - Depois, L1 e L2 ficam vazias.
void concatenarListas(Lista *l1, Lista *l2, Lista *l3)
{
    if (!l1 || !l2 || !l3)
        return;

    if (l1->inicio == nullptr)
        return;
    if (l2->inicio == nullptr)
        return;

    l3->inicio = l1->inicio;
    l3->fim = l2->fim;
    l3->tamanho = l1->tamanho + l2->tamanho;

    // Conectar
    l1->fim->prox = l2->inicio;
    l2->inicio->ant = l1->fim;

    // Tornar l1 e l2 vazias (nao desalocar nos)
    l1->inicio = nullptr;
    l1->fim = nullptr;
    l1->tamanho = 0;

    l2->inicio = nullptr;
    l2->fim = nullptr;
    l2->tamanho = 0;
}

#endif

