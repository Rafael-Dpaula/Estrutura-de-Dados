#include <iostream>

using namespace std;

// ============================================================
// ATIVIDADE 6 - INSERIR EM LISTA ENCADEADA POR POSIÇÃO/ÍNDICE
// ============================================================
// Função pedida:
// bool inserePosicao(No** lista, int pos, int valor);
//
// Regras do enunciado:
// - É proibido o uso de listas auxiliares.
// - Se pos for inválido, retorna false.
// - Se pos for 0, insere no começo.
// - Exemplo no PDF mostra uma lista L1: 2 5 3 9 9 8 7 6 2 1 (tamanho 11)
//   e as operações:
//   pos=0  -> true
//   pos=3  -> true
//   pos=11 -> true (inserir no final)
//   pos=13 -> false
//   pos=-1 -> false
//
// Interpretação adotada (coerente com o exemplo):
// - pos é índice 0-based.
// - pos == tamanho significa "inserir no final".

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

// Função principal da atividade.
bool inserePosicao(No** lista, int pos, int valor)
{
    // Se pos for inválido (negativo), retorna false imediatamente.
    if (pos < 0)
        return false;

    // Criamos o novo nó (se falhar em alocar, retornamos false).
    No* novo = new No();
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = NULL;

    // Caso pos == 0: inserir no começo.
    if (pos == 0)
    {
        novo->prox = *lista;
        *lista = novo;
        return true;
    }

    // Para inserir na posição pos (0-based), precisamos do nó anterior.
    // Queremos inserir depois do nó de índice pos-1.
    No* anterior = *lista;

    // Vamos avançar pos-1 vezes.
    // Primeiro, garantimos que a lista não acabou antes.
    int indiceAnterior = 0; // anterior está no índice 0 inicialmente

    while (anterior != NULL && indiceAnterior < pos - 1)
    {
        anterior = anterior->prox;
        indiceAnterior++;
    }

    // Se anterior ficou NULL, significa que a posição era inválida.
    // Exemplo: lista tem tamanho menor que pos.
    if (anterior == NULL)
    {
        delete novo;
        return false;
    }

    // Depois de mover, anterior está no nó de índice pos-1.
    // A nova ligação será:
    // novo->prox = anterior->prox
    // anterior->prox = novo
    novo->prox = anterior->prox;
    anterior->prox = novo;

    return true;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Criando L1: 2 5 3 9 9 8 7 6 2 1
    No* L1 = NULL;
    inicializaL(&L1);

    // Como insereInicioL adiciona no começo, precisamos inserir em ordem reversa.
    insereInicioL(&L1, 1);
    insereInicioL(&L1, 2);
    insereInicioL(&L1, 6);
    insereInicioL(&L1, 7);
    insereInicioL(&L1, 8);
    insereInicioL(&L1, 9);
    insereInicioL(&L1, 9);
    insereInicioL(&L1, 3);
    insereInicioL(&L1, 5);
    insereInicioL(&L1, 2);

    cout << "L1 original: ";
    mostraL(&L1);

    cout << "\ninserePosicao(L1, 0, 100) -> " << (inserePosicao(&L1, 0, 100) ? "true" : "false") << "\n";
    mostraL(&L1);

    cout << "\ninserePosicao(L1, 3, 200) -> " << (inserePosicao(&L1, 3, 200) ? "true" : "false") << "\n";
    mostraL(&L1);

    cout << "\ninserePosicao(L1, 11, 300) -> " << (inserePosicao(&L1, 11, 300) ? "true" : "false") << "\n";
    mostraL(&L1);

    cout << "\ninserePosicao(L1, 13, 1000) -> " << (inserePosicao(&L1, 13, 1000) ? "true" : "false") << "\n";
    mostraL(&L1);

    cout << "\ninserePosicao(L1, -1, 1000) -> " << (inserePosicao(&L1, -1, 1000) ? "true" : "false") << "\n";
    mostraL(&L1);

    destroiL(&L1);
    return 0;
}

