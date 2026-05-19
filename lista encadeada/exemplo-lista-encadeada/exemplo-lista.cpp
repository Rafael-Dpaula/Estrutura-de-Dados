#include <iostream>
using namespace std;

#include "lista.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor; //valor deve ser do mesmo tipo de DadoNoLista (lista.hpp)
    No* aux; //usado na busca
    No* lista; //evite usar "list", pois é uma palavra reservada

    inicializaL(&lista);

    cout << "\n\n###TESTE 1\n";
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 40);
    mostraL(&lista);


    cout << "\n\n###TESTE 2\n";
    if(vaziaL(&lista) == true)
        cout << "A lista está vazia\n";
    else
        cout << "A lista NÃO está vazia\n";


    cout << "\n\n###TESTE 3\n";
    cout << "remover o nó com o valor 40, o primeiro elemento (no início da lista)\n";
    removeL(&lista, 40);
    mostraL(&lista);


    cout << "\n\n###TESTE 4\n";
    cout << "podemos verificar se a remoção foi realizado com sucesso (se o elemento foi encontrado)\n";
    if(removeL(&lista, 20) == true)
        cout << "O valor 20 foi removido da lista!\n";
    else
        cout << "O valor 20 não foi encontrado!\n";
    mostraL(&lista);

    cout << "\n\n###TESTE 5\n";
    cout << "Ler o valor do primeiro nó da lista SEM remover o nó\n";
    if(vaziaL(&lista) == false)
    {
        valor = leInicioL(&lista);

        cout << "O valor do primeiro nó é: " << valor << endl;

    }
    mostraL(&lista);


    cout << "\n\n###TESTE 6\n";
    cout << "Ler o valor do primeiro nó da lista e REMOVER o nó\n";
    if(vaziaL(&lista) == false)
    {
        valor = removeInicioL(&lista);

        cout << "O valor do primeiro nó é: " << valor << endl;

    }
    mostraL(&lista);


    cout << "\n\n###TESTE 7\n";
    aux = buscaL(&lista, 30);
    if(aux != NULL)
        cout << "Um nó com o valor 30 foi encontrado: " << aux->dado << "\n";
    else
        cout << "O valor 30 não foi entrado na lista\n";


    cout << "\n\n###TESTE 8\n";
    aux = buscaL(&lista, 10);
    if(aux != NULL)
        cout << "Um nó com o valor 10 foi encontrado: " << aux->dado << "\n";
    else
        cout << "O valor 10 não foi entrado na lista\n";


    destroiL(&lista);
    return EXIT_SUCCESS;


}//final do main

