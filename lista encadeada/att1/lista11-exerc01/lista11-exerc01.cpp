#include <iostream>
using namespace std;

#include "lista.hpp"

//passo 1: encontrar o primeiro n� que possui o valor par

//passo 2: criar o novo n�

//passo 3: ligar os ponteiros

//Aten��o:
//-lista vazia
//-lista sem elementos pares

void insereAposPrimeiroPar(No** lista, int valor)
{
    No *atual = *lista;
    while(atual!=NULL && atual->dado%2 != 0)
        atual = atual->prox;

    if(atual!=NULL) //se atual==NULL, a lita est� vazis ou n�o possui par
    {
        No *novo = new No(); // aloca mem�ria para o n�
        if (novo == NULL)
            return;

        novo->dado = valor;
        novo->prox= atual->prox;
        atual->prox = novo;
    }

}
void insereAntesPrimeiroPar(No**lista, int valor)
{

    No *atual = *lista;
    No *ant = NULL;
    while(atual!=NULL && atual->dado%2 != 0)
    {
        ant = atual;
        atual = atual->prox;
    }
    if(atual!=NULL) //se atual==NULL, a lita est� vazia ou n�o possui par
    {
        No *novo = new No(); // aloca mem�ria para o n�
        if (novo == NULL)
            return;
        novo->dado = valor;

        if(!ant) // if(ant==NULL)
        {
            novo->prox = *lista;
            *lista = novo;
        }
        else
        {
            ant->prox = novo;
            novo->prox = atual;
        }
    }
}


bool igualL(No **lista1, No **lista2)
{

    No *n1 = *lista1;
    No *n2 = *lista2;
    while(n1!=NULL && n2!=NULL)
    {
        if(n1->dado != n2->dado)
            return false;

        n1 = n1->prox;
        n2 = n2->prox;
    }

    if(n1!=NULL ||  n2!=NULL)
        return false;


    return true;
}

void insereFinalL(No **lista, int valor)
{
    No *n = *lista;
    while(n!=NULL && n->prox!= NULL)
        n = n->prox;


    No *novo = new No(); // aloca mem�ria para o n�
    if (novo == NULL)
        return;
    novo->dado = valor;
    novo->prox =  NULL;

    if(n!=NULL)
        n->prox = novo;
    else
        *lista = novo;

}

int leFinalL(No **lista)
{
    No *n = *lista;
    while(n!=NULL && n->prox!= NULL)
        n = n->prox;


    if(n!=NULL)
        return n->dado;
    else
        return 0;

}



int removeFinalL(No **lista)
{
    No *atual = *lista;
    No *ant = NULL;
    int dadoRetorno = 0;
    while(atual!=NULL && atual->prox!= NULL)
    {
        ant = atual;
        atual = atual->prox;
    }

    if(ant!=NULL)
        ant->prox = NULL;
    else
        *lista = NULL;

    if(atual != NULL)
    {
        dadoRetorno = atual->dado;
        delete atual;
    }

    return dadoRetorno;

}


int lePosicao(No **lista, int posicao)
{
    int cont = 0;
    No *n = *lista;
    while(n!=NULL && cont<posicao)
    {
        n = n->prox;
        cont++;
    }

    if(n!=NULL)
        return n->dado;
    else
        return 0;
}


void insereAposCadaPar(No **lista, int valor)
{
    No *atual = *lista;
    while(atual!=NULL)
    {
         if(atual->dado%2 == 0)
         {
             No *novo = new No(); // aloca mem�ria para o n�
            if (novo == NULL)
                return;

            novo->dado = valor;
            novo->prox= atual->prox;
            atual->prox = novo;

            atual =  novo; // IMPORTANTE
         }
         atual = atual->prox;
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int dado;
    No *lista, *lista2; //evite usar "list", pois � uma palavra reservada


    cout <<"\n##Teste 1\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 1);
    mostraL(&lista);
    insereAposPrimeiroPar(&lista, 200);
    mostraL(&lista);
    destroiL(&lista);


    cout <<"\n##Teste 2\n";
    inicializaL(&lista);
    mostraL(&lista);
    insereAposPrimeiroPar(&lista, 200);
    mostraL(&lista);
    destroiL(&lista);


    cout <<"\n##Teste 3\n";
    inicializaL(&lista);
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    mostraL(&lista);
    insereAposPrimeiroPar(&lista, 200);
    mostraL(&lista);
    destroiL(&lista);


    cout <<"\n##Teste 4\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 1);
    mostraL(&lista);
    insereAntesPrimeiroPar(&lista, 200);
    mostraL(&lista);
    destroiL(&lista);


    cout <<"\n##Teste 5\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 10);
    mostraL(&lista);
    insereAntesPrimeiroPar(&lista, 200);
    mostraL(&lista);
    destroiL(&lista);



    cout <<"\n##Teste 6\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);
    mostraL(&lista);
    insereAntesPrimeiroPar(&lista, 200);
    mostraL(&lista);
    destroiL(&lista);



    cout <<"\n##Teste 7\n";
    inicializaL(&lista);
    inicializaL(&lista2);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);

    insereInicioL(&lista2, 3);
    insereInicioL(&lista2, 1);
    insereInicioL(&lista2, 5);
    mostraL(&lista);
    mostraL(&lista2);
    if(igualL(&lista, &lista2))
        cout << "As listas s�o iguais\n";
    else
        cout << "As listas n�o s�o iguais\n";
    destroiL(&lista);
    destroiL(&lista2);



    cout <<"\n##Teste 8\n";
    inicializaL(&lista);
    inicializaL(&lista2);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);

    insereInicioL(&lista2, 200);
    insereInicioL(&lista2, 3);
    insereInicioL(&lista2, 1);
    insereInicioL(&lista2, 5);
    mostraL(&lista);
    mostraL(&lista2);
    if(igualL(&lista, &lista2))
        cout << "As listas s�o iguais\n";
    else
        cout << "As listas n�o s�o iguais\n";
    destroiL(&lista);
    destroiL(&lista2);


    cout <<"\n##Teste 9\n";
    inicializaL(&lista);
    inicializaL(&lista2);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);

    insereInicioL(&lista2, 3);
    insereInicioL(&lista2, 2);
    insereInicioL(&lista2, 5);
    mostraL(&lista);
    mostraL(&lista2);
    if(igualL(&lista, &lista2))
        cout << "As listas s�o iguais\n";
    else
        cout << "As listas n�o s�o iguais\n";
    destroiL(&lista);
    destroiL(&lista2);



    cout <<"\n##Teste 10\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);
    mostraL(&lista);
    insereFinalL(&lista, 200);
    mostraL(&lista);
    destroiL(&lista);

    cout <<"\n##Teste 11\n";
    inicializaL(&lista);
    insereFinalL(&lista, 200);
    mostraL(&lista);
    destroiL(&lista);


    cout <<"\n##Teste 12\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);
    mostraL(&lista);
    cout << "leFinalL: " << leFinalL(&lista) << endl;
    destroiL(&lista);


    cout <<"\n##Teste 13\n";
    inicializaL(&lista);
    mostraL(&lista);
    cout << "leFinalL: " << leFinalL(&lista) << endl;
    destroiL(&lista);




    cout <<"\n##Teste 14\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);
    mostraL(&lista);
    dado = removeFinalL(&lista);
    cout << "Dado removido: " << dado << endl;
    mostraL(&lista);
    destroiL(&lista);


    cout <<"\n##Teste 15\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    mostraL(&lista);
    dado = removeFinalL(&lista);
    cout << "Dado removido: " << dado << endl;
    mostraL(&lista);
    destroiL(&lista);


    cout <<"\n##Teste 16\n";
    inicializaL(&lista);
    mostraL(&lista);
    dado = removeFinalL(&lista);
    cout << "Dado removido: " << dado << endl;
    mostraL(&lista);
    destroiL(&lista);



    cout <<"\n##Teste 17\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);
    mostraL(&lista);
    cout << "lePosicao(pos=0): " << lePosicao(&lista, 0) << endl;
    destroiL(&lista);
    
    cout <<"\n##Teste 17.1\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);
    mostraL(&lista);
    cout << "lePosicao(pos= -1): " << lePosicao(&lista, -1) << endl;
    destroiL(&lista);


    cout <<"\n##Teste 18\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);
    mostraL(&lista);
    cout << "lePosicao(pos=2): " << lePosicao(&lista, 2) << endl;
    destroiL(&lista);



    cout <<"\n##Teste 19\n";
    inicializaL(&lista);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 5);
    mostraL(&lista);
    cout << "lePosicao(pos=3): " << lePosicao(&lista, 3) << endl;
    destroiL(&lista);



    cout <<"\n##Teste 20\n";
    inicializaL(&lista);
    mostraL(&lista);
    cout << "lePosicao(pos=0): " << lePosicao(&lista, 0) << endl;
    destroiL(&lista);


    cout <<"\n##Teste 21\n";
    inicializaL(&lista);
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 1);
    mostraL(&lista);
    insereAposCadaPar(&lista, 200);
    mostraL(&lista);
    destroiL(&lista);


    cout <<"\n##Teste 22\n";
    inicializaL(&lista);
    insereInicioL(&lista, 7);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 9);
    insereInicioL(&lista, 1);
    mostraL(&lista);
    insereAposCadaPar(&lista, 200);
    mostraL(&lista);
    destroiL(&lista);

    return EXIT_SUCCESS;


}//final do main

