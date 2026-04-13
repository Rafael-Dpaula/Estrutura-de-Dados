#include <iostream>
#include <iomanip>
#include <locale>
#include "fila-dinamica.hpp"
using namespace std;

void trocar(Fila *f) {
    // Troca primeira metade com segunda metade da fila, mantendo ordem interna
    // Elemento central fica se ímpar
    // Usa apenas filas aux
    
    if (vaziaF(f)) return;
    
    int tam = 0;
    NoFila *no = f->inicio;
    while (no != nullptr) {
        tam++;
        no = no->prox;
    }
    
    int metade = tam / 2;
    
    Fila primeira_metade, segunda_metade, aux;
    
    // Extrai primeira metade
    for (int i = 0; i < metade; i++) {
        enfileiraF(&primeira_metade, desenfileiraF(f));
    }
    
    // Segunda metade vai para segunda_metade
    while (!vaziaF(f)) {
        enfileiraF(&segunda_metade, desenfileiraF(f));
    }
    
    // Reconstrói: segunda + primeira (reverse ordem? Não, ordem relativa)
    // Para manter ordem, precisa inverter porque desempilhou invertido? Não fila é FIFO
    // primeira_metade tem primeira em ordem
    // segunda tem segunda em ordem
    
    // f = segunda_metade + primeira_metade
    while (!vaziaF(&segunda_metade)) {
        enfileiraF(f, desenfileiraF(&segunda_metade));
    }
    while (!vaziaF(&primeira_metade)) {
        enfileiraF(f, desenfileiraF(&primeira_metade));
    }
    
    destroiF(&primeira_metade);
    destroiF(&segunda_metade);
}

int main(void){
    setlocale(LC_ALL, "Portuguese"); 
    Fila fila; 
 
    cout << "\n#Teste 1\n"; 
    enfileiraF(&fila, Pessoa("Fulano1", 1000)); 
    enfileiraF(&fila, Pessoa("Fulano2", 2000)); 
    enfileiraF(&fila, Pessoa("Fulano3", 3000)); 
    enfileiraF(&fila, Pessoa("Fulano4", 4000)); 
    enfileiraF(&fila, Pessoa("Fulano5", 5000)); 
    mostraF(&fila); 
    trocar(&fila); 
    mostraF(&fila); 
 
    cout << "\n#Teste 2\n"; 
    destroiF(&fila); 
    enfileiraF(&fila, Pessoa("Fulano1", 1000)); 
    enfileiraF(&fila, Pessoa("Fulano2", 2000)); 
    enfileiraF(&fila, Pessoa("Fulano3", 3000)); 
    enfileiraF(&fila, Pessoa("Fulano4", 4000)); 
    mostraF(&fila); 
    trocar(&fila); 
    mostraF(&fila); 
 
    destroiF(&fila); 
    return 0; 
}

