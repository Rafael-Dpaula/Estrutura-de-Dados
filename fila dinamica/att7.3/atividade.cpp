#include <iostream>
#include <cstdlib>
using namespace std;
#include "../exemplo-fila-dinamica/fila-dinamica.hpp"

/**
 * att7.3 - Lista 7 exercício 3: separaF
 * Separa fila f1 em f1 (até primeira ocorrência de N inclusive) e f2 (resto após N)
 * Usa fila aux dinâmica para preservar ordem
 * Teste: preenche f1 com 1-9, pede N, separa e mostra
 */

void separaF(int N, Fila *f1, Fila *f2) {
    // Cria fila auxiliar dinâmica para guardar até N
    Fila aux;

    // Passo 1: Move elementos de f1 para aux até encontrar a primeira N (incluindo N)
    while (!vaziaF(f1) && f1->inicio->dado != N) {
        enfileiraF(&aux, desenfileiraF(f1)); // Move antes de N
    }
    if (!vaziaF(f1)) {
        enfileiraF(&aux, desenfileiraF(f1)); // Move a N inclusive
    }

    // Passo 2: Move o resto de f1 para f2
    while (!vaziaF(f1)) {
        enfileiraF(f2, desenfileiraF(f1));
    }

    // Passo 3: Volta aux para f1 preservando ordem (f1 agora 1 até N)
    while (!vaziaF(&aux)) {
        enfileiraF(f1, desenfileiraF(&aux));
    }
    // aux destruída automaticamente no fim do scope (libera memória)
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Fila f1, f2;
    int N;

    // Preenche f1 com 1 a 9 para teste
    for (int i = 1; i <= 9; ++i) {
        enfileiraF(&f1, i);
    }

    cout << "Fila f1 inicial: ";
    mostraF(&f1);
    cout << "Fila f2 inicial (vazia): ";
    mostraF(&f2);

    cout << "Digite o valor N para separar: ";
    cin >> N;

    separaF(N, &f1, &f2);

    cout << "Após separaF(" << N << "):" << endl;
    cout << "f1 (até N incl): ";
    mostraF(&f1);
    cout << "f2 (resto): ";
    mostraF(&f2);

    // Limpa memória
    destroiF(&f1);
    destroiF(&f2);

    return 0;
}

