#include <iostream>

#include "../..//lista duplamente encadeada/lista_dupla.hpp"

using namespace std;

// O que o exercicio exige:
// Excluir o no cujo valor e 23 de uma lista duplamente encadeada L1.
//
// O que ele testa de conhecimento nessa atividade:
// Atualizacao correta dos ponteiros inicio/fim e prox/ant apos exclusao.
//
// Como o codigo esta executando:
// - Constroi manualmente uma lista com 4 nos e ponteiros coerentes (como no enunciado).
// - Remove o no com dado=23 usando a funcao de busca + remover.
// - Exibe inicio, fim e tamanho apos a remocao.

static No* criaNo(int dado)
{
    No *n = new No();
    n->dado = dado;
    return n;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista l;

    // No enderecos sao apenas ilustrativos no enunciado; no programa, usaremos enderecos reais.
    No *n1 = criaNo(4);
    No *n2 = criaNo(10);
    No *n3 = criaNo(23);
    No *n4 = criaNo(30);

    // Ligacoes (duplamente encadeada)
    n1->ant = nullptr;
    n1->prox = n2;

    n2->ant = n1;
    n2->prox = n3;

    n3->ant = n2;
    n3->prox = n4;

    n4->ant = n3;
    n4->prox = nullptr;

    l.inicio = n1;
    l.fim = n4;
    l.tamanho = 4;

    cout << "#7 - remocao do no com valor 23\n";
    cout << "Antes: inicio=" << l.inicio << " fim=" << l.fim << " tamanho=" << l.tamanho << "\n";

    // Excluir o no com dado 23
    No *alvo = buscaL(&l, 23);
    if (alvo != nullptr)
        removerNoL(&l, alvo);

    cout << "Depois: inicio=" << l.inicio << " fim=" << l.fim << " tamanho=" << l.tamanho << "\n";

    // Como remove ja liberou o no 23, precisamos apenas destruir o resto.
    // destroiL percorre via prox.
    destroiL(&l);

    return EXIT_SUCCESS;
}

