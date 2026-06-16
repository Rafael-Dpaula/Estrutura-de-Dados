#ifndef _HPP_LISTA_DUPLA_13_3
#define _HPP_LISTA_DUPLA_13_3

#include <iostream>
#include <cstdlib>
using namespace std;

struct No
{
    int dado;
    No *prox;
;
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

bool removerNoL(Lista *lista, No *no)
{
    if (!lista || !no || vaziaL(lista))
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

    delete no;
    lista->tamanho--;
    return true;
}

// Exercicio 13.3 - remove da lista todas as ocorrencias de 'valor'
void removeTodos(Lista *L, int valor)
{
    if (!L)
        return;

    No *n = L->inicio;
    while (n)
    {
        No *prox = n->prox;
        if (n->dado == valor)
            removerNoL(L, n);
        n = prox;
    }
}

// Insere um valor em ordem crescente (por simplicidade) numa lista.
// Para montar a lista dos K maiores em ordem crescente, basta inserir assim.
bool insereOrdenadoCrescente(Lista *L, int valor)
{
    if (!L)
        return false;

    if (L->tamanho == 0)
        return insereInicioL(L, valor);

    No *n = L->inicio;
    while (n && n->dado <= valor)
        n = n->prox;

    if (!n)
        return insereFimL(L, valor);

    // Inserir antes de n
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = n;
    novo->ant = n->ant;

    if (n->ant)
        n->ant->prox = novo;
    else
        L->inicio = novo;

    n->ant = novo;
    L->tamanho++;
    return true;
}

// Exercicio 13.3 - retorna uma nova lista, ordenada, com os K maiores elementos de L.
// Se K > tamanho de L, retorna todos os elementos ordenados.
Lista leMaiores(Lista *L, int K)
{
    Lista resp;
    if (!L)
        return resp;

    int total = L->tamanho;
    int k = K;
    if (k > total)
        k = total;
    if (k <= 0)
        return resp;

    // Estrategia simples:
    // 1) Copiar os elementos para uma lista auxiliar resp.
    // 2) Ordenar por insercao ordenada conforme percorre L.
    // 3) Remover os menores ate restarem k elementos.

    // Passo 1 e 2: inserir todos ordenadamente crescente
    No *n = L->inicio;
    while (n)
    {
        insereOrdenadoCrescente(&resp, n->dado);
        n = n->prox;
    }

    // Passo 3: remover do inicio ate tamanho == k
    while (resp.tamanho > k)
    {
        No *rem = resp.inicio;
        resp.inicio = rem->prox;
        if (resp.inicio)
            resp.inicio->ant = nullptr;
        else
            resp.fim = nullptr;
        delete rem;
        resp.tamanho--;
    }

    return resp;
}

#endif

