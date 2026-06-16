#include <iostream>

#include "../..//lista duplamente encadeada/lista_dupla.hpp"

using namespace std;

// O que o exercicio exige:
// Criar uma funcao equivalente a insereInicioL para lista duplamente encadeada,
// preenchendo as lacunas do enunciado.
//
// O que ele testa de conhecimento nessa atividade:
// Entendimento dos ponteiros prox/ant em uma lista duplamente encadeada.
//
// Como o codigo esta executando:
// - Cria um novo no.
// - Ajusta novo->ant e novo->prox.
// - Atualiza fim quando a lista estiver vazia.
// - Atualiza o ant do antigo inicio.
// - Atualiza inicio e tamanho.

static bool insereInicioL_lacunas(Lista *lista, int valor)
{
    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;

    // Lacunas:
    novo->ant = nullptr;
    novo->prox = lista->inicio;

    if (lista->fim == nullptr) // lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return true;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista l;
    cout << "#1 - insercao no inicio (lista duplamente encadeada)\n";

    insereInicioL_lacunas(&l, 10);
    insereInicioL_lacunas(&l, 20);
    insereInicioL_lacunas(&l, 30);

    cout << "Lista no sentido direto: ";
    mostraL(&l);
    cout << "Lista no sentido inverso: ";
    mostrarInversoL(&l);

    destroiL(&l);
    return EXIT_SUCCESS;
}

