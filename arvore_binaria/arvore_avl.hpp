#ifndef _HPP_ARVORE
#define _HPP_ARVORE

#include <iostream>
#include <fstream>
#include <string>

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

int fator_bal(arvore *p)
{
    if (p == NULL)
        return 0;
    int fator = 0;
    if (p->sae)
        fator += altura(p->sae);
    if (p->sad)
        fator -= altura(p->sad);
    return fator;
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
    if (p == NULL)
        return NULL;

    if (p->sae)
        p->sae = balancear_node(p->sae);
    if (p->sad)
        p->sad = balancear_node(p->sad);

    int fator = fator_bal(p);
    arvore *node_balanceado = p;

    if (fator >= 2)
    {
        if (fator_bal(p->sae) <= -1)
            node_balanceado = rotationar_esq_dir(p);
        else
            node_balanceado = rotacionar_esq_esq(p);
    }
    else if (fator <= -2)
    {
        if (fator_bal(p->sad) >= 1)
            node_balanceado = rotacionar_dir_esq(p);
        else
            node_balanceado = rotacionar_dir_dir(p);
    }

    return node_balanceado;
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
    else
    {
        if (num < (*t)->info)
            inserir(&(*t)->sae, num);
        else if (num > (*t)->info)
            inserir(&(*t)->sad, num);
    }
}

void inserir_avl(arvore **t, int num)
{
    inserir(t, num);
    *t = balancear_node(*t);
}

arvore *remover(arvore **t, int num)
{
    if (*t == NULL)
        return NULL;

    if (num < (*t)->info)
        remover(&(*t)->sae, num);
    else if (num > (*t)->info)
        remover(&(*t)->sad, num);
    else
    {
        arvore *aux = *t;
        if (((*t)->sae == NULL) && ((*t)->sad == NULL))
        {
            delete (aux);
            (*t) = NULL;
        }
        else if ((*t)->sae == NULL)
        {
            (*t) = (*t)->sad;
            aux->sad = NULL;
            delete (aux);
        }
        else if ((*t)->sad == NULL)
        {
            (*t) = (*t)->sae;
            aux->sae = NULL;
            delete (aux);
        }
        else
        {
            aux = (*t)->sae;
            while (aux->sad != NULL)
            {
                aux = aux->sad;
            }
            (*t)->info = aux->info;
            (*t)->sae = remover(&(*t)->sae, aux->info);
        }
    }
    return (*t);
}

void remover_avl(arvore **t, int num)
{
    *t = remover(t, num);
    if (*t != NULL)
        *t = balancear_node(*t);
}

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

void ler_arquivo(arvore **t, string nomeArquivo)
{
    ifstream arquivo(nomeArquivo.c_str());
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    string acao;
    int valor;
    while (arquivo >> acao >> valor)
    {
        if (acao == "inserir")
        {
            inserir_avl(t, valor);
            cout << "Executado: Inserir " << valor << endl;
        }
        else if (acao == "remover")
        {
            remover_avl(t, valor);
            cout << "Executado: Remover " << valor << endl;
        }
    }
    arquivo.close();
}
#endif