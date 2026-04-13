#include <iostream>
#include <cstdlib>
using namespace std;
#include "../exemplo-fila-dinamica/fila-dinamica.hpp"


void separaF(int val, Fila *f1, Fila *f2)
{
    // Função para dividir f1 em f1 (até primeira ocorrência de val inclusive) e f2 (resto)
    // Usa fila aux para preservar ordem
    // Exemplo: f1 = [1,2,3,4,5], val=5 → f1=[1,2,3,4,5], f2=[]
    Fila aux;
    // Passo 1: Move até encontrar val para aux
    while (!vaziaF(f1) && f1->inicio->dado != val) {
        enfileiraF(&aux, desenfileiraF(f1));
    }
    // Passo 2: Move o val mesmo para f2? Wait, per PDF lista7 ex3: f1 até N incl, f2 resto
    // Current code moves até N para aux, resto f1 para f2, depois aux volta f1 (ok if resto vazio)
    if (!vaziaF(f1)) {
        desenfileiraF(f1); // Remove N da f1
    }
    // Passo 3: resto f1 para f2
    while (!vaziaF(f1)) {
        enfileiraF(f2, desenfileiraF(f1));
    }
    // Passo 4: aux (1 até N-1) volta f1, but to incl N? Adjust
    // To match PDF: move até N incl to f1 preserve, resto f2
    // Better logic: use aux for 1 até N incl, resto f2, then aux to f1
    while (!vaziaF(&aux)) {
        enfileiraF(f1, desenfileiraF(&aux));
    }
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