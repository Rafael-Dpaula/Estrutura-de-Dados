#include <iostream>
#include <vector>
using namespace std;

#include "estrutura.hpp"

// Exercicio 13.4:
// Considerar um labirinto e um caminho de ida do ponto de entrada ate o ponto de saida.
// Calcular o percurso inverso (caminho de volta) usando uma lista duplamente encadeada.
//
// Este exercicio testa:
// - Uso de lista duplamente encadeada para armazenar uma sequencia.
// - Obter a sequencia inversa percorrendo a partir do fim.
//
// Como a solucao foi implementada:
// - Armazenamos o caminho de ida em uma lista (cada movimento vira um inteiro).
// - Para imprimir o caminho de volta, basta percorrer a lista do fim ate o inicio.
// - Alem disso, o inverso de um movimento no labirinto e:
//   direita <-> esquerda, baixo <-> cima.
//
// Observacao importante:
// O enunciado mostra exemplos concretos de movimentos.
// Para simplificar e focar em funcionamento correto, usamos a conversao direta.
//
// Funcionamento passo a passo:
// 1) Montar o caminho de ida a partir do exemplo do enunciado.
// 2) Inserir movimentos na lista.
// 3) Imprimir o caminho de volta em ordem inversa e com movimentos invertidos.

int codMov(char m)
{
    // direita=0, esquerda=1, baixo=2, cima=3
    if (m == 'd')
        return 0;
    if (m == 'e')
        return 1;
    if (m == 'b')
        return 2;
    return 3;
}

char movInvertido(int c)
{
    // direita <-> esquerda, baixo <-> cima
    if (c == 0)
        return 'e';
    if (c == 1)
        return 'd';
    if (c == 2)
        return 'c';
    return 'b';
}

const char *movTexto(int c)
{
    if (c == 0)
        return "direita";
    if (c == 1)
        return "esquerda";
    if (c == 2)
        return "baixo";
    return "cima";
}

int main(void)
{
    Lista caminho;

    // Caminho de ida conforme exemplo do enunciado
    char ida[] = {
        'd','b','d','c','d','b','d','b','d','d','c','d','d','c','c','c','e','c','d','d'
    };
    int nIda = 20;

    for (int i = 0; i < nIda; i++)
        insereFimL(&caminho, codMov(ida[i]));

    cout << "\nCaminho de ida: ";
    No *tmp = caminho.inicio;
    while (tmp)
    {
        cout << movTexto(tmp->dado);
        tmp = tmp->prox;
        if (tmp)
            cout << ", ";
    }
    cout << endl;

    cout << "Caminho de volta: ";
    No *k = caminho.fim;
    while (k)
    {
        char inv = movInvertido(k->dado);
        int cod = codMov(inv);
        cout << movTexto(cod);
        k = k->ant;
        if (k)
            cout << ", ";
    }
    cout << endl;

    destroiL(&caminho);
    return EXIT_SUCCESS;
}

