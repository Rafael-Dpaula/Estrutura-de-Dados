#include<iostream>
using namespace std;
#include "../exemplo-fila-dinamica/fila-dinamica.hpp"

void concatenaF(Fila *f1, Fila *f2, Fila *fconcatenada){
    while(!vaziaF(f1) and !vaziaF(f1)){
        enfileiraF(fconcatenada, desenfileiraF(f1));
        enfileiraF(fconcatenada, desenfileiraF(f2));
    }
}

int main(){
    srand(time(NULL));
    Fila f1, f2, f;

    for( int i = 0; i < 5; i++){
        enfileiraF(&f1, rand()%20 + 1);
        enfileiraF(&f2, rand()%20 + 1);
    }

    mostraF(&f1);
    mostraF(&f2);
    concatenaF(&f1, &f2, &f);
    mostraF(&f);
    EXIT_SUCCESS;
}