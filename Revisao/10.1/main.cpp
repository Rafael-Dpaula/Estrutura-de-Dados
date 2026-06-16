#include <iostream>

#include "../..//lista encadeada/exemplo-lista-encadeada/lista.hpp"

using namespace std;

// O que o exercicio exige:
// Encontrar o menor e o maior valor em uma lista simplesmente encadeada
// e trocar esses valores entre si.
//
// O que ele testa de conhecimento nessa atividade:
// Percorrer a lista, identificar minimo e maximo e realizar a troca.
//
// Como o codigo esta executando:
// - Percorre todos os nos procurando menor e maior.
// - Se a lista tiver 0 ou 1 elementos, nao faz nada.
// - Caso contrario, troca os valores dos nodos identificados.

void trocarMenorMaior(No **lista)
{
    if (lista == nullptr || *lista == nullptr || (*lista)->prox == nullptr)
        return;

    No *menorNo = *lista;
    No *maiorNo = *lista;

    No *n = *lista;
    while (n != nullptr)
    {
        if (n->dado < menorNo->dado)
            menorNo = n;
        if (n->dado > maiorNo->dado)
            maiorNo = n;
        n = n->prox;
    }

    int aux = menorNo->dado;
    menorNo->dado = maiorNo->dado;
    maiorNo->dado = aux;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *lista;
    inicializaL(&lista);

    insereInicioL(&lista, -100);
    insereInicioL(&lista, -20);
    insereInicioL(&lista, -30);
    insereInicioL(&lista, -110);
    insereInicioL(&lista, -40);

    cout << "Antes da troca\n";
    mostraL(&lista);

    trocarMenorMaior(&lista);

    cout << "\nDepois da troca\n";
    mostraL(&lista);

    destroiL(&lista);
    return EXIT_SUCCESS;
}

