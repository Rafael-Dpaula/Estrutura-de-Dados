#include <iostream>
#include <locale>
#include "pilha.hpp"
using namespace std;

void repetidos(Pilha *P, Pilha *R) {
    // Encontra valores repetidos em P e coloca em R (sem duplicatas em R)
    // P permanece inalterada
    // Usa pilha aux para copiar P sem modificar
    
    Pilha aux;
    aux = *P; // Copia (simples para static)
    
    // Pilha para rastrear vistos
    bool vistos[1000] = {false}; // Assume valores <1000
    
    while (!vaziaP(&aux)) {
        int val = desempilhaP(&aux);
        if (vistos[val]) {
            // Repetido, empilha em R se não já em R
            if (!buscaP(R, val)) {
                empilhaP(R, val);
            }
        } else {
            vistos[val] = true;
        }
    }
    destroiP(&aux); // Nota: ajustar para static
}

bool buscaP(Pilha *p, int valor) {
    for (int i = p->topo; i >= 0; i--) {
        if (p->dados[i] == valor) return true;
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Pilha P;
    inicializaP(&P);
    
    // Exemplo do PDF: topo 1 4 3 8 4 0 7 6 7 5 7 9 8 base
    int exemplo[] = {1,4,3,8,4,0,7,6,7,5,7,9,8};
    for (int i = 0; i < 13; i++) {
        empilhaP(&P, exemplo[i]);
    }
    
    Pilha R;
    inicializaP(&R);
    
    cout << "Pilha P antes:" << endl;
    mostraP(&P);
    
    repetidos(&P, &R);
    
    cout << "Pilha R repetidos:" << endl;
    mostraP(&R);
    
    cout << "Pilha P depois (inalterada):" << endl;
    mostraP(&P);
    
    destroiP(&P);
    destroiP(&R);
    
    return 0;
}

