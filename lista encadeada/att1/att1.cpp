#include <iostream>

using namespace std;

// Usamos a mesma estrutura de nó do exemplo de lista simplesmente encadeada.
// A lista guarda apenas inteiros (int), porque a Atividade 1 trabalha com valores int.
//
// Observação importante:
// - Não usamos bibliotecas nem estruturas auxiliares para criar a lista.
// - A ideia aqui é manipular os ponteiros (prox) para alterar a lista.

struct No
{
    int dado;
    No* prox;
};

// Inicializa a lista vazia
void inicializaL(No** lista)
{
    *lista = NULL;
}

// Verifica se a lista está vazia
bool vaziaL(No** lista)
{
    return (*lista == NULL);
}

// Exibe a lista (apenas para ajudar a testar o código)
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

// Insere no início da lista
bool insereInicioL(No** lista, int valor)
{
    No* novo = new No();
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista; // novo aponta para o antigo primeiro
    *lista = novo;       // a lista agora começa em novo

    return true;
}

// Remove todos os elementos da lista
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

// ============================================================
// ATIVIDADE 1 - LISTA SIMPLEMENTE ENCADEADA
// ============================================================

// Insere "valor" APÓS a primeira ocorrência de um valor par na lista.
// Exemplo: 1 3 4 8 2 -> primeiro par é 4, então vira 1 3 4 valor 8 2
void insereAposPrimeiroPar(No** lista, int valor)
{
    // Caso a lista esteja vazia, não tem o que fazer.
    if (vaziaL(lista))
        return;

    // Vamos percorrer a lista buscando o primeiro nó com dado par.
    No* n = *lista;

    while (n != NULL)
    {
        // Verifica se o dado do nó atual é par.
        if (n->dado % 2 == 0)
        {
            // Achamos o primeiro par. Agora criamos um novo nó com "valor".
            No* novo = new No();
            novo->dado = valor;

            // O novo nó deve apontar para o próximo do nó par atual.
            novo->prox = n->prox;

            // O nó par atual deve apontar para o novo nó.
            n->prox = novo;

            // Como é a primeira ocorrência, paramos.
            return;
        }

        // Avança para o próximo nó.
        n = n->prox;
    }

    // Se não existir nenhum par, nada muda.
}

// Insere "valor" ANTES da primeira ocorrência de um valor par na lista.
void insereAntesPrimeiroPar(No** lista, int valor)
{
    // Se a lista estiver vazia, não tem o que inserir.
    if (vaziaL(lista))
        return;

    // Precisamos saber o nó anterior para conseguir inserir antes.
    // Começamos com anterior = NULL.
    No* anterior = NULL;
    No* atual = *lista;

    while (atual != NULL)
    {
        // Verifica se o nó atual tem dado par.
        if (atual->dado % 2 == 0)
        {
            // Criamos o novo nó.
            No* novo = new No();
            novo->dado = valor;

            // O novo nó precisa apontar para o nó par atual (porque ele ficará antes).
            novo->prox = atual;

            // Se anterior for NULL, significa que o primeiro nó já era par.
            // Então o novo vira o novo começo da lista.
            if (anterior == NULL)
                *lista = novo;
            else
                anterior->prox = novo;

            return;
        }

        // Avança: anterior passa a ser o atual e atual vai para o próximo.
        anterior = atual;
        atual = atual->prox;
    }

    // Se não existir nenhum par, nada muda.
}

// Retorna o total de elementos da lista.
int totalL(No** lista)
{
    // contador começa em 0 e aumenta para cada nó encontrado.
    int cont = 0;

    No* n = *lista;
    while (n != NULL)
    {
        cont++;
        n = n->prox;
    }

    return cont;
}

// Verifica se duas listas são iguais.
// Duas listas são iguais se:
// - Têm o mesmo tamanho
// - E cada posição tem o mesmo valor.
bool igualL(No** lista1, No** lista2)
{
    No* n1 = *lista1;
    No* n2 = *lista2;

    // Enquanto ambos apontarem para um nó válido, comparamos os dados.
    while (n1 != NULL && n2 != NULL)
    {
        if (n1->dado != n2->dado)
            return false;

        n1 = n1->prox;
        n2 = n2->prox;
    }

    // Se uma lista terminou antes da outra, elas não são iguais.
    if (n1 != NULL || n2 != NULL)
        return false;

    // Se chegou aqui, ambas terminaram ao mesmo tempo e com mesmos valores.
    return true;
}

// Insere um valor no final da lista.
void insereFinalL(No** lista, int valor)
{
    // Se a lista estiver vazia, o final é o começo.
    if (vaziaL(lista))
    {
        insereInicioL(lista, valor);
        return;
    }

    // Precisamos do último nó para ligar o novo no final.
    No* n = *lista;

    while (n->prox != NULL)
        n = n->prox;

    // n é o último nó. Agora criamos o novo e ligamos.
    No* novo = new No();
    novo->dado = valor;
    novo->prox = NULL;

    n->prox = novo;
}

// Retorna o valor do último elemento da lista SEM remover.
int leFinalL(No** lista)
{
    // Se estiver vazia, o enunciado não define o que retornar.
    // Para manter o padrão do exemplo, retornaremos 0.
    if (vaziaL(lista))
        return 0;

    // Vamos chegar no último nó.
    No* n = *lista;
    while (n->prox != NULL)
        n = n->prox;

    return n->dado;
}

// Retorna o valor do último elemento da lista e REMOVE o elemento.
int removeFinalL(No** lista)
{
    // Se estiver vazia, retornamos 0.
    if (vaziaL(lista))
        return 0;

    // Se existe apenas 1 elemento, remover o final é remover o início.
    if ((*lista)->prox == NULL)
    {
        int valor = (*lista)->dado;
        delete *lista;
        *lista = NULL;
        return valor;
    }

    // Caso geral: precisamos do nó penúltimo.
    No* anterior = NULL;
    No* atual = *lista;

    while (atual->prox != NULL)
    {
        anterior = atual;
        atual = atual->prox;
    }

    // atual é o último, anterior é o penúltimo.
    int valorFinal = atual->dado;

    anterior->prox = NULL; // remove a ligação do penúltimo para o último
    delete atual;

    return valorFinal;
}

// Retorna o valor do nó na posição informada.
// posicao=0 -> primeiro nó
// posicao=1 -> segundo nó
int lePosicao(No** lista, int posição)
{
    // Se a posição for negativa, retornamos 0 (como o exemplo faz para lista vazia).
    if (posição < 0)
        return 0;

    // Se a lista estiver vazia, não existe posição.
    if (vaziaL(lista))
        return 0;

    int indice = 0;
    No* n = *lista;

    while (n != NULL)
    {
        if (indice == posição)
            return n->dado;

        n = n->prox;
        indice++;
    }

    // Se a posição for maior que o tamanho-1, retornamos 0.
    return 0;
}

// Insere "valor" ANTES de CADA ocorrência de um valor par na lista.
void insereAposCadaPar(No** lista, int valor)
{
    // Observação: o nome da função no PDF é insereAposCadaPar.
    // Isso quer dizer: inserir "valor" APÓS cada par.

    if (vaziaL(lista))
        return;

    No* n = *lista;

    while (n != NULL)
    {
        if (n->dado % 2 == 0)
        {
            // Criamos um novo nó depois do par atual.
            No* novo = new No();
            novo->dado = valor;

            // O novo deve apontar para o próximo do par atual.
            novo->prox = n->prox;

            // Agora o par aponta para o novo.
            n->prox = novo;

            // Para não ficar preso, precisamos avançar.
            // Se fizermos n = n->prox, iremos para o novo nó (não é par, então não cria outro).
            // Depois, no próximo ciclo, vamos para o nó que estava depois do par.
            n = novo->prox;
        }
        else
        {
            // Se não for par, apenas avança um.
            n = n->prox;
        }
    }
}

// ============================================================
// Função main apenas para testar rapidamente localmente.
// Se seu professor exigir somente as funções, você pode remover este main.
// ============================================================
int main()
{
    setlocale(LC_ALL, "Portuguese");

    No* lista = NULL;
    inicializaL(&lista);

    // Lista de teste: 1 3 4 8 2 (vamos inserir no início para ficar nessa ordem, faremos ao contrário)
    insereInicioL(&lista, 2);
    insereInicioL(&lista, 8);
    insereInicioL(&lista, 4);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);

    cout << "Lista inicial: ";
    mostraL(&lista);

    insereAposPrimeiroPar(&lista, 99);
    cout << "Após inserir 99 depois do primeiro par: ";
    mostraL(&lista);

    insereAntesPrimeiroPar(&lista, 77);
    cout << "Após inserir 77 antes do primeiro par: ";
    mostraL(&lista);

    cout << "Total de elementos: " << totalL(&lista) << "\n";
    cout << "Valor do ultimo (sem remover): " << leFinalL(&lista) << "\n";

    int removido = removeFinalL(&lista);
    cout << "Removido do final: " << removido << "\n";
    cout << "Lista depois de remover o final: ";
    mostraL(&lista);

    cout << "Valor na posicao 0: " << lePosicao(&lista, 0) << "\n";
    cout << "Valor na posicao 2: " << lePosicao(&lista, 2) << "\n";

    insereAposCadaPar(&lista, 50);
    cout << "Depois de inserir 50 apos cada par: ";
    mostraL(&lista);

    destroiL(&lista);
    return 0;
}

