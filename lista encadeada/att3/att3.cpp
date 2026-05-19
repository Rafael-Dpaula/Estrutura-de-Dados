#include <iostream>
#include <string>

using namespace std;

// ============================================================
// ATIVIDADE 3 - SENHAS NÃO SEGURAS
// ============================================================
// O enunciado pede uma função que receba uma lista de senhas e
// retorne outra lista contendo as senhas NÃO SEGURAS.
//
// Uma senha é NÃO SEGURA se:
// - possuir menos de 4 caracteres, OU
// - for usada por mais de 5 usuários (frequência de aparecimento > 5)
//
// Como a lista de origem pode ter senhas repetidas, vamos considerar
// frequência = quantidade de vezes que a mesma senha aparece na lista.
//
// Regras:
// - Proibido uso de bibliotecas para criar filas/pilhas. Aqui é lista.
// - Também não vamos usar listas auxiliares (nenhuma estrutura de dados extra).
//
// Para conseguir frequência sem estruturas auxiliares, faremos contagens
// por varredura simples da lista (podendo ficar O(n²), mas atende as regras).

struct NoSenha
{
    string senha;
    NoSenha* prox;
};

void inicializaL(NoSenha** lista)
{
    *lista = NULL;
}

bool vaziaL(NoSenha** lista)
{
    return (*lista == NULL);
}

bool insereInicioL(NoSenha** lista, const string& s)
{
    NoSenha* novo = new NoSenha();
    if (novo == NULL)
        return false;

    novo->senha = s;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

void destroiL(NoSenha** lista)
{
    NoSenha* n = *lista;
    while (n != NULL)
    {
        NoSenha* aux = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

void mostraL(NoSenha** lista)
{
    NoSenha* n = *lista;

    cout << "L:{";
    while (n != NULL)
    {
        cout << n->senha;
        n = n->prox;
        if (n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

// Conta quantas vezes a senha aparece na lista.
int contaFrequencia(NoSenha** lista, const string& senha)
{
    int cont = 0;

    NoSenha* n = *lista;
    while (n != NULL)
    {
        if (n->senha == senha)
            cont++;

        n = n->prox;
    }

    return cont;
}

// Cria e retorna uma nova lista com todas as senhas não seguras.
// Importante: como você escolheu a opção (1), cada senha não segura
// deve aparecer apenas uma vez na lista de saída.
NoSenha* naoSeguras(NoSenha* listaOrigem)
{
    // A lista de saída começa vazia.
    NoSenha* saida = NULL;

    // Se a lista de origem estiver vazia, retornamos vazia.
    if (listaOrigem == NULL)
        return saida;

    // Para colocar cada senha não segura apenas uma vez, precisamos evitar duplicar.
    // Sem estruturas auxiliares, vamos decidir se a senha já foi inserida
    // fazendo uma busca na lista de saída (que é uma lista auxiliar, mas não é
    // uma estrutura extra de dados: é a lista que o enunciado pede para retornar).
    // Ou seja, só controlamos duplicidade consultando "saida".

    NoSenha* atualOrigem = listaOrigem;

    while (atualOrigem != NULL)
    {
        string s = atualOrigem->senha;

        // Condição 1: menos de 4 caracteres.
        bool poucoCaracteres = (static_cast<int>(s.size()) < 4);

        // Condição 2: frequência > 5.
        int freq = contaFrequencia(&listaOrigem, s);
        bool frequenciaMaior = (freq > 5);

        // Se for não segura, precisamos inserir na saída apenas uma vez.
        if (poucoCaracteres || frequenciaMaior)
        {
            // Verifica se já existe essa senha na lista de saída.
            bool jaExiste = false;
            NoSenha* nSaida = saida;
            while (nSaida != NULL)
            {
                if (nSaida->senha == s)
                {
                    jaExiste = true;
                    break;
                }
                nSaida = nSaida->prox;
            }

            if (!jaExiste)
            {
                // Inserimos no início para manter o código simples.
                NoSenha* novo = new NoSenha();
                if (novo != NULL)
                {
                    novo->senha = s;
                    novo->prox = saida;
                    saida = novo;
                }
            }
        }

        atualOrigem = atualOrigem->prox;
    }

    return saida;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Lista de exemplo
    NoSenha* lista = NULL;

    // Senhas (repetidas para testar frequência)
    insereInicioL(&lista, "abc");      // < 4 caracteres -> não segura
    insereInicioL(&lista, "senha1");  // vamos repetir 6 vezes
    insereInicioL(&lista, "senha1");
    insereInicioL(&lista, "senha1");
    insereInicioL(&lista, "senha1");
    insereInicioL(&lista, "senha1");
    insereInicioL(&lista, "senha1");

    insereInicioL(&lista, "segura"); // aparece menos de 6 e tamanho >= 4
    insereInicioL(&lista, "1234");   // tamanho 4 e frequência pequena -> segura

    cout << "Lista original:\n";
    mostraL(&lista);

    NoSenha* resultado = naoSeguras(lista);

    cout << "\nSenhas nao seguras (sem repeticoes):\n";
    NoSenha* rptr = resultado;
    // mostraL espera NoSenha**
    mostraL(&rptr);

    destroiL(&lista);
    destroiL(&resultado);

    return 0;
}

