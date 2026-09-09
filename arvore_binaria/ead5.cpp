#include "arvore_avl.hpp"

using namespace std;

// ============================================================
// 1. MOSTRAR QUANTIDADE DE NOS POR NIVEL
// ============================================================

// Conta quantos nos existem em determinado nivel.
int contar_nos_nivel(arvore *t, int nivel)
{
    if (t == NULL)
        return 0;

    // Se chegou no nivel procurado, encontrou um no.
    if (nivel == 0)
        return 1;

    // Procura nos dois lados diminuindo o nivel.
    return contar_nos_nivel(t->sae, nivel - 1) + contar_nos_nivel(t->sad, nivel - 1);
}

// Exibe a quantidade de nos em cada nivel.
void mostrar_nos_por_nivel(arvore *t)
{
    if (t == NULL)
    {
        cout << "Arvore vazia." << endl;
        return;
    }

    int h = altura(t);

    for (int nivel = 0; nivel < h; nivel++)
    {
        int quantidade = contar_nos_nivel(t, nivel);

        cout << "Nivel " << nivel << ": " << quantidade << " no";

        if (quantidade != 1)
            cout << "s";

        cout << endl;
    }
}

// ============================================================
// 2. ENCONTRAR UM NO
// ============================================================

// Procura um determinado valor na arvore.
// Retorna o ponteiro para o no ou NULL caso nao encontre.
arvore *buscar(arvore *t, int valor)
{
    if (t == NULL)
        return NULL;

    if (t->info == valor)
        return t;

    if (valor < t->info)
        return buscar(t->sae, valor);

    return buscar(t->sad, valor);
}

// Mostra o fator de balanceamento de um valor.
void mostrar_fator_balanceamento(arvore *t, int valor)
{
    arvore *no = buscar(t, valor);

    if (no == NULL)
    {
        cout << "O valor informado nao pertence a arvore" << endl;
        return;
    }

    cout << "Fator de balanceamento de " << valor << ": "
         << fator_bal(no) << endl;
}

// ============================================================
// 3. MAIOR ELEMENTO E SEU NIVEL
// ============================================================

// Procura o maior elemento e tambem descobre seu nivel.
void maior_elemento(arvore *t, int nivel, int &maior, int &nivel_maior)
{
    if (t == NULL)
        return;

    // Como e uma arvore binaria de busca,
    // o maior elemento sempre esta no lado direito.
    if (t->sad != NULL)
    {
        maior_elemento(t->sad, nivel + 1, maior, nivel_maior);
    }
    else
    {
        maior = t->info;
        nivel_maior = nivel;
    }
}

void mostrar_maior_elemento(arvore *t)
{
    if (t == NULL)
    {
        cout << "Nao possui" << endl;
        return;
    }

    int maior = 0;
    int nivel_maior = 0;

    maior_elemento(t, 0, maior, nivel_maior);

    cout << "Maior elemento: " << maior << endl;
    cout << "Nivel: " << nivel_maior << endl;
}

// ============================================================
// 4. LCA - ANCESTOR COMUM MAIS PROXIMO
// ============================================================

// Encontra o menor ancestral comum de dois valores.
//
// Como a arvore e uma ABB:
// - Se os dois valores sao menores, vamos para esquerda.
// - Se os dois sao maiores, vamos para direita.
// - Caso contrario, o no atual e o LCA.
arvore *lca(arvore *t, int valor1, int valor2)
{
    if (t == NULL)
        return NULL;

    if (valor1 < t->info && valor2 < t->info)
        return lca(t->sae, valor1, valor2);

    if (valor1 > t->info && valor2 > t->info)
        return lca(t->sad, valor1, valor2);

    return t;
}

void mostrar_lca(arvore *t, int valor1, int valor2)
{
    // Antes de procurar o LCA,
    // verificamos se os dois valores existem.
    if (buscar(t, valor1) == NULL)
    {
        cout << "Nao possui o valor " << valor1 << endl;
        return;
    }

    if (buscar(t, valor2) == NULL)
    {
        cout << "Nao possui o valor " << valor2 << endl;
        return;
    }

    arvore *resultado = lca(t, valor1, valor2);

    if (resultado != NULL)
        cout << "Ancestor comum mais proximo: "
             << resultado->info << endl;
    else
        cout << "Nao possui" << endl;
}

// ============================================================
// 5. SOMA DOS VALORES
// ============================================================

// Soma todos os valores da arvore.
int soma_valores(arvore *t)
{
    if (t == NULL)
        return 0;

    return t->info +
           soma_valores(t->sae) +
           soma_valores(t->sad);
}

void mostrar_soma(arvore *t)
{
    if (t == NULL)
    {
        cout << "Nao possui" << endl;
        return;
    }

    cout << "Soma dos valores: "
         << soma_valores(t) << endl;
}

// ============================================================
// 6. MENOR ELEMENTO E NOS DO MESMO NIVEL
// ============================================================

// Encontra o menor elemento da arvore.
arvore *menor_elemento(arvore *t)
{
    if (t == NULL)
        return NULL;

    if (t->sae == NULL)
        return t;

    return menor_elemento(t->sae);
}

// Exibe os elementos que estao em determinado nivel.
void mostrar_nivel(arvore *t, int nivel)
{
    if (t == NULL)
        return;

    if (nivel == 0)
    {
        cout << t->info << " ";
        return;
    }

    mostrar_nivel(t->sae, nivel - 1);
    mostrar_nivel(t->sad, nivel - 1);
}

// Descobre o nivel de um determinado valor.
int encontrar_nivel(arvore *t, int valor, int nivel)
{
    if (t == NULL)
        return -1;

    if (t->info == valor)
        return nivel;

    if (valor < t->info)
        return encontrar_nivel(t->sae, valor, nivel + 1);

    return encontrar_nivel(t->sad, valor, nivel + 1);
}

void mostrar_mesmo_nivel_menor(arvore *t)
{
    if (t == NULL)
    {
        cout << "Nao possui" << endl;
        return;
    }

    arvore *menor = menor_elemento(t);

    int nivel = encontrar_nivel(t, menor->info, 0);

    cout << "Menor elemento: " << menor->info << endl;
    cout << "Elementos no mesmo nivel: ";

    mostrar_nivel(t, nivel);

    cout << endl;
}

// ============================================================
// MENU
// ============================================================

int main()
{
    arvore *t = NULL;

    int opcao;
    int valor;
    int valor1;
    int valor2;

    do
    {
        cout << endl;
        cout << "==============================" << endl;
        cout << "       ARVORE AVL" << endl;
        cout << "==============================" << endl;
        cout << "1 - Inserir elemento" << endl;
        cout << "2 - Mostrar arvore" << endl;
        cout << "3 - Remover elemento" << endl;
        cout << "4 - Ler arquivo texto" << endl;
        cout << "5 - Nos por nivel" << endl;
        cout << "6 - Fator de balanceamento" << endl;
        cout << "7 - Maior elemento e nivel" << endl;
        cout << "8 - Ancestor comum mais proximo (LCA)" << endl;
        cout << "9 - Soma dos valores" << endl;
        cout << "10 - Elementos no mesmo nivel do menor" << endl;
        cout << "0 - Sair" << endl;
        cout << "==============================" << endl;

        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o valor: ";
            cin >> valor;

            inserir_avl(&t, valor);

            cout << "Elemento inserido." << endl;
            break;

        case 2:
            if (t == NULL)
            {
                cout << "Arvore vazia." << endl;
            }
            else
            {
                cout << "Pre-ordem: ";
                mostra_preOrdem(t);
                cout << endl;

                cout << "Simetrica: ";
                mostra_simetrica(t);
                cout << endl;

                cout << "Pos-ordem: ";
                mostra_posOrdem(t);
                cout << endl;
            }
            break;

        case 3:
            cout << "Digite o valor a remover: ";
            cin >> valor;

            if (buscar(t, valor) == NULL)
            {
                cout << "O valor informado nao pertence a arvore" << endl;
            }
            else
            {
                remover_avl(&t, valor);
                cout << "Elemento removido." << endl;
            }
            break;

        case 4:
        {
            string nomeArquivo;

            cout << "Digite o nome do arquivo: ";
            cin >> nomeArquivo;

            ler_arquivo(&t, nomeArquivo);
            break;
        }

        case 5:
            mostrar_nos_por_nivel(t);
            break;

        case 6:
            cout << "Digite o valor: ";
            cin >> valor;

            mostrar_fator_balanceamento(t, valor);
            break;

        case 7:
            mostrar_maior_elemento(t);
            break;

        case 8:
            cout << "Digite o primeiro valor: ";
            cin >> valor1;

            cout << "Digite o segundo valor: ";
            cin >> valor2;

            mostrar_lca(t, valor1, valor2);
            break;

        case 9:
            mostrar_soma(t);
            break;

        case 10:
            mostrar_mesmo_nivel_menor(t);
            break;

        case 0:
            cout << "Programa encerrado." << endl;
            break;

        default:
            cout << "Opcao invalida." << endl;
        }

    } while (opcao != 0);

    return 0;
}