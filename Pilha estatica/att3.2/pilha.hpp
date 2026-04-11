#ifndef _HPP_PILHA
#define _HPP_PILHA

struct Pilha
{
    int tam;
    int base;
    int topo;
    int *dados; // Vetor que ser� alocado para armazenar os elementos da pilha

    Pilha() // Construtor. Usado para inicializar os dados das vari�veis da struct
    {
        tam = 0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};

/// inicializa��o dos dados da pilha
void inicializaP(Pilha *p, int tam)
{
    p->base = -1; ///  (*p).base = -1;  /// p->base  p.topo
    p->topo = -1;
    p->tam = tam;
    p->dados = new int[tam]; /// aloca mem�ria dinamicamente
}

// retorna true se a pilha foi inicializada
// retorna false se a pilha n�o foi inicializada
bool verificaInicializacaoP(Pilha *p) // verifica de a pilha foi inicializada
{
    if (p->dados != NULL)
        return true;
    else
        return false;
}

void destroiP(Pilha *p)
{
    p->base = -1;
    p->topo = -1;
    p->tam = 0;

    if (p->dados != NULL)
    {
        delete[] (p->dados);
        p->dados = NULL;
    }
}

bool cheiaP(Pilha *p)
{
    if (p->topo == p->tam - 1)
        return true;
    else
        return false;
}

bool vaziaP(Pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}

/// push
bool empilhaP(Pilha *p, int valor) /// push
{
    /// retorna false se a pilha n�o foi inicializada ou se ela est� cheia
    if (verificaInicializacaoP(p) == false || cheiaP(p) == true)
        return false;
    else
    {
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}

/// pop
int desempilhaP(Pilha *p) /// pop
{

    int valor = 0; // inicializar a vari�vel valor, a qual ser� retornada

    /// se a pilha foi inicializada && se n�o estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        valor = p->dados[p->topo];
        p->topo--;
    }

    return valor;
}

/// peek
int espiaP(Pilha *p) /// peek
{
    int valor = 0; // inicializar a vari�vel valor, a qual ser� retornada

    if (vaziaP(p) == false)
    {
        valor = p->dados[p->topo];
    }

    return valor;
}

void mostraP(Pilha *p)
{

    cout << "PILHA: " << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO: " << p->topo << endl;
    if (vaziaP(p) == false)
    {
        cout << "------------" << endl;
        for (int i = p->topo; i > p->base; i--)
        {

            cout << i << "| " << p->dados[i] << endl;
            cout << "------------" << endl;
        }
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor n�o existe na pilha
bool buscaP(Pilha *p, Pilha *aux, int valor)
{
    inicializaP(aux, p->tam);

    bool encontrou = false;
    while (!vaziaP(p))
    {
        int v = desempilhaP(p);
        empilhaP(aux, v);
        if (v == valor)
        {
            encontrou = true;
            break;
        }
    }
    while (!vaziaP(aux))
    {
        int v = desempilhaP(aux);
        empilhaP(p, v);
    }
    return encontrou;
}

void estatisticasP(Pilha *p, int *maior, int *menor, float *media)
{
    *maior = 0;
    *menor = 0;
    *media = 0;
    float soma = 0;
    if (!vaziaP(p))
    {
        for (int i = p->topo; i > p->base; i--)
        {
            if(i == p->topo){
                *menor = p->dados[i];
                *maior = p->dados[i];
            }


            if (*maior < p->dados[i])
                *maior = p->dados[i];

            if (*menor > p->dados[i])
                *menor = p->dados[i];
                
            soma += p->dados[i];
        }
        *media = soma / p->tam;
    }
}

#endif // _HPP_PILHA
