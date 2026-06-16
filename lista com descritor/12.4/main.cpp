#include <iostream>

#include "estrutura.hpp"

using namespace std;

// Exercicio:
// Recebe uma lista L e um valor X.
// Retirar os primeiros X valores da lista L e inserir esses valores no fim de L.
//
// Este exercicio testa o conhecimento sobre:
// - remover do inicio (por vez) e inserir no fim
// - manutencao de descritores (inicio, fim e tamanho)
// - casos especiais (lista vazia e X maior/igual ao tamanho)
//
// Como a solucao foi implementada:
// 1) Repetimos X vezes (ou ate a lista ficar vazia):
//    - guardamos o valor do inicio
//    - removemos o primeiro no
//    - inserimos esse valor no fim
// 2) Dessa forma, os X primeiros elementos “giraram” para o final.
//
// Como o codigo funciona passo a passo:
// - Criamos a lista L do exemplo.
// - Chamamos retirarPrimeirosXInserirFim(L, X).
// - Exibimos antes e depois.

static bool removerInicioEObterValor(Lista *lista, int &valor)
{
    if (lista == nullptr || lista->inicio == nullptr)
        return false;

    No *remover = lista->inicio;
    valor = remover->dado;
    lista->inicio = remover->prox;

    if (lista->inicio == nullptr)
        lista->fim = nullptr;

    delete remover;
    lista->tamanho--;
    return true;
}

static void retirarPrimeirosXInserirFim(Lista *lista, int X)
{
    if (lista == nullptr)
        return;

    if (X <= 0)
        return;

    for (int i = 0; i < X; i++)
    {
        if (lista->inicio == nullptr)
            break;

        int valor;
        bool ok = removerInicioEObterValor(lista, valor);
        if (!ok)
            break;

        insereFimL(lista, valor);
    }
}

int main()
{
    // Exemplo:
    // L: [3,5,8,9,12,11,7,10]
    // x: 4
    // L apos: [12,11,7,10,3,5,8,9]

    Lista l;
    int v[8] = {3, 5, 8, 9, 12, 11, 7, 10};

    for (int i = 0; i < 8; i++)
        insereFimL(&l, v[i]);

    cout << "L inicial:" << "\n";
    mostraL(&l);

    int X = 4;
    retirarPrimeirosXInserirFim(&l, X);

    cout << "L apos retirar primeiros " << X << " valores e inserir no fim:" << "\n";
    mostraL(&l);

    destroiL(&l);
    return 0;
}

