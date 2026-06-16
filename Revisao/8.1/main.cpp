#include <iostream>
#include <string>

#include "../..//lista com descritor/lista_descritor.hpp"

using namespace std;

struct Pessoa
{
    int codigo;
    string nome;
    int idade;
    double salario;

    Pessoa() : codigo(0), nome(""), idade(0), salario(0.0) {}
};

// O que o exercicio exige:
// Manipular duas listas simplesmente encadeadas com descritor (L1 e L2), armazenando Pessoa.
//
// O que ele testa de conhecimento nessa atividade:
// Uso de descritor (inicio/fim/tamanho), insercao no final, percorrimento, interseccao por nome e remocao com criterio.
//
// Como o codigo esta executando:
// - Implementamos uma estrutura de lista com descritor local para Pessoa usando o mesmo padrao da lista_descritor.hpp.
// - Implementamos Inserir, MostrarSalarioMedioPorFaixaEtaria, MostrarInterseccao e RemoverAcimaDeIdadeESalario.

struct NoP
{
    Pessoa dado;
    NoP *prox;

    NoP() : prox(nullptr) {}
};

struct ListaP
{
    NoP *inicio;
    NoP *fim;
    int tamanho;

    ListaP() : inicio(nullptr), fim(nullptr), tamanho(0) {}
};

static bool vaziaP(ListaP *l)
{
    return l->inicio == nullptr;
}

static void destroiP(ListaP *l)
{
    NoP *n = l->inicio;
    while (n != nullptr)
    {
        NoP *aux = n;
        n = n->prox;
        delete aux;
    }
    l->inicio = nullptr;
    l->fim = nullptr;
    l->tamanho = 0;
}

static void mostraP(ListaP *l)
{
    cout << "Lista(P tamanho=" << l->tamanho << "):{";
    NoP *n = l->inicio;
    while (n != nullptr)
    {
        cout << n->dado.nome;
        n = n->prox;
        if (n != nullptr)
            cout << ", ";
    }
    cout << "}\n";
}

static bool inserirFimP(ListaP *l, Pessoa p)
{
    NoP *novo = new NoP();
    if (novo == nullptr)
        return false;

    novo->dado = p;
    novo->prox = nullptr;

    if (vaziaP(l))
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->fim->prox = novo;
        l->fim = novo;
    }

    l->tamanho++;
    return true;
}

static void Inserir(ListaP *l, int codigo, string nome, int idade, double salario)
{
    Pessoa p;
    p.codigo = codigo;
    p.nome = nome;
    p.idade = idade;
    p.salario = salario;

    inserirFimP(l, p);
}

static void MostrarSalarioMedioPorFaixaEtaria(ListaP *l1, ListaP *l2)
{
    double soma[4] = {0.0, 0.0, 0.0, 0.0};
    int cont[4] = {0, 0, 0, 0};

    auto processa = [&](ListaP *l) {
        NoP *n = l->inicio;
        while (n != nullptr)
        {
            int idade = n->dado.idade;
            double salario = n->dado.salario;

            int idx = -1;
            if (idade >= 0 && idade <= 20)
                idx = 0;
            else if (idade >= 21 && idade <= 40)
                idx = 1;
            else if (idade >= 41 && idade <= 60)
                idx = 2;
            else if (idade >= 61)
                idx = 3;

            if (idx >= 0)
            {
                soma[idx] += salario;
                cont[idx]++;
            }

            n = n->prox;
        }
    };

    processa(l1);
    processa(l2);

    cout << "Salario medio por faixa etaria (L1+L2)\n";
    cout << "0 a 20: ";
    if (cont[0] == 0)
        cout << "nao foram encontrados registros\n";
    else
        cout << (soma[0] / cont[0]) << "\n";

    cout << "21 a 40: ";
    if (cont[1] == 0)
        cout << "nao foram encontrados registros\n";
    else
        cout << (soma[1] / cont[1]) << "\n";

    cout << "41 a 60: ";
    if (cont[2] == 0)
        cout << "nao foram encontrados registros\n";
    else
        cout << (soma[2] / cont[2]) << "\n";

    cout << "61+: ";
    if (cont[3] == 0)
        cout << "nao foram encontrados registros\n";
    else
        cout << (soma[3] / cont[3]) << "\n";
}

static bool nomeExisteNoLista(ListaP *l, string nome)
{
    NoP *n = l->inicio;
    while (n != nullptr)
    {
        if (n->dado.nome == nome)
            return true;
        n = n->prox;
    }
    return false;
}

static void MostrarInterseccao(ListaP *l1, ListaP *l2)
{
    // Lista resultado sem repeticao (controle por nome)
    ListaP resultado;

    NoP *n1 = l1->inicio;
    while (n1 != nullptr)
    {
        // Se esta presente em l2 e ainda nao esta em resultado, inserir
        NoP *n2 = l2->inicio;
        while (n2 != nullptr)
        {
            if (n2->dado.nome == n1->dado.nome)
            {
                if (!nomeExisteNoLista(&resultado, n1->dado.nome))
                {
                    Pessoa p = n1->dado;
                    inserirFimP(&resultado, p);
                }
                break;
            }
            n2 = n2->prox;
        }
        n1 = n1->prox;
    }

    cout << "Interseccao (nomes)\n";
    if (resultado.tamanho == 0)
    {
        cout << "Nenhuma pessoa foi encontrada em comum entre as listas\n";
    }
    else
    {
        NoP *n = resultado.inicio;
        while (n != nullptr)
        {
            cout << n->dado.nome << "\n";
            n = n->prox;
        }
    }

    destroiP(&resultado);
}

static void RemoverAcimaDeIdadeESalario(ListaP *l, int idadeLimite, double salarioLimite)
{
    NoP *anterior = nullptr;
    NoP *atual = l->inicio;

    while (atual != nullptr)
    {
        bool deveRemover = (atual->dado.idade > idadeLimite) && (atual->dado.salario > salarioLimite);

        if (deveRemover)
        {
            NoP *remover = atual;

            if (anterior == nullptr)
            {
                l->inicio = atual->prox;
                atual = l->inicio;
            }
            else
            {
                anterior->prox = atual->prox;
                atual = atual->prox;
            }

            if (remover == l->fim)
                l->fim = anterior;

            delete remover;
            l->tamanho--;
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ListaP L1;
    ListaP L2;

    cout << "#8 - duas listas de Pessoas (descritor)\n";

    Inserir(&L1, 1, "Ana", 20, 1000.0);
    Inserir(&L1, 2, "Bruno", 35, 2000.0);
    Inserir(&L1, 3, "Carla", 50, 3000.0);

    Inserir(&L2, 10, "Bruno", 41, 2500.0);
    Inserir(&L2, 11, "Daniel", 19, 1800.0);
    Inserir(&L2, 12, "Ana", 62, 4000.0);

    cout << "L1: ";
    mostraP(&L1);
    cout << "L2: ";
    mostraP(&L2);

    MostrarSalarioMedioPorFaixaEtaria(&L1, &L2);

    MostrarInterseccao(&L1, &L2);

    RemoverAcimaDeIdadeESalario(&L1, 40, 2800.0);
    cout << "L1 apos RemoverAcimaDeIdadeESalario(idade>40, salario>2800)\n";
    mostraP(&L1);

    destroiP(&L1);
    destroiP(&L2);

    return EXIT_SUCCESS;
}

