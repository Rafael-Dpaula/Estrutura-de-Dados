#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    int valor;
    bool resultado;


   cout << "\n\n###TESTE 1\n";

    mostraF(&f1);

    valor = 5;
    resultado = enfileiraF(&f1, valor);
    if(resultado == true)
        cout << "\nO valor " << valor << " foi enfileirado com sucesso!\n";

    valor = 6;
    resultado = enfileiraF(&f1, valor);
    if(resultado == true)
        cout << "O valor " << valor << " foi enfileirado com sucesso!\n";

    valor = 7;
    resultado = enfileiraF(&f1, valor);
    if(resultado == true)
        cout << "O valor " << valor << " foi enfileirado com sucesso!\n";

    mostraF(&f1);

    cout << "\n\n###TESTE 2\n";

    valor = desenfileiraF(&f1);
    cout << "O valor " << valor << " foi desenfileirado com sucesso!\n";

    valor = desenfileiraF(&f1);
    cout << "O valor " << valor << " foi desenfileirado com sucesso!\n";

    valor = 10;
    resultado = enfileiraF(&f1, valor);
    if(resultado)
        cout << "O valor " << valor << " foi enfileirado com sucesso!\n";

    mostraF(&f1);


    cout << "\n\n###TESTE 3\n";

	if(vaziaF(&f1) == false)
    {
        valor = espiaF(&f1);
        cout << "O valor no início da fila é " << valor << endl;
    }
    else
        cout << "Não foi possivel consultar o valor na fila, pois a fila está vazia!\n";


    mostraF(&f1);


    cout << "\n\n###TESTE 4\n";
    valor = 50;
    if(buscaF(&f1, valor) == true)
        cout << "O valor " << valor << " foi encontrado na fila!\n";
    else
        cout << "O valor " << valor << " NÃO foi encontrado na fila!\n";

    valor = 10;
    if(buscaF(&f1, valor) == true)
        cout << "O valor " << valor << " foi encontrado na fila!\n";
    else
        cout << "O valor " << valor << " NÃO foi encontrado na fila!\n";

    mostraF(&f1);


    cout << "\n\n###TESTE 5\n";
	
	if(vaziaF(&f1) == false)
    {
		valor = desenfileiraF(&f1);
		cout << "O valor " << valor << " foi desenfileirado com sucesso!\n";
	}
	else
		cout << "Fila vazia! Não foi possível retirar um elemento da fila!\n";

    
	if(vaziaF(&f1) == false)
    {
		valor = desenfileiraF(&f1);
		cout << "O valor " << valor << " foi desenfileirado com sucesso!\n";
	}
	else
		cout << "Fila vazia! Não foi possível retirar um elemento da fila!\n";
	
	
	if(vaziaF(&f1) == false)
    {
		valor = desenfileiraF(&f1);
		cout << "O valor " << valor << " foi desenfileirado com sucesso!\n";
	}
	else
		cout << "Fila vazia! Não foi possível retirar um elemento da fila!\n";

    

    mostraF(&f1);


    cout << "\n\n###FIM\n";

    destroiF(&f1);

    return EXIT_SUCCESS;

}//final do main

