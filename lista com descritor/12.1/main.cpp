#include <iostream>

#include "estrutura.hpp"

using namespace std;

// Exercicio:
// Inserir e remover elementos em uma lista encadeada com descritor
// (usando diretamente ponteiro para No, atraves de No **lista).
//
// Este exercicio testa o conhecimento sobre:
// - operacoes basicas em listas encadeadas (insercao/remoção no inicio e fim)
// - atualizacao de ponteiros de inicio/fim e contador de tamanho
// - tratamento de casos especiais (lista vazia, lista com 1 elemento,
//   remocao no inicio e no fim).
//
// Como a solucao foi implementada:
// 1) Para cada operacao, a lista e acessada via No**.
// 2) A cada insercao/remocao, calculamos inicio e fim varrendo a lista
//    para garantir que os descritores estejam consistentes.
// 3) Entao imprimimos inicio, fim e tamanho.
//
// Como o codigo funciona passo a passo:
// - Criamos uma lista inicial a partir de valores.
// - Aplicamos as funcoes pedidas em sequencia.
// - Apos cada chamada, as funcoes atualizam a estrutura e imprimem
//   os descritores consistentes.

// insere "valor" apos a primeira ocorrencia de um valor par na lista
void insereAposPrimeiroPar(No **lista, int valor)
{
    if (lista == nullptr || *lista == nullptr)
    {
        // Se a lista e vazia, nao existe "primeiro par" para inserir apos.
        return;
    }

    No *atual = *lista;
    while (atual != nullptr)
    {
        if (atual->dado % 2 == 0)
        {
            No *novo = new No();
            novo->dado = valor;
            novo->prox = atual->prox;
            atual->prox = novo;
            break;
        }
        atual = atual->prox;
    }
}

// insere "valor" antes da primeira ocorrencia de um valor par na lista
void insereAntesPrimeiroPar(No **lista, int valor)
{
    if (lista == nullptr || *lista == nullptr)
        return;

    No *anterior = nullptr;
    No *atual = *lista;

    while (atual != nullptr)
    {
        if (atual->dado % 2 == 0)
        {
            No *novo = new No();
            novo->dado = valor;

            if (anterior == nullptr)
            {
                novo->prox = *lista;
                *lista = novo;
            }
            else
            {
                novo->prox = atual;
                anterior->prox = novo;
            }
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

// retorna o valor do ultimo elemento da lista SEM removelo
int leFinalL(No **lista)
{
    if (lista == nullptr || *lista == nullptr)
        return 0;

    No *atual = *lista;
    while (atual->prox != nullptr)
        atual = atual->prox;

    return atual->dado;
}

// retorna o valor do ultimo elemento da lista e REMOVE o elemento
int removeFinalL(No **lista)
{
    if (lista == nullptr || *lista == nullptr)
        return 0;

    // Caso lista com 1 elemento
    if ((*lista)->prox == nullptr)
    {
        int valor = (*lista)->dado;
        delete *lista;
        *lista = nullptr;
        return valor;
    }

    No *anterior = nullptr;
    No *atual = *lista;

    while (atual->prox != nullptr)
    {
        anterior = atual;
        atual = atual->prox;
    }

    // atual e o ultimo
    int valor = atual->dado;
    anterior->prox = nullptr;
    delete atual;
    return valor;
}

// insere "valor" antes de CADA ocorrencia de um valor par na lista
void insereAposCadaPar(No **lista, int valor)
{
    // A questao pede "antes de cada ocorrencia" de um valor par.
    if (lista == nullptr || *lista == nullptr)
        return;

    No *atual = *lista;
    No *anterior = nullptr;

    while (atual != nullptr)
    {
        if (atual->dado % 2 == 0)
        {
            No *novo = new No();
            novo->dado = valor;
            novo->prox = atual;

            if (anterior == nullptr)
            {
                *lista = novo;
                anterior = novo;
            }
            else
            {
                anterior->prox = novo;
                anterior = novo;
            }

            // avancamos para o proximo apos o par atual
            anterior = atual;
            atual = atual->prox;
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

static void imprimeDescritores(No *inicio)
{
    int tamanho = 0;
    int fimValor = 0;

    No *n = inicio;
    No *fimPtr = nullptr;

    while (n != nullptr)
    {
        tamanho++;
        fimPtr = n;
        n = n->prox;
    }

    if (inicio == nullptr)
    {
        cout << "inicio: (vazio)" << "\n";
        cout << "fim: (vazio)" << "\n";
        cout << "tamanho: 0" << "\n";
        return;
    }

    fimValor = fimPtr->dado;
    cout << "inicio: " << inicio->dado << "\n";
    cout << "fim: " << fimValor << "\n";
    cout << "tamanho: " << tamanho << "\n";
}

int main()
{
    // Lista inicial: 2 5 3 9 9 8 7 6 2 1
    int valores[10] = {2, 5, 3, 9, 9, 8, 7, 6, 2, 1};

    No *lista = nullptr;
    No *fim = nullptr;

    for (int i = 0; i < 10; i++)
    {
        No *novo = new No();
        novo->dado = valores[i];
        novo->prox = nullptr;

        if (lista == nullptr)
        {
            lista = novo;
            fim = novo;
        }
        else
        {
            fim->prox = novo;
            fim = novo;
        }
    }


    No **p = &lista;

    cout << "Estado inicial:" << "\n";
    imprimeDescritores(lista);

    insereAposPrimeiroPar(p, 100);
    cout << "Depois de insereAposPrimeiroPar(100):" << "\n";
    imprimeDescritores(lista);

    insereAntesPrimeiroPar(p, 200);
    cout << "Depois de insereAntesPrimeiroPar(200):" << "\n";
    imprimeDescritores(lista);

    int ult = leFinalL(p);
    cout << "leFinalL: " << ult << "\n";
    cout << "Depois de leFinalL (sem remover):" << "\n";
    imprimeDescritores(lista);

    int rem = removeFinalL(p);
    cout << "removeFinalL (removido): " << rem << "\n";
    cout << "Depois de removeFinalL:" << "\n";
    imprimeDescritores(lista);

    insereAposCadaPar(p, 300);
    cout << "Depois de insereAposCadaPar(300):" << "\n";
    imprimeDescritores(lista);

    // Destroi manualmente (sem acentos/complexidade)
    No *n = lista;
    while (n != nullptr)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }

    return 0;
}


