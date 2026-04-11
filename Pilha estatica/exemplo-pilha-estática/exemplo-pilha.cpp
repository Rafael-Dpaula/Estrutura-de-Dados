#include <iostream>
using namespace std;

#include "pilha.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int tamPilha, valor;
    bool resultado;


    cout << "Informe o tamanho da pilha: ";
    cin >> tamPilha;
    inicializaP(&p1, tamPilha);


    cout << "\n\n###TESTE 1\n";
    //empilhando o valor 100
    valor = 100;
    resultado = empilhaP(&p1, valor);
    if(resultado == true)
        cout << "O valor " << valor << " foi empilhado com sucesso!\n";
    else
        cout << "Não foi possível empilhar o valor " << valor <<"!\n";

    //empilhando o valor 30
    valor = 30;
    if(empilhaP(&p1, valor) == true )
        cout << "O valor " << valor << " foi empilhado com sucesso!\n";
    else
        cout << "Não foi possível empilhar o valor " << valor <<"!\n";


    //mostra a pilha
    mostraP(&p1);




    system("pause");
    cout << "\n\n###TESTE 2\n";
    cout << "Empilhar os valors 300, 40, 50 e 90\n";
    empilhaP(&p1, 300);
    empilhaP(&p1, 40);
    empilhaP(&p1, 50);
    empilhaP(&p1, 90);




    //mostra a pilha
    mostraP(&p1);

    //verificando se a pilha está cheia
    if(cheiaP(&p1) == true)
        cout << "A pilha está cheia!\n";
    else
        cout << "A pilha NÃO está cheia!\n";


    //verificando se a pilha está vazia
    if(vaziaP(&p1) == true)
        cout << "A pilha está vazia!\n";
    else
        cout << "A pilha NÃO está vazia!\n";


    system("pause");
    cout << "\n\n###TESTE 3\n";
    //desempilhar
    if(vaziaP(&p1) == false)
    {
        valor = espiaP(&p1);
        cout << "O valor no topo da pilha é " << valor << endl;
    }
    else
        cout << "Não foi possivel consultar o valor no topo da pilha, a pilha está vazia!\n";

    mostraP(&p1);


    system("pause");
    cout << "\n\n###TESTE 4\n";
    cout << "Informe um valor para buscar na pilha:";
    cin >> valor;

    //desempilhar
    if(buscaP(&p1, valor) == true)
        cout << "O valor " << valor << " foi encontrado na pilha!\n";
    else
        cout << "O valor " << valor << " NÃO foi encontrado na pilha!\n";



    system("pause");
    cout << "\n\n###TESTE 5\n";
    //desempilhar

    if(vaziaP(&p1) == false)
    {
        valor = desempilhaP(&p1);
        cout << "O valor desempilhado é " << valor << endl;
    }
    else
        cout << "Não foi possivel desempilhar, a pilha está vazia!\n";

    mostraP(&p1);







    system("pause");
    cout << "\n\n###TESTE 6\n";

    while(vaziaP(&p1)== false)
    {
        valor = desempilhaP(&p1);
        cout << "O valor desempilhado é " << valor << endl;
    }
    mostraP(&p1);


    //verificando se a pilha está cheia
    if(cheiaP(&p1)== true)
        cout << "A pilha está cheia!\n";
    else
        cout << "A pilha NÃO está cheia!\n";


    //verificando se a pilha está vazia
    if(vaziaP(&p1) == true)
        cout << "A pilha está vazia!\n";
    else
        cout << "A pilha NÃO está vazia!\n";

    //desalocar memória
    destroiP(&p1);


    return EXIT_SUCCESS;

}//final do main

