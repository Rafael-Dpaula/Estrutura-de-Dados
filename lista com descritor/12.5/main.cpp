#include <iostream>

#include "estrutura.hpp"

using namespace std;

// Exercicio:
// Inserir de forma ordenada um valor em uma lista encadeada.
//
// Protocolo:
// void insereOrdenado(Lista* lista, int valor);
//
// Observacao:
// - Lista inicialmente vazia (mas a solucao contempla caso nao vazia).
// - E proibido o uso de listas auxiliares e ajustar ponteiros de forma indireta.
//   A abordagem e inserir o novo no ponto correto percorrendo os nos.
//
// Este exercicio testa o conhecimento sobre:
// - insercao ordenada em lista encadeada
// - manutencao de inicio/fim/tamanho
//
// Como a solucao foi implementada:
// 1) Se a lista estiver vazia, inserimos no inicio.
// 2) Se o valor deve ficar no inicio (<= inicio->dado), inserimos no inicio.
// 3) Caso contrario, percorremos usando dois ponteiros:
//    - anterior aponta para o no anterior ao ponto de insercao
//    - atual aponta para o no atual
// 4) Inserimos o novo no entre anterior e atual (ou no fim se atual for null).
//
// Como o codigo funciona passo a passo:
// - Criamos uma lista e inserimos varios valores chamando insereOrdenado.
// - Exibimos a lista ao final.

void insereOrdenado(Lista *lista, int valor)
{
    if (lista == nullptr)
        return;

    if (vaziaL(lista))
    {
        insereInicioL(lista, valor);
        return;
    }

    if (valor <= lista->inicio->dado)
    {
        insereInicioL(lista, valor);
        return;
    }

    No *anterior = lista->inicio;
    No *atual = lista->inicio->prox;

    while (atual != nullptr && valor > atual->dado)
    {
        anterior = atual;
        atual = atual->prox;
    }

    No *novo = new No();
    novo->dado = valor;
    novo->prox = atual;

    anterior->prox = novo;

    if (atual == nullptr)
        lista->fim = novo;

    lista->tamanho++;
}

int main()
{
    Lista l;

    int valores[7] = {5, 3, 9, 1, 4, 7, 2};

    cout << "Inserindo valores e mantendo a lista ordenada:" << "\n";
    for (int i = 0; i < 7; i++)
    {
        cout << "Inserir: " << valores[i] << "\n";
        insereOrdenado(&l, valores[i]);
        mostraL(&l);
    }

    destroiL(&l);
    return 0;
}

