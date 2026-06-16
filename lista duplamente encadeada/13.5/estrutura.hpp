#ifndef _HPP_LISTA_DUPLA_13_5
#define _HPP_LISTA_DUPLA_13_5

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

void mostraL(Lista *lista)
{
    No *n = lista->inicio;
    cout << "L[" << lista->tamanho << "]:{";
    while (n)
    {
        cout << n->dado;
        n = n->prox;
        if (n)
            cout << ", ";
    }
    cout << "}\n";
}

void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while (n)
    {
        cout << n->dado;
        n = n->ant;
        if (n)
            cout << ", ";
    }
    cout << "}" << endl;
}

// Exercicio 13.5 - inverter os N ultimos elementos (permitido estruturas auxiliares)
void inverterNFim(Lista *l, int n)
{
    if (!l)
        return;

    if (n > l->tamanho)
        return;
    if (n <= 1)
        return;

    // Copiar os N ultimos valores para um vetor e reconstruir invertendo.
    // Assim o trabalho de ponteiros e bem simples.
    int *v = new int[n];
    int i = 0;

    No *fim = l->fim;
    No *p = fim;

    // Percorrer para chegar no inicio do bloco N (usando ant, sem percorrer aleatorio)
    for (int j = 1; j < n; j++)
        p = p->ant;

    // p agora e o primeiro do bloco N
    while (p)
    {
        v[i++] = p->dado;
        if (p == fim)
            break;
        p = p->prox;
    }

    // Escrever de volta no bloco N invertendo
    No *atual = p; // pode estar no fim, entao vamos recomputar corretamente
    // recomputar atual: primeiro do bloco N
    atual = l->fim;
    for (int j = 1; j < n; j++)
        atual = atual->ant;

    int idx = 0;
    while (atual)
    {
        atual->dado = v[n - 1 - idx];
        idx++;
        if (idx == n)
            break;
        atual = atual->prox;
    }

    delete[] v;
}

#endif

