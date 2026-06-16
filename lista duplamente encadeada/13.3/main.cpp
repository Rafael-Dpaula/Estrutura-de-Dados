#include <iostream>
using namespace std;

#include "estrutura.hpp"

// Exercicio 13.3:
// 1) removeTodos(L, valor): remover todas as ocorrencias do valor em L.
// 2) leMaiores(L, K): retornar uma nova lista ordenada com os K maiores elementos de L.
//    Se K > tamanho de L, a lista retornada deve conter todos os elementos de L ordenados.
//
// Este exercicio testa:
// - Remocao de nos durante a travessia.
// - Criacao de lista nova e manutencao de ordem.
//
// Como a solucao foi implementada:
// - removeTodos percorre com ponteiro n e guarda prox antes de remover.
// - leMaiores:
//   a) Insere todos os valores em ordem crescente na lista resp.
//   b) Remove do inicio os menores ate ficarem exatamente k elementos.
//
// Funcionamento passo a passo:
// 1) Monta uma lista L com valores.
// 2) Aplica removeTodos.
// 3) Chama leMaiores com K escolhido.
// 4) Mostra as listas resultantes.

int main(void)
{
    Lista L;

    cout << "\n#TESTE 1\n";
    insereInicioL(&L, 5);
    insereInicioL(&L, 1);
    insereInicioL(&L, 7);
    insereInicioL(&L, 5);
    insereInicioL(&L, 3);
    insereInicioL(&L, 9);

    mostraL(&L, "L normal   :");
    mostrarInversoL(&L, "L invertida:");

    cout << "\nRemovendo todos os valores 5...\n";
    removeTodos(&L, 5);

    mostraL(&L, "L normal   :");
    mostrarInversoL(&L, "L invertida:");

    cout << "\nSelecionando K=3 maiores (ordenado)...\n";
    Lista resp = leMaiores(&L, 3);

    mostraL(&resp, "resp normal   :");
    mostrarInversoL(&resp, "resp invertida:");

    destroiL(&L);
    destroiL(&resp);
    return EXIT_SUCCESS;
}

