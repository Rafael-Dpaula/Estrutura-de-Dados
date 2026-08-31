#ifndef _HPP_ARVORE
#define _HPP_ARVORE

#include <iostream>
using namespace std;
typedef struct arv
{
    int info;
    int fb;
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

int altura(arvore *t)
{
    if (t == NULL)
        return 0;
    int alt_esq = altura(t->sae);
    int alt_dir = altura(t->sad);
    return (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
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

int fator_bal(arvore *p)
{
    int fator = 0;
    if (p->sae)
        fator += altura(p->sae);

    if (p->sad)
        fator -= altura(p->sad);
    return fator;
}

void calcula_fb(arvore *p)
{
    if (!vazia(p))
    {
        p->fb = fator_bal(p);
        if (p->sae != NULL)
            calcula_fb(p->sae);
        if (p->sad != NULL)
            calcula_fb(p->sad);
    }
}

int verifica_avl(arvore *p)
{
    if (!vazia(p))
    {
        if ((p->fb > 1) || (p->fb < -1))
        {
            return p->fb;
        }
        if (p->sae != NULL)
            verifica_avl(p->sae);
        else
            return 0;
        if (p->sad != NULL)
            verifica_avl(p->sad);
        else
            return 0;
    }
}

arvore *rotacionar_esq_esq(arvore *p)
{
    arvore *temp_ptr = p;
    arvore *esq_ptr = temp_ptr->sae;
    temp_ptr->sae = esq_ptr->sad;
    esq_ptr->sad = temp_ptr;
    return esq_ptr;
}

arvore *rotacionar_dir_dir(arvore *t)
{
    arvore *temp_ptr = t;
    arvore *dir_ptr = temp_ptr->sad;
    temp_ptr->sad = dir_ptr->sae;
    dir_ptr->sae = temp_ptr;
    return dir_ptr;
}

arvore *rotationar_esq_dir(arvore *p)
{
    arvore *temp_ptr = p;
    arvore *esq_ptr = temp_ptr->sae;
    arvore *dir_ptr = esq_ptr->sad;
    temp_ptr->sae = dir_ptr->sad;
    esq_ptr->sad = dir_ptr->sae;
    dir_ptr->sae = esq_ptr;
    dir_ptr->sad = temp_ptr;
    return dir_ptr;
}

arvore *rotacionar_dir_esq(arvore *p)
{
    arvore *temp_ptr = p;
    arvore *dir_ptr = temp_ptr->sad;
    arvore *esq_ptr = dir_ptr->sae;
    temp_ptr->sad = esq_ptr->sae;
    dir_ptr->sae = esq_ptr->sad;
    esq_ptr->sad = dir_ptr;
    esq_ptr->sae = temp_ptr;
    return esq_ptr;
}

arvore *balancear_node(arvore *p)
{
    arvore *node_balanceado = NULL;
    if (p->sae)
        p->sae = balancear_node(p->sae);
    if (p->sad)
        p->sad = balancear_node(p->sad);
    int fator = fator_bal(p);
    if (fator >= 2)
    {
        /* pesando pra esquerda */
        if (fator_bal(p->sae) <= -1)
            node_balanceado = rotationar_esq_dir(p);
        else
            node_balanceado = rotacionar_esq_esq(p);
    }
    else if (fator <= -2)
    {
        /* pesando pra direita */
        if (fator_bal(p->sad) >= 1)
            node_balanceado = rotacionar_dir_esq(p);
        else
            node_balanceado = rotacionar_dir_dir(p);
    }
    else
    {
        node_balanceado = p;
    }
    return node_balanceado;
} // encerra a função

#endif