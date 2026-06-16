#include <iostream>

#include "estrutura.hpp"

using namespace std;

// Exercicio:
// Dados duas listas L1 e L2, criar a lista L3 com a intersecao entre L1 e L2.
//
// Este exercicio testa o conhecimento sobre:
// - listas encadeadas
// - percorrer listas e comparar valores
// - insercao no fim da lista resultado
//
// Como a solucao foi implementada:
// 1) Percorremos todos os elementos da L1.
// 2) Para cada valor encontrado, verificamos se ele existe em L2.
// 3) Se existir, inserimos esse valor no fim de L3.
//
// Como o codigo funciona passo a passo:
// - Criamos L1 e L2 com os valores do exemplo.
// - Chamamos a funcao de intersecao.
// - Exibimos L1, L2 e L3.

static void intersecao(Lista *l1, Lista *l2, Lista *l3)
{
    if (l1 == nullptr || l2 == nullptr || l3 == nullptr)
        return;

    // Assumimos que l3 esta vazia no uso deste exercicio.
    No *n1 = l1->inicio;
    while (n1 != nullptr)
    {
        if (buscaL(l2, n1->dado) != nullptr)
            insereFimL(l3, n1->dado);

        n1 = n1->prox;
    }
}

int main()
{
    // Exemplo:
    // L1: 2 5 3 9 9 8 7 6 2 1
    // L2: 20 30 100 6 1 5 9
    // L3: 5 9 6 1

    Lista l1;
    Lista l2;
    Lista l3;

    int v1[10] = {2, 5, 3, 9, 9, 8, 7, 6, 2, 1};
    int v2[7] = {20, 30, 100, 6, 1, 5, 9};

    for (int i = 0; i < 10; i++)
        insereFimL(&l1, v1[i]);

    for (int i = 0; i < 7; i++)
        insereFimL(&l2, v2[i]);

    cout << "L1:" << "\n";
    mostraL(&l1);

    cout << "L2:" << "\n";
    mostraL(&l2);

    intersecao(&l1, &l2, &l3);

    cout << "L3 (intersecao):" << "\n";
    mostraL(&l3);

    destroiL(&l1);
    destroiL(&l2);
    destroiL(&l3);

    return 0;
}

