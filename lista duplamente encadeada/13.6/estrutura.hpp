#ifndef _HPP_LISTA_DUPLA_13_6
#define _HPP_LISTA_DUPLA_13_6

#include <iostream>
#include <string>
using namespace std;

struct Reuniao
{
    string titulo;
    int duracao;
};

struct No
{
    Reuniao dado;
    No *prox;
    No *ant;
    No()
    {
        prox = nullptr;
        ant = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista()
    {
        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }
};

void destroiL(Lista *l)
{
    No *n = l->inicio;
    while (n)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = nullptr;
    l->inicio = nullptr;
    l->tamanho = 0;
}

bool vaziaL(Lista *lista)
{
    if (!lista)
        return true;
    return (lista->inicio == nullptr);
}

bool insereDepoisNo(Lista *lista, No *pos, const Reuniao &r)
{
    if (!lista || !pos)
        return false;

    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = r;

    novo->ant = pos;
    novo->prox = pos->prox;

    if (pos->prox)
        pos->prox->ant = novo;
    else
        lista->fim = novo;

    pos->prox = novo;
    lista->tamanho++;
    return true;
}

bool insereInicioL(Lista *lista, const Reuniao &r)
{
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = r;
    novo->ant = nullptr;
    novo->prox = lista->inicio;

    if (lista->fim == nullptr)
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;
    return true;
}

void mostraL(Lista *lista, const char *rotulo)
{
    cout << rotulo << " L[" << lista->tamanho << "]:";
    No *n = lista->inicio;
    while (n)
    {
        cout << " [" << n->dado.titulo << "," << n->dado.duracao << "]";
        n = n->prox;
    }
    cout << endl;
}

void mostrarInversoL(Lista *lista, const char *rotulo)
{
    cout << rotulo << " L[" << lista->tamanho << "]:";
    No *n = lista->fim;
    while (n)
    {
        cout << " [" << n->dado.titulo << "," << n->dado.duracao << "]";
        n = n->ant;
    }
    cout << endl;
}

// Exercicio 13.6:
// dividirReunioesLongas(Lista *lista)
// - identifica reunioes com duracao > 240
// - ajusta a duracao do no original para 240
// - insere imediatamente apos o no original um novo no com duracao restante.
// - proibido usar estrutura de dados auxiliares.
void dividirReunioesLongas(Lista *lista)
{
    if (!lista)
        return;

    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.duracao > 240)
        {
            int restante = n->dado.duracao - 240;

            // atualiza a primeira parte no original
            n->dado.duracao = 240;

            // cria a segunda parte (insere apos n)
            Reuniao r;
            r.titulo = n->dado.titulo;
            r.duracao = restante;

            // insere imediatamente depois
            insereDepoisNo(lista, n, r);

            // agora n->prox e o novo no inserido.
            // como a regra e dividir apenas uma vez por iteracao,
            // avancamos para o no seguinte apos o novo.
            n = n->prox->prox;
        }
        else
        {
            n = n->prox;
        }
    }
}

#endif

