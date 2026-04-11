#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <string> //biblioteca usada para formatar a impressão da pilha
#include "Cadastro.hpp"

struct NoPilha
{
    Cadastro dado; //informação do nó
    NoPilha *prox; //próximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha(){ //Construtor. Inicialização da pilha
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
bool empilhaP(Pilha *p, Cadastro dado)
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
Cadastro desempilhaP(Pilha *p)
{
    Cadastro dado;

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
Cadastro espiaP(Pilha* p)
{
    Cadastro dado;

    if (vaziaP(p) == false)
        dado = p->topo->dado;

    return dado;
}


void mostraP(Pilha *p, string nome="")
{

    cout << "PILHA " << nome << ": " << endl;
    //cout << "TOPO: " << p->topo << endl;
    if(vaziaP(p) == false)
    {
        cout << "------------" << endl;
         NoPilha *no = p->topo;
        while (no != NULL)
        {

            cout  << no->dado.codigo << ", " << no->dado.nome << ", " << no->dado.idade <<", " << no->dado.saldo << endl;
            cout << "------------" << endl;

            no = no->prox;
        }
    }
    else
    {
        cout << "------------" << endl;
        cout << "VAZIA\n";
        cout << "------------" << endl;
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor não existe na pilha
bool buscaP(Pilha *p, int dado) //busca se tem o mesmo codigo
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == dado)
            return true;

        no = no->prox;
    }

    return false;

}

void destroiP(Pilha *p)
{
    Cadastro dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor não existe na pilha
Cadastro encontraP(Pilha *p, int codigo) //busca se tem o mesmo codigo
{
    Cadastro cli;
    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == codigo)
            return no->dado;

        no = no->prox;
    }
    return cli;
}

#endif // _HPP_PILHA_DINAMICA





