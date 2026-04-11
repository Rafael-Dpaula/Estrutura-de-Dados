#include <iostream>
using namespace std;
#include "../exemplo-fila-dinamica/fila-dinamica.hpp"

void separaF(int val, Fila *f1, Fila *f2)
{
    Fila aux;
    while (f1->inicio->dado != val)
        enfileiraF(&aux, desenfileiraF(f1));
    enfileiraF(&aux, desenfileiraF(f1));

    while (!vaziaF(f1))
        enfileiraF(f2, desenfileiraF(f1));

    while (!vaziaF(&aux))
        enfileiraF(f1, desenfileiraF(&aux));
}

int main()
{
    Fila f, f2;
    int val;
    for (int i = 1; i < 10; i++)
    {
        enfileiraF(&f, i);
    }

    mostraF(&f);
    mostraF(&f2);
    cout << "Informe o valor de separação: ";
    cin >> val;
    separaF(val, &f, &f2);
    mostraF(&f);
    mostraF(&f2);

    EXIT_SUCCESS;
}