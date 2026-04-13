#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "../exemplo-fila-dinamica/fila-dinamica.hpp"


void concatenaF(Fila *f1, Fila *f2, Fila *fconcatenada){
    // Função para concatenar f1 + f2 em fconcatenada
    // Alterna elementos de f1 e f2 até uma esvaziar
    while(!vaziaF(f1) || !vaziaF(f2)){ // Continua enquanto pelo menos uma fila tem elementos
        if (!vaziaF(f1)) {
            enfileiraF(fconcatenada, desenfileiraF(f1)); // Pega da f1 se não vazia
        }
        if (!vaziaF(f2)) {
            enfileiraF(fconcatenada, desenfileiraF(f2)); // Pega da f2 se não vazia
        }
    }
    // Nota: f1 e f2 ficam vazias após chamada
}

int main(){
    srand(time(NULL)); // Semente para números aleatórios diferentes a cada execução
    Fila f1, f2, fconcat; // Declara três filas dinâmicas

    cout << "Gerando valores aleatórios para f1 e f2 (5 cada)..." << endl;
    for( int i = 0; i < 5; i++){
        enfileiraF(&f1, rand()%20 + 1); // Valores 1-20 aleatórios em f1
        enfileiraF(&f2, rand()%20 + 1); // Valores 1-20 aleatórios em f2
    }

    cout << "Fila f1 original: " << endl;
    mostraF(&f1);
    cout << "Fila f2 original: " << endl;
    mostraF(&f2);

    concatenaF(&f1, &f2, &fconcat); // Concatena alternando

    cout << "Fila concatenada (f1 + f2 alternados): " << endl;
    mostraF(&fconcat);

    destroiF(&f1); // Limpa memória
    destroiF(&f2);
    destroiF(&fconcat);

    return 0;
}
