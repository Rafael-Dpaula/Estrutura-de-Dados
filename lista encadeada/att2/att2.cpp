#include <iostream>
#include <string>

using namespace std;

// ============================================================
// ATIVIDADE 2 - LISTA ENCADEADA DE PRODUTOS (nome + quantidade)
// ============================================================
// Regras do enunciado (importantes):
// - Proibido uso de arrays e listas auxiliares.
// - Não vamos usar estruturas de dados auxiliares para criar a lista.
// - Para trabalhar com "nome" e "quantidade", precisamos adaptar a estrutura
//   da lista (porque o exemplo era apenas para int).

struct Produto
{
    string nome;
    int quantidade;
};

struct NoProduto
{
    Produto dado;
    NoProduto* prox;
};

// Inicializa a lista vazia
void inicializaL(NoProduto** lista)
{
    *lista = NULL;
}

// Verifica se a lista está vazia
bool vaziaL(NoProduto** lista)
{
    return (*lista == NULL);
}

// Exibe a lista (apenas para teste)
void mostraL(NoProduto** lista)
{
    NoProduto* n = *lista;

    cout << "L:{";
    while (n != NULL)
    {
        cout << "(" << n->dado.nome << ", " << n->dado.quantidade << ")";
        n = n->prox;
        if (n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

// Destroi a lista
void destroiL(NoProduto** lista)
{
    NoProduto* n = *lista;
    while (n != NULL)
    {
        NoProduto* aux = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

// Insere no início (ajuda nos testes do main)
bool insereInicioL(NoProduto** lista, Produto p)
{
    NoProduto* novo = new NoProduto();
    if (novo == NULL)
        return false;

    novo->dado = p;
    novo->prox = *lista;
    *lista = novo;
    return true;
}

// Retorna a soma das quantidades dos produtos com o nome informado.
int soma(NoProduto** lista, string nome)
{
    int total = 0;

    NoProduto* n = *lista;
    while (n != NULL)
    {
        if (n->dado.nome == nome)
            total += n->dado.quantidade;

        n = n->prox;
    }

    return total;
}

// Retorna quantos elementos possuem o nome informado.
int contProdutos(NoProduto** lista, string nome)
{
    int cont = 0;

    NoProduto* n = *lista;
    while (n != NULL)
    {
        if (n->dado.nome == nome)
            cont++;

        n = n->prox;
    }

    return cont;
}

// Soma as quantidades dos nós entre as posições I e F (inclusive).
// Convenção usada:
// - I e F são índices 0-based.
// - Se I > F, trocamos para ficar válido.
// - Se a lista terminar antes, somamos apenas o que existe.
int somaIntervalo(NoProduto** lista, int I, int F)
{
    if (lista == NULL)
        return 0;

    if (I > F)
    {
        int aux = I;
        I = F;
        F = aux;
    }

    if (F < 0)
        return 0;

    int total = 0;

    int indice = 0;
    NoProduto* n = *lista;

    while (n != NULL)
    {
        if (indice >= I && indice <= F)
            total += n->dado.quantidade;

        n = n->prox;
        indice++;
    }

    return total;
}

// Combina os produtos com o mesmo nome somando quantidades.
// Ideia:
// - Percorremos a lista.
// - Quando encontramos um nó com o nome desejado,
//   percorremos o restante procurando outros nós com o mesmo nome.
// - Ao encontrar outro, somamos quantidades e removemos o nó repetido.
// Atenção: não usamos lista auxiliar.
void combinarProd(NoProduto** lista, string nome)
{
    if (vaziaL(lista))
        return;

    NoProduto* atual = *lista;

    while (atual != NULL)
    {
        // Só precisamos combinar quando o nó atual tem o nome desejado.
        if (atual->dado.nome == nome)
        {
            NoProduto* anterior = atual;
            NoProduto* n = atual->prox;

            // Vamos procurar repetidos depois do nó atual.
            while (n != NULL)
            {
                if (n->dado.nome == nome)
                {
                    // Somamos a quantidade do repetido no nó atual.
                    atual->dado.quantidade += n->dado.quantidade;

                    // Removemos o nó n.
                    anterior->prox = n->prox;
                    delete n;

                    // n agora vira o próximo do anterior.
                    n = anterior->prox;
                }
                else
                {
                    // Se não é repetido, apenas avançamos.
                    anterior = n;
                    n = n->prox;
                }
            }
        }

        atual = atual->prox;
    }
}

// Retorna verdadeiro se a soma dos intervalos em cada lista for igual.
bool verificaIntervalos(NoProduto** lista1, NoProduto** lista2, int I1, int F1, int I2, int F2)
{
    int soma1 = somaIntervalo(lista1, I1, F1);
    int soma2 = somaIntervalo(lista2, I2, F2);

    return (soma1 == soma2);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    NoProduto* lista = NULL;
    inicializaL(&lista);

    Produto p1 = {"Arroz", 10};
    Produto p2 = {"Arroz", 5};
    Produto p3 = {"Feijao", 7};
    Produto p4 = {"Arroz", 3};

    insereInicioL(&lista, p4);
    insereInicioL(&lista, p3);
    insereInicioL(&lista, p2);
    insereInicioL(&lista, p1);

    cout << "Lista inicial:\n";
    mostraL(&lista);

    cout << "Soma do produto 'Arroz': " << soma(&lista, "Arroz") << "\n";
    cout << "Quantidade de elementos com nome 'Arroz': " << contProdutos(&lista, "Arroz") << "\n";

    cout << "SomaIntervalo (pos 0 a 2): " << somaIntervalo(&lista, 0, 2) << "\n";

    cout << "Combinar produtos com nome 'Arroz'...\n";
    combinarProd(&lista, "Arroz");
    mostraL(&lista);

    NoProduto* lista2 = NULL;
    inicializaL(&lista2);
    insereInicioL(&lista2, Produto{"X", 1});
    insereInicioL(&lista2, Produto{"Y", 2});
    insereInicioL(&lista2, Produto{"Z", 3});
    insereInicioL(&lista2, Produto{"W", 4});

    cout << "Lista2:\n";
    mostraL(&lista2);

    cout << "verificaIntervalos(lista, lista2, 0, 1, 2, 3): "
         << (verificaIntervalos(&lista, &lista2, 0, 1, 2, 3) ? "true" : "false") << "\n";

    destroiL(&lista);
    destroiL(&lista2);
    return 0;
}

