#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA


struct NoFila
{
    Pacote dado; //informacao do n�
    NoFila *prox; //proximo elemento da fila
};

struct Fila
{
    NoFila *inicio;
    NoFila *fim;

    Fila()  //Construtor. Usado para inicializar os dados das vari�veis da struct
    {
        inicio = nullptr;
        fim = nullptr;
    }
};


bool vaziaF(Fila *f)
{
    if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}


//Enqueue
bool enfileiraF(Fila *f, Pacote dado)
{
    NoFila *novo = new NoFila();
    if (novo == NULL) /// n�o conseguiu alocar mem�ria (novo == NULL)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

//Dequeue
Pacote desenfileiraF(Fila *f)
{
    Pacote dado;

    // se n�o estiver vazia, retira valor
    if (vaziaF(f) == false) //verifica se a fila n�o est� vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado; //pega o dado armazenado no primeiro n�
        NoFila *apagar = f->inicio; //guarda o primeiro n� em uma vari�vel auxiliar;
        f->inicio = f->inicio->prox; // atualiza o in�cio da fila
        delete apagar;  // libera a mem�ria

        if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}

//peek
float espiaF(Fila* f)
{
    Pacote dado;

    if (vaziaF(f) == false) //verifica se a fila n�o est� vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado;
    }

    return dado.peso;
}

//show
void mostraF(Fila *f, string nome = "")
{
    cout << "Fila " << nome <<": ";

    if(vaziaF(f) == false) //verifica se a fila n�o est� vazia
    {

        cout << "{";

        NoFila *no = f->inicio;
        while (no != NULL) //fa�a enquanto (no != NULL)
        {
            cout << "[";
            cout << "cod=" <<no->dado.codigo << ", " << "peso="<<no->dado.peso;
            no = no->prox;
            cout << "]";

            if(no != NULL) //verifica se o pr�ximo n� n�o � nulo (no != NULL)
                cout << ", ";
        }
        cout << "}" << endl;
    }
    else
        cout << "{}"<<endl;
}

// retorna true se o valor existe na fila
// retorna false se o valor n�o existe na fila
bool buscaF(Fila *f, int cod1, int cod2)
{

    NoFila *no = f->inicio;
    while (no != NULL)
    {
        if((no->dado.codigo == cod1) and (no->prox->dado.codigo))
            return true;

        no = no->prox;
    }

    return false;

}

void destroiF(Fila *f)
{

    NoFila *no = f->inicio;
    while (no != NULL) //fa�a enquanto (no != NULL)
    {
        NoFila *apagar = no; //guarda o n� em uma vari�vel auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif // _HPP_FILA_DINAMICA





