#include <iostream>

#include "../..//lista duplamente encadeada/lista_dupla.hpp"

using namespace std;

// O que o exercicio exige:
// Inserir dois novos nos (valorNovoNo em cada um) antes e depois de cada ocorrencia
// de valorBusca na lista duplamente encadeada.
//
// O que ele testa de conhecimento nessa atividade:
// Manipulacao de ponteiros prox e ant e cuidado ao inserir enquanto percorre a lista.
//
// Como o codigo esta executando:
// - Percorre a lista a partir do inicio.
// - Quando encontra um valorBusca, cria um no antes e um no depois.
// - Atualiza as ligacoes do antes e do depois.
// - Move a iteracao para o proximo no original (apos o bloco inserido).

void inserirAntesDepois(Lista *l, int valorBusca, int valorNovoNo)
{
    if (l == nullptr)
        return;

    No *atual = l->inicio;

    while (atual != nullptr)
    {
        if (atual->dado == valorBusca)
        {
            No *antOriginal = atual->ant;
            No *proxOriginal = atual->prox;

            // Cria no antes
            No *novoAntes = new No();
            novoAntes->dado = valorNovoNo;

            novoAntes->ant = antOriginal;
            novoAntes->prox = atual;

            if (antOriginal != nullptr)
                antOriginal->prox = novoAntes;
            else
                l->inicio = novoAntes;

            atual->ant = novoAntes;

            // Cria no depois
            No *novoDepois = new No();
            novoDepois->dado = valorNovoNo;

            novoDepois->ant = atual;
            novoDepois->prox = proxOriginal;

            atual->prox = novoDepois;

            if (proxOriginal != nullptr)
                proxOriginal->ant = novoDepois;
            else
                l->fim = novoDepois;

            l->tamanho += 2;

            // Proximo: devemos continuar a busca depois do valor original.
            atual = novoDepois->prox;
        }
        else
        {
            atual = atual->prox;
        }
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista l;
    insereInicioL(&l, 9);
    insereInicioL(&l, 7);
    insereInicioL(&l, 8);
    insereInicioL(&l, 7);
    insereInicioL(&l, 6);

    cout << "Lista inicial (sentido direto): ";
    mostraL(&l);
    cout << "Lista inicial (sentido inverso): ";
    mostrarInversoL(&l);

    cout << "\n#1\n";
    inserirAntesDepois(&l, 7, 100);
    mostraL(&l);
    mostrarInversoL(&l);

    cout << "\n#2\n";
    inserirAntesDepois(&l, 6, 200);
    mostraL(&l);
    mostrarInversoL(&l);

    cout << "\n#3\n";
    inserirAntesDepois(&l, 9, 300);
    mostraL(&l);
    mostrarInversoL(&l);

    cout << "\n#4\n";
    inserirAntesDepois(&l, 7, 7);
    mostraL(&l);
    mostrarInversoL(&l);

    cout << "\n#5\n";
    inserirAntesDepois(&l, 7, 7);
    mostraL(&l);
    mostrarInversoL(&l);

    destroiL(&l);
    return EXIT_SUCCESS;
}

