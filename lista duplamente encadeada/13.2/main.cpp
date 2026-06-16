#include <iostream>
using namespace std;

#include "estrutura.hpp"

// Exercicio 13.2:
// Criar a funcao RemoveFim para remover o ultimo elemento da lista duplamente encadeada.
//
// Este exercicio testa o conhecimento sobre:
// - Remocao do ultimo nó usando somente fim e ant.
// - Atualizacao dos ponteiros fim e inicio sem percorrer a lista.
//
// Como a solucao foi implementada:
// - Se a lista tiver apenas 1 elemento, inicio e fim viram nullptr.
// - Caso contrario, usa-se ultimo->ant para obter o penultimo.
//   Atualiza-se ant->prox = nullptr e fim passa a ser ant.
//
// Funcionamento passo a passo:
// 1) Inserir alguns valores no inicio para formar a lista.
// 2) Mostrar a lista.
// 3) Chamar RemoveFim e mostrar novamente.

int main(void)
{
    Lista l;

    cout << "\n#TESTE 1\n";
    insereInicioL(&l, 10);
    insereInicioL(&l, 20);
    insereInicioL(&l, 30);

    mostraL(&l, "l normal   :");
    mostrarInversoL(&l, "l invertida:");

    cout << "\nChamando RemoveFim...\n";
    RemoveFim(&l);

    mostraL(&l, "l normal   :");
    mostrarInversoL(&l, "l invertida:");

    destroiL(&l);
    return EXIT_SUCCESS;
}

