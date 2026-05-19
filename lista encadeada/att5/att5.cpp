#include <iostream>

using namespace std;

// ============================================================
// ATIVIDADE 5 - ORDENAR LISTA SIMPLEMENTE ENCADEADA
// ============================================================
// Função pedida:
// void ordenarL(No** lista);
//
// Regras:
// - Proibido usar listas auxiliares.
// - Proibido percorrer os nós (observação do enunciado).
//   Na prática, para ordenar uma lista encadeada, precisamos ao menos comparar
//   nós atuais e próximos; então vamos fazer uma ordenação por trocas
//   de valores do nó atual e do próximo.
// - A lista não pode estar vazia.
//
// Estratégia:
// - Usar um "bubble sort" sem lista auxiliar.
// - Percorremos a lista repetidas vezes.
// - A cada passo comparamos nó atual e próximo.
// - Se estiver fora de ordem crescente, trocamos os valores.
// - Paramos quando uma passada inteira não fizer nenhuma troca.

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

void mostraL(No** lista)
{
    No* n = *lista;
    cout << "L:{";
    while (n != NULL)
    {
        cout << n->dado;
        n = n->prox;
        if (n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

void ordenarL(No** lista)
{
    // Como o enunciado diz que a lista não pode estar vazia,
    // aqui só garantimos que não vamos acessar ponteiro nulo.
    if (vaziaL(lista))
        return;

    bool houveTroca = true;

    // Enquanto houver troca, ainda não está ordenada.
    while (houveTroca)
    {
        houveTroca = false;

        // Percorremos os nós comparando com o próximo.
        No* atual = *lista;
        while (atual != NULL && atual->prox != NULL)
        {
            // Queremos ordem crescente.
            if (atual->dado > atual->prox->dado)
            {
                // Trocamos os valores dos nós.
                int temp = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = temp;

                // Marcamos que houve troca nessa passada.
                houveTroca = true;
            }

            // Vamos para o próximo nó.
            atual = atual->prox;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    No* lista = NULL;
    inicializaL(&lista);

    // Teste: 5 1 4 2 8
    insereInicioL(&lista, 8);
    insereInicioL(&lista, 2);
    insereInicioL(&lista, 4);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);

    cout << "Lista antes de ordenar:\n";
    mostraL(&lista);

    ordenarL(&lista);

    cout << "Lista depois de ordenar (crescente):\n";
    mostraL(&lista);

    destroiL(&lista);
    return 0;
}

