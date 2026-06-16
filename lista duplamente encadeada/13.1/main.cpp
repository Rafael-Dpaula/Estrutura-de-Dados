#include <iostream>
using namespace std;

#include "estrutura.hpp"

// Exercicio 13.1:
// Implementar operacoes em uma lista duplamente encadeada:
// 1) Inserir no final da lista.
// 2) Remover o primeiro elemento.
// 3) Remover o ultimo elemento.
//
// Este exercicio testa o conhecimento sobre:
// - Operacoes basicas em lista duplamente encadeada usando descritor.
// - Atualizacao correta dos ponteiros inicio, fim, ant e prox.
// - Remocao sem percorrer (para achar o penultimo usa-se o ant).
//
// Como a solucao foi implementada:
// - A estrutura auxiliar nao e necessaria.
// - A insercao no final usa o ponteiro fim do descritor.
// - A remocao do primeiro usa o ponteiro inicio do descritor.
// - A remocao do ultimo usa o ponteiro fim e o ant do ultimo.
//
// Funcionamento passo a passo:
// 1) Cria uma lista vazia.
// 2) Insere alguns valores no final usando insereFimL.
// 3) Mostra a lista na ordem normal e inversa.
// 4) Remove o primeiro valor usando removeInicioL e mostra novamente.
// 5) Remove o ultimo valor usando removeFimL e mostra novamente.

int main(void)
{
    Lista l;

    cout << "\n#TESTE 1\n";
    insereFimL(&l, 1);
    insereFimL(&l, 2);
    insereFimL(&l, 3);
    insereFimL(&l, 4);
    insereFimL(&l, 5);

    mostraL(&l, "l normal   :");
    mostrarInversoL(&l, "l invertida:");

    cout << "\nRemovendo primeiro...\n";
    removeInicioL(&l);
    mostraL(&l, "l normal   :");
    mostrarInversoL(&l, "l invertida:");

    cout << "\nRemovendo ultimo...\n";
    removeFimL(&l);
    mostraL(&l, "l normal   :");
    mostrarInversoL(&l, "l invertida:");

    destroiL(&l);
    return EXIT_SUCCESS;
}

