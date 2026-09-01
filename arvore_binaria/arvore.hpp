#ifndef _HPP_ARVORE
#define _HPP_ARVORE

#include <iostream>
using namespace std;
typedef struct arv
{
    int info;
    arv *sae;
    arv *sad;
} arvore;

int vazia(arvore *t)
{
    if (t == NULL)
        return 1;
    if (t->info == NULL)
        return 1;
    return 0;
}

void inserir(arvore **t, int num)
{
    if (*t == NULL)
    {
        *t = new arvore;
        (*t)->sae = NULL;
        (*t)->sad = NULL;
        (*t)->info = num;
    }
    // continua ao lado

    else
    {
        if (num < (*t)->info)
            inserir(&(*t)->sae, num);
        else
            inserir(&(*t)->sad, num);
    }

} // fecha a função

void mostra_preOrdem(arvore *t)
{
    cout << "<";
    if (!vazia(t))
    {
        cout << t->info;
        mostra_preOrdem(t->sae);
        mostra_preOrdem(t->sad);
    }
    cout << ">";
}

void mostra_simetrica(arvore *t)
{
    cout << "<";
    if (!vazia(t))
    {
        mostra_simetrica(t->sae);
        cout << t->info;
        mostra_simetrica(t->sad);
    }
    cout << ">";
}

void mostra_posOrdem(arvore *t)
{
    cout << "<";
    if (!vazia(t))
    {
        mostra_posOrdem(t->sae);
        mostra_posOrdem(t->sad);
        cout << t->info;
    }
    cout << ">";
}

bool consulta(arvore *t, int v)
{
    if (vazia(t))
        return 0;
    return t->info == v || consulta(t->sae, v) || consulta(t->sad, v);
}

arvore *remover(arvore **t, int num)
{
    if (num < (*t)->info)
        remover(&(*t)->sae, num);
    else if (num > (*t)->info)
        remover(&(*t)->sad, num);
    else
    {
        arvore *aux = *t;
        // se for uma folha
        if (((*t)->sae == NULL) && ((*t)->sad == NULL))
        {
            delete (aux);
            (*t) = NULL;
        }
        else if ((*t)->sae == NULL)
        {
            // só tem filho a direita
            (*t) = (*t)->sad;
            aux->sad = NULL;
            delete (aux);
            aux = NULL;
        }
        else if ((*t)->sad == NULL)
        {
            // só tem filho a esquerda
            (*t) = (*t)->sae;
            aux->sae = NULL;
            delete (aux);
            aux = NULL;
        }
        else
        {
            aux = (*t)->sae;
            while (aux->sad != NULL)
            {
                aux = aux->sad;
            }
            (*t)->info = aux->info;
            aux->info = num;
            (*t)->sae = remover(&(*t)->sae, num);
        }
    }
    return (*t);
}

#endif