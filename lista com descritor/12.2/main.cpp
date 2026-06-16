#include <iostream>

#include "estrutura.hpp"

using namespace std;

// Exercicio:
// Inserir um valor em uma lista encadeada baseada em uma posicao/indice.
//
// Este exercicio testa o conhecimento sobre:
// - listas encadeadas com descritor (inicio, fim e tamanho)
// - insercao em posicoes especiais (insercao no inicio, no meio e no fim)
// - validacao de indice (posicao invalida)
//
// Como a solucao foi implementada:
// 1) Validamos o indice pos. Se pos < 0 ou pos > tamanho, retornamos false.
// 2) Se pos == 0, inserimos no inicio.
// 3) Se pos == tamanho, inserimos no fim.
// 4) Caso geral: percorremos ate o no que esta na posicao pos-1,
//    inserimos o novo no entre (pos-1) e (pos).
// 5) Atualizamos inicio/fim/tamanho.
//
// Como o codigo funciona passo a passo:
// - Criamos uma lista L1 a partir do exemplo do enunciado.
// - Chamamos inserePosicao com varios valores de posicao.
// - Imprimimos se a operacao retornou true/false e exibimos a lista.

bool inserePosicao(Lista *lista, int pos, int valor)
{
    if (lista == nullptr)
        return false;

    if (pos < 0 || pos > lista->tamanho)
        return false;

    if (pos == 0)
    {
        return insereInicioL(lista, valor);
    }

    if (pos == lista->tamanho)
    {
        return insereFimL(lista, valor);
    }

    // Insercao no meio: pos entre 1 e tamanho-1
    No *anterior = lista->inicio;
    for (int i = 0; i < pos - 1; i++)
        anterior = anterior->prox;

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = anterior->prox;
    anterior->prox = novo;

    lista->tamanho++;
    return true;
}

int main()
{
    // Exemplo L1: 2 5 3 9 9 8 7 6 2 1
    Lista l1;
    int valores[10] = {2, 5, 3, 9, 9, 8, 7, 6, 2, 1};

    for (int i = 0; i < 10; i++)
        insereFimL(&l1, valores[i]);

    cout << "L1 inicial:" << "\n";
    mostraL(&l1);

    bool r1 = inserePosicao(&l1, 0, 100);
    cout << "inserePosicao(L1, 0, 100) retorna: " << (r1 ? "true" : "false") << "\n";
    mostraL(&l1);

    bool r2 = inserePosicao(&l1, 3, 200);
    cout << "inserePosicao(L1, 3, 200) retorna: " << (r2 ? "true" : "false") << "\n";
    mostraL(&l1);

    bool r3 = inserePosicao(&l1, 11, 300);
    cout << "inserePosicao(L1, 11, 300) retorna: " << (r3 ? "true" : "false") << "\n";
    mostraL(&l1);

    bool r4 = inserePosicao(&l1, 13, 1000);
    cout << "inserePosicao(L1, 13, 1000) retorna: " << (r4 ? "true" : "false") << "\n";
    mostraL(&l1);

    bool r5 = inserePosicao(&l1, -1, 1000);
    cout << "inserePosicao(L1, -1, 1000) retorna: " << (r5 ? "true" : "false") << "\n";
    mostraL(&l1);

    destroiL(&l1);
    return 0;
}

