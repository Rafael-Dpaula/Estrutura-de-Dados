#include <iostream>
using namespace std;
#include "pilha.hpp"


/**
 * att4.1 - Lista 4 exercício 1: Média aritmética dos valores na pilha dinamica.
 * Percorre usando topo->prox (sem desempilhar), soma/cont.
 * main: exemplo empilha valores fixos, mostra, print media.
 */
float media(Pilha *p)
{
    // Se pilha vazia, retorna 0
    if (vaziaP(p))
        return 0.0f;
    
    // Variaveis para calcular soma e contar elementos
    float soma = 0.0f;
    int cont = 0;
    
    // Começa do topo e vai até NULL percorrendo prox
    NoPilha *noAtual = p->topo;
    while (noAtual != NULL)
    {
        soma += noAtual->dado; // Soma o dado atual
        cont++; // Incrementa contador de elementos
        noAtual = noAtual->prox; // Vai para próximo nó
    }
    
    // Retorna média (soma dividida pelo número de elementos)
    return soma / cont;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p;

    empilhaP(&p, 12);
    empilhaP(&p, 21);
    empilhaP(&p, 44);
    empilhaP(&p, 19);
    empilhaP(&p, 3);

    mostraP(&p, "pilha");

    cout << "Media: " << media(&p) << endl;

    return EXIT_SUCCESS;

} // final do main
