#include <iostream>

#include "../..//lista duplamente encadeada/lista_dupla.hpp"

using namespace std;

// O que o exercicio exige:
// Inserir um elemento no final da lista duplamente encadeada preenchendo as lacunas.
//
// O que ele testa de conhecimento nessa atividade:
// Atualizacao correta dos ponteiros prox e ant e do descritor (inicio/fim/tamanho).
//
// Como o codigo esta executando:
// - Cria um novo no.
// - Se a lista estiver vazia, ajusta inicio e fim.
// - Caso contrario, liga fim->prox e ajusta novo->ant.
// - Atualiza fim e tamanho.

static bool insereFimL_lacunas(Lista *lista, int valor)
{
    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;

    // Lacuna I
    novo->prox = nullptr;

    // Lacuna II
    novo->ant = nullptr;

    if (lista->inicio == nullptr)
        lista->inicio = novo;
    else
        lista->fim->prox = novo; // Lacuna III

    if (lista->inicio != nullptr)
        novo->ant = lista->fim; // ajusta ant de acordo com a ligacao feita acima

    // Lacuna IV
    lista->fim = novo;

    lista->tamanho++;

    return true;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista l;

    cout << "#6 - insercao no final (lista duplamente encadeada)\n";

    insereFimL_lacunas(&l, 10);
    insereFimL_lacunas(&l, 20);
    insereFimL_lacunas(&l, 30);

    cout << "Sentido direto: ";
    mostraL(&l);
    cout << "Sentido inverso: ";
    mostrarInversoL(&l);

    destroiL(&l);
    return EXIT_SUCCESS;
}

