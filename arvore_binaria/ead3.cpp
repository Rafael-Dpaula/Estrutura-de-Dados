#include<iostream>
using namespace std;
#include "arvore.hpp"

int altura_aux(arvore *t)
{
    if (vazia(t))
        return 0;
    return 1 + max(altura_aux(t->sae), altura_aux(t->sad));
}

int altura_subarvore_esquerda(arvore *t)
{
    if (vazia(t))
    {
        cout << "Árvore vazia!" << endl;
        return -1;
    }
    return altura_aux(t->sae);
}

int altura_subarvore_direita(arvore *t)
{
    if (vazia(t))
    {
        cout << "Árvore vazia!" << endl;
        return -1;
    }
    return altura_aux(t->sad);
}

int altura_arvore(arvore *t)
{
    if (vazia(t))
    {
        cout << "Árvore vazia!" << endl;
        return 0;
    }
    return altura_aux(t);
}

void limpar_arvore(arvore **t)
{
    if (!vazia(*t))
    {
        limpar_arvore(&(*t)->sae);
        limpar_arvore(&(*t)->sad);
        delete (*t);
        *t = NULL;
    }
}

int encontrar_nivel_aux(arvore *t, int valor, int nivel_atual)
{
    if (vazia(t))
        return -1; // valor não encontrado

    if (t->info == valor)
        return nivel_atual;

    int nivel_esq = encontrar_nivel_aux(t->sae, valor, nivel_atual + 1);
    if (nivel_esq != -1)
        return nivel_esq;

    return encontrar_nivel_aux(t->sad, valor, nivel_atual + 1);
}

int encontrar_nivel(arvore *t, int valor)
{
    if (vazia(t))
    {
        cout << "Árvore vazia!" << endl;
        return -1;
    }
    return encontrar_nivel_aux(t, valor, 1);
}

int main()
{
    arvore *arvore_principal = NULL;
    int opcao, valor, resultado;

    do
    {
        cout << "\n========== MENU DE ÁRVORE BINÁRIA ==========" << endl;
        cout << "1. Inserir valor" << endl;
        cout << "2. Consultar valor" << endl;
        cout << "3. Remover valor" << endl;
        cout << "4. Altura da sub-árvore esquerda" << endl;
        cout << "5. Altura da sub-árvore direita" << endl;
        cout << "6. Altura da árvore" << endl;
        cout << "7. Encontrar nível de um valor" << endl;
        cout << "8. Mostrar árvore (pré-ordem)" << endl;
        cout << "9. Mostrar árvore (simétrica)" << endl;
        cout << "10. Mostrar árvore (pós-ordem)" << endl;
        cout << "11. Limpar árvore" << endl;
        cout << "0. Sair" << endl;
        cout << "========================================" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o valor a inserir: ";
            cin >> valor;
            inserir(&arvore_principal, valor);
            cout << "Valor inserido com sucesso!" << endl;
            break;

        case 2:
            cout << "Digite o valor a consultar: ";
            cin >> valor;
            if (consulta(arvore_principal, valor))
                cout << "Valor encontrado na árvore!" << endl;
            else
                cout << "Valor NÃO encontrado na árvore!" << endl;
            break;

        case 3:
            cout << "Digite o valor a remover: ";
            cin >> valor;
            if (consulta(arvore_principal, valor))
            {
                remover(&arvore_principal, valor);
                cout << "Valor removido com sucesso!" << endl;
            }
            else
                cout << "Valor não encontrado na árvore!" << endl;
            break;

        case 4:
            resultado = altura_subarvore_esquerda(arvore_principal);
            if (resultado != -1)
                cout << "Altura da sub-árvore esquerda: " << resultado << endl;
            break;

        case 5:
            resultado = altura_subarvore_direita(arvore_principal);
            if (resultado != -1)
                cout << "Altura da sub-árvore direita: " << resultado << endl;
            break;

        case 6:
            resultado = altura_arvore(arvore_principal);
            cout << "Altura da árvore: " << resultado << endl;
            break;

        case 7:
            cout << "Digite o valor para encontrar o nível: ";
            cin >> valor;
            resultado = encontrar_nivel(arvore_principal, valor);
            if (resultado != -1)
                cout << "O valor " << valor << " está no nível: " << resultado << endl;
            else
                cout << "Valor não encontrado na árvore!" << endl;
            break;

        case 8:
            cout << "Árvore em pré-ordem: ";
            mostra_preOrdem(arvore_principal);
            cout << endl;
            break;

        case 9:
            cout << "Árvore em ordem simétrica: ";
            mostra_simetrica(arvore_principal);
            cout << endl;
            break;

        case 10:
            cout << "Árvore em pós-ordem: ";
            mostra_posOrdem(arvore_principal);
            cout << endl;
            break;

        case 11:
            limpar_arvore(&arvore_principal);
            cout << "Árvore limpa e memória liberada!" << endl;
            break;

        case 0:
            limpar_arvore(&arvore_principal);
            cout << "Encerrando programa..." << endl;
            break;

        default:
            cout << "Opção inválida! Tente novamente." << endl;
        }

    } while (opcao != 0);

    return EXIT_SUCCESS;
}