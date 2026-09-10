#ifndef _HPP_ARVORE
#define _HPP_ARVORE

#include <iostream>
#include <fstream>
#include <string>

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
            return p->fb;

        int resultado;

        if (p->sae != NULL)
        {
            resultado = verifica_avl(p->sae);

            if (resultado != 0)
                return resultado;
        }

        if (p->sad != NULL)
        {
            resultado = verifica_avl(p->sad);

            if (resultado != 0)
                return resultado;
        }
    }

    return 0;
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
    else
    {
        node_balanceado = p;
    }

    return node_balanceado;
}

void inserir(arvore **t, int num)
{
    if (*t == NULL)
    {
        *t = new arvore;

        (*t)->info = num;
        (*t)->fb = 0;
        (*t)->sae = NULL;
        (*t)->sad = NULL;
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

    calcula_fb(*t);

    if (verifica_avl(*t) != 0)
    {
        *t = balancear_node(*t);

        calcula_fb(*t);
    }
}

arvore *remover(arvore **t, int num)
{
    if (*t == NULL)
        return NULL;

    if (num < (*t)->info)
    {
        remover(&(*t)->sae, num);
    }
    else if (num > (*t)->info)
    {
        remover(&(*t)->sad, num);
    }
    else
    {
        arvore *aux = *t;

        if ((*t)->sae == NULL && (*t)->sad == NULL)
        {
            delete aux;
            *t = NULL;
        }
        else if ((*t)->sae == NULL)
        {
            *t = (*t)->sad;
            aux->sad = NULL;
            delete aux;
        }
        else if ((*t)->sad == NULL)
        {
            *t = (*t)->sae;
            aux->sae = NULL;
            delete aux;
        }
        else
        {
            aux = (*t)->sae;

            while (aux->sad != NULL)
                aux = aux->sad;

            (*t)->info = aux->info;

            (*t)->sae = remover(&(*t)->sae, aux->info);
        }
    }

    return *t;
}

void remover_avl(arvore **t, int num)
{
    *t = remover(t, num);

    if (*t != NULL)
    {
        calcula_fb(*t);

        if (verifica_avl(*t) != 0)
        {
            *t = balancear_node(*t);

            calcula_fb(*t);
        }
    }
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

            cout << "Executado: Inserir -> "
                 << valor << endl;
        }
        else if (acao == "remover")
        {
            remover_avl(t, valor);

            cout << "Executado: Remover -> "
                 << valor << endl;
        }
    }

    arquivo.close();
}

void mostrar_arvore_hierarquica(arvore *t, int nivel = 0)
{
    if (t == NULL)
        return;

    mostrar_arvore_hierarquica(t->sad, nivel + 1);

    cout << string(nivel * 4, ' ')
         << t->info << endl;

    mostrar_arvore_hierarquica(t->sae, nivel + 1);
}

void mostrar_arvore_com_linhas(
    arvore *t,
    string prefixo,
    bool ehDireita,
    bool raiz)
{
    if (t == NULL)
        return;

    string galho = raiz
                       ? ""
                       : (ehDireita ? "|-- " : "`-- ");

    mostrar_arvore_com_linhas(
        t->sad,
        prefixo + (raiz ? "" : (ehDireita ? "|   " : "    ")),
        true,
        false);

    cout << prefixo
         << galho
         << t->info << endl;

    mostrar_arvore_com_linhas(
        t->sae,
        prefixo + (raiz ? "" : (ehDireita ? "|   " : "    ")),
        false,
        false);
}

void mostrar_arvore_com_linhas(arvore *t)
{
    mostrar_arvore_com_linhas(t, "", true, true);
}

int largura_sub(arvore *t)
{
    if (t == NULL)
        return 0;

    return largura_sub(t->sae) + largura_sub(t->sad) + 1;
}

void desenhar_no(
    arvore *t,
    int linha,
    int inicio,
    char **tela,
    int celula)
{
    if (t == NULL)
        return;

    int larg_esq = largura_sub(t->sae) * celula;
    int larg_dir = largura_sub(t->sad) * celula;

    int centro = inicio + (larg_esq + celula) / 2;

    char texto[12];
    int tam = 0;
    int v = t->info;

    if (v == 0)
        texto[tam++] = '0';

    while (v > 0)
    {
        for (int i = tam; i > 0; i--)
            texto[i] = texto[i - 1];

        texto[0] = (char)('0' + v % 10);
        tam++;

        v /= 10;
    }

    texto[tam] = '\0';

    for (int i = 0; i < tam; i++)
        tela[linha][centro + i] = texto[i];

    if (t->sae)
    {
        int centro_esq = inicio + larg_esq / 2;

        if (centro_esq < centro - 1)
            tela[linha + 1][centro - 2] = '/';

        desenhar_no(
            t->sae,
            linha + 2,
            inicio,
            tela,
            celula);
    }

    if (t->sad)
    {
        int inicio_dir = inicio + larg_esq + celula;
        int centro_dir = inicio_dir + larg_dir / 2;

        if (centro_dir > centro + 1)
            tela[linha + 1][centro + 2] = '\\';

        desenhar_no(
            t->sad,
            linha + 2,
            inicio_dir,
            tela,
            celula);
    }
}

void mostrar_arvore_em_pe(arvore *t)
{
    if (t == NULL)
    {
        cout << "(arvore vazia)" << endl;
        return;
    }

    int celula = 4;
    int largura = largura_sub(t) * celula + 4;
    int linhas = altura(t) * 2 - 1;

    char **tela = new char *[linhas];

    for (int i = 0; i < linhas; i++)
    {
        tela[i] = new char[largura + 1];

        for (int j = 0; j < largura; j++)
            tela[i][j] = ' ';

        tela[i][largura] = '\0';
    }

    desenhar_no(
        t,
        0,
        2,
        tela,
        celula);

    for (int i = 0; i < linhas; i++)
    {
        int fim = largura;

        while (fim > 0 && tela[i][fim - 1] == ' ')
            fim--;

        tela[i][fim] = '\0';

        cout << tela[i] << endl;
    }

    for (int i = 0; i < linhas; i++)
        delete[] tela[i];

    delete[] tela;
}

void mostrar_entre_limites(
    arvore *t,
    int inferior,
    int superior)
{
    if (t == NULL)
        return;

    if (t->info > inferior)
        mostrar_entre_limites(
            t->sae,
            inferior,
            superior);

    if (t->info > inferior &&
        t->info < superior)
    {
        cout << t->info << " ";
    }

    if (t->info < superior)
        mostrar_entre_limites(
            t->sad,
            inferior,
            superior);
}

#endif