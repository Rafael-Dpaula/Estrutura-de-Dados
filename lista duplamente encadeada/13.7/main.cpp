#include <iostream>
using namespace std;

#include "estrutura.hpp"

// Exercicio 13.7:
// Concatenar listas duplamente encadeadas com descritores L1, L2 e L3 armazenando inteiros.
// Prot. void concatenarListas(Lista *l1, Lista *l2, Lista *l3)
//
// Este exercicio testa:
// - Conexao correta de ponteiros prox/ant entre listas.
// - Atualizacao consistente dos descritores (inicio, fim, tamanho).
// - Respeitar restricoes: sem estruturas auxiliares e sem lacos de repeticao.
//
// Como a solucao foi implementada:
// - Se L1 ou L2 estiver vazia, nao faz nada.
// - Caso contrario:
//   * L3 aponta para l1->inicio e l2->fim
//   * conecta l1->fim->prox em l2->inicio e vice-versa via ant
//   * soma os tamanhos em L3
//   * torna L1 e L2 vazias (ponteiros nulos e tamanho 0)
//
// Funcionamento passo a passo:
// 1) Montar l1 e l2.
// 2) Mostrar l1, l2 e l3 antes.
// 3) Chamar concatenarListas.
// 4) Mostrar l1, l2 e l3 depois.

int main(void)
{
    Lista l1;
    Lista l2;
    Lista l3;

    cout << "\n\n###TESTE 1\n";
    insereInicioL(&l1, 5);
    insereInicioL(&l1, 7);
    insereInicioL(&l1, 3);
    insereInicioL(&l1, 1);
    insereInicioL(&l1, 9);

    insereInicioL(&l2, 5);
    insereInicioL(&l2, 4);
    insereInicioL(&l2, 11);

    mostraL(&l1, "l1 normal   :");
    mostrarInversoL(&l1, "l1 invertida:");
    mostraL(&l2, "l2 normal   :");
    mostrarInversoL(&l2, "l2 invertida:");
    mostraL(&l3, "l3 normal   :");
    mostrarInversoL(&l3, "l3 invertida:");
    cout << "Tamanho da lista 3: " << l3.tamanho << endl;

    cout << "\n\n###TESTE 2\n";
    concatenarListas(&l1, &l2, &l3);
    mostraL(&l1, "l1 normal   :");
    mostrarInversoL(&l1, "l1 invertida:");
    mostraL(&l2, "l2 normal   :");
    mostrarInversoL(&l2, "l2 invertida:");
    mostraL(&l3, "l3 normal   :");
    mostrarInversoL(&l3, "l3 invertida:");
    cout << "Tamanho da lista 3: " << l3.tamanho << endl;

    destroiL(&l3);
    return EXIT_SUCCESS;
}

