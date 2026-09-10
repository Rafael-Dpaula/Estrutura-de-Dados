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
            cout << "Executado: Inserir -> " << valor << endl;
        }
        else if (acao == "remover")
        {
            remover_avl(t, valor);
            cout << "Executado: Remover -> " << valor << endl;
        }
    }
    arquivo.close();
}

void mostrar_arvore_hierarquica(arvore *t, int nivel = 0)
{
    if (t == NULL)
        return;

    mostrar_arvore_hierarquica(t->sad, nivel + 1);

    cout << string(nivel * 4, ' ') << t->info << endl;

    mostrar_arvore_hierarquica(t->sae, nivel + 1);
}

// Mostra a arvore "deitada" com linhas conectando os nos (estilo tree do Windows)
// prefixo = barras verticais a desenhar na linha; ultimo = indica se o filho anterior era o ultimo da direita
void mostrar_arvore_com_linhas(arvore *t, string prefixo, bool ehDireita, bool raiz)
{
    if (t == NULL)
        return;

    string galho = raiz ? "" : (ehDireita ? "|-- " : "`-- ");

    // imprime primeiro a subarvore DIREITA (fica em cima na tela)
    mostrar_arvore_com_linhas(t->sad, prefixo + (raiz ? "" : (ehDireita ? "|   " : "    ")), true, false);

    cout << prefixo << galho << t->info << endl;

    // depois a subarvore ESQUERDA (fica embaixo)
    mostrar_arvore_com_linhas(t->sae, prefixo + (raiz ? "" : (ehDireita ? "|   " : "    ")), false, false);
}

// Chamada simplificada: mostrar_arvore_com_linhas(raiz);
void mostrar_arvore_com_linhas(arvore *t)
{
    mostrar_arvore_com_linhas(t, "", true, true);
}

// ============ VERSAO "DE PE": raiz em cima, filhos embaixo ============
// Largura (em "celulas") de uma subarvore = nos que ela contem
int largura_sub(arvore *t)
{
    if (t == NULL)
        return 0;
    return largura_sub(t->sae) + largura_sub(t->sad) + 1;
}

// Desenha o no na "tela" e chama recursivamente para os filhos,
// calculando a coluna de cada um a partir da largura das subarvores
// tela = matriz de chars criada com new (sem bibliotecas extras)
void desenhar_no(arvore *t, int linha, int inicio, char **tela, int celula)
{
    if (t == NULL)
        return;

    int larg_esq = largura_sub(t->sae) * celula;
    int larg_dir = largura_sub(t->sad) * celula;

    // centro do no atual dentro do espaco que ele ocupa
    int centro = inicio + (larg_esq + celula) / 2;
    // converte o numero para string na mao (sem to_string)
    char texto[12];
    int tam = 0;
    int v = t->info;
    if (v == 0)
        texto[tam++] = '0';
    while (v > 0)
    {
        // desloca o texto para a direita para inserir o novo digito
        for (int i = tam; i > 0; i--)
            texto[i] = texto[i - 1];
        texto[0] = (char)('0' + v % 10);
        tam++;
        v /= 10;
    }
    texto[tam] = '\0';
    for (int i = 0; i < tam; i++)
        tela[linha][centro + i] = texto[i];

    // conectores ( / e \ ) na linha intermediaria
    if (t->sae)
    {
        int centro_esq = inicio + larg_esq / 2;
        if (centro_esq < centro - 1)
            tela[linha + 1][centro - 2] = '/';
        desenhar_no(t->sae, linha + 2, inicio, tela, celula);
    }
    if (t->sad)
    {
        int inicio_dir = inicio + larg_esq + celula;
        int centro_dir = inicio_dir + larg_dir / 2;
        if (centro_dir > centro + 1)
            tela[linha + 1][centro + 2] = '\\';
        desenhar_no(t->sad, linha + 2, inicio_dir, tela, celula);
    }
}

// Chamada simplificada: mostrar_arvore_em_pe(raiz);
void mostrar_arvore_em_pe(arvore *t)
{
    if (t == NULL)
    {
        cout << "(arvore vazia)" << endl;
        return;
    }

    int celula = 4; // largura de cada no na tela
    int largura = largura_sub(t) * celula + 4;
    int linhas = altura(t) * 2 - 1; // uma linha de valor + uma de conector por nivel

    // cria a matriz de caracteres na mao
    char **tela = new char *[linhas];
    for (int i = 0; i < linhas; i++)
    {
        tela[i] = new char[largura + 1];
        for (int j = 0; j < largura; j++)
            tela[i][j] = ' ';
        tela[i][largura] = '\0';
    }

    desenhar_no(t, 0, 2, tela, celula);

    for (int i = 0; i < linhas; i++)
    {
        // remove espacos sobrando no fim da linha
        int fim = largura;
        while (fim > 0 && tela[i][fim - 1] == ' ')
            fim--;
        tela[i][fim] = '\0';
        cout << tela[i] << endl;
    }

    // libera a memoria
    for (int i = 0; i < linhas; i++)
        delete[] tela[i];
    delete[] tela;
}

#endif