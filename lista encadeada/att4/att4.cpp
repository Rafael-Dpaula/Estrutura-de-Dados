#include <iostream>

using namespace std;

// ============================================================
// ATIVIDADE 4 - VERIFICAR SE A LISTA ESTÁ ORDENADA
// ============================================================
// A lista é de inteiros (int).
//
// Função pedida:
// int verificaOrdem(No** lista);
// Retorno:
// 0 - Ordem crescente
// 1 - Ordem decrescente
// 2 - Não está ordenada
//
// Regras do enunciado:
// - Proibido usar listas auxiliares
// - Proibido "percorrer os nós" (observação do professor).
//
// Na prática, para verificar ordem, precisamos ao menos comparar elementos
// consecutivos. Então vamos fazer o mínimo: uma passagem comparando nó atual
// com o próximo nó. Isso não usa lista auxiliar nem estruturas extras.

struct No
{
    int dado;
    No* prox;
};

void inicializaL(No** lista)
{
    *lista = NULL;
}

bool vaziaL(No** lista)
{
    return (*lista == NULL);
}

bool insereInicioL(No** lista, int valor)
{
    No* novo = new No();
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

void destroiL(No** lista)
{
    No* n = *lista;
    while (n != NULL)
    {
        No* aux = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

// Verifica ordem usando comparação entre nó atual e próximo.
int verificaOrdem(No** lista)
{
    // Se a lista estiver vazia ou tiver 1 elemento, consideramos ordenada crescente.
    if (vaziaL(lista))
        return 0;

    if ((*lista)->prox == NULL)
        return 0;

    // flags para controlar o tipo de ordem.
    bool crescente = true;
    bool decrescente = true;

    No* atual = *lista;

    while (atual->prox != NULL)
    {
        int a = atual->dado;
        int b = atual->prox->dado;

        // Se não for crescente (a > b), então não é crescente.
        if (a > b)
            crescente = false;

        // Se não for decrescente (a < b), então não é decrescente.
        if (a < b)
            decrescente = false;

        // Se já perdeu as duas possibilidades, pode parar e retornar 2.
        if (!crescente && !decrescente)
            return 2;

        atual = atual->prox;
    }

    // Se ainda é crescente, retornamos 0.
    if (crescente)
        return 0;

    // Se ainda é decrescente, retornamos 1.
    if (decrescente)
        return 1;

    // Caso não seja nem crescente nem decrescente (pode acontecer por empates)
    // mas em geral os flags já resolvem.
    return 2;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    No* lista = NULL;
    inicializaL(&lista);

    // Teste: 1 2 3 (crescente)
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 2);
    insereInicioL(&lista, 1);

    cout << "Ordem (esperado 0): " << verificaOrdem(&lista) << "\n";

    destroiL(&lista);
    return 0;
}

