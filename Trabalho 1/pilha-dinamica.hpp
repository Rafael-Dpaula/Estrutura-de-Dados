#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include "pacote.hpp"

#include <string> //biblioteca usada para formatar a impressão da pilha


struct NoPilha
{
    Pacote dado; //informação do nó
    NoPilha *prox; //próximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha()  //Construtor. Inicialização da pilha
    {
        topo = nullptr;
    }
};


bool vaziaP(Pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}


//push
bool empilhaP(Pilha *p, Pacote dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo nó
    if (novo == NULL) /// sistema não conseguiu alocar a memória
        return false;

    novo->dado = dado; //armazena a informação no nó
    novo->prox = p->topo; //o próximo elemento do nó criado será o último elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o nó criado.
    return true;
}

//pop
Pacote desempilhaP(Pilha *p)
{
    Pacote dado;

    // se não estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no nó do topo
        NoPilha *apagar = p->topo; //guarda o nó do topo em uma variável auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o próximo elemento;

        delete apagar;  /// libera a memória
    }

    return dado;
}

//peek
Pacote espiaP(Pilha* p)
{
    Pacote dado;

    if (vaziaP(p) == false)
        dado = p->topo->dado;

    return dado;
}


void mostraP(Pilha *p, string nome="")
{

    cout << "Pilha topo: ";
    if(vaziaP(p) == false)
    {
        //cout << "------------" << endl;
        NoPilha *no = p->topo;
        cout << "{";
        while (no != NULL)
        {
            cout << "[";
            cout << "cod=" << no->dado.codigo << ", peso="<<no->dado.peso;
            cout << "]";
            no = no->prox;

            if(no != NULL) //verifica se o pr�ximo n� n�o � nulo (no != NULL)
                cout << ", ";
        }
        cout << "} base"<<endl;
    }
    else
    {
        cout << "{} base" <<endl;
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor não existe na pilha
bool buscaP(Pilha *p, int cod1, int cod2)
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if((no->dado.codigo == cod1) and (no->prox->dado.codigo))
            return true;

        no = no->prox;
    }

    return false;

}

void destroiP(Pilha *p)
{
    Pacote dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}

#endif // _HPP_PILHA_DINAMICA





