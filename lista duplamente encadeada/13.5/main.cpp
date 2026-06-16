#include <iostream>
using namespace std;

#include "estrutura.hpp"

// Exercicio 13.5:
// Desenvolver uma funcao inverterNFim(Lista* l, int n) que inverta a ordem dos N ultimos
// elementos de uma lista duplamente encadeada com descritor.
//
// Este exercicio testa:
// - Uso de ponteiros fim/ant para localizar o bloco a inverter.
// - Atualizacao de conteudos dos nos para produzir o efeito de reversao.
//
// Como a solucao foi implementada:
// - Se n > tamanho, aborta.
// - Copia-se os valores dos N ultimos para um vetor.
// - Em seguida escreve-se de volta invertendo a ordem dentro do bloco N.
//
// Funcionamento passo a passo:
// 1) Montar a lista.
// 2) Mostrar.
// 3) Chamar inverterNFim.
// 4) Mostrar a lista direta e inversa.

int main(void)
{
    Lista lista;

    cout << "\n#TESTE 1\n";
    insereInicioL(&lista, 9);
    insereInicioL(&lista, 8);
    insereInicioL(&lista, 7);
    insereInicioL(&lista, 6);
    insereInicioL(&lista, 5);
    insereInicioL(&lista, 4);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 2);
    insereInicioL(&lista, 1);
    mostraL(&lista);

    inverterNFim(&lista, 4);
    mostraL(&lista);
    mostrarInversoL(&lista);

    destroiL(&lista);

    cout << "\n#TESTE 2\n";
    insereInicioL(&lista, 90);
    insereInicioL(&lista, 80);
    insereInicioL(&lista, 70);
    insereInicioL(&lista, 60);
    insereInicioL(&lista, 50);
    insereInicioL(&lista, 40);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 10);
    mostraL(&lista);

    inverterNFim(&lista, lista.tamanho);
    mostraL(&lista);
    mostrarInversoL(&lista);

    destroiL(&lista);
    return EXIT_SUCCESS;
}

