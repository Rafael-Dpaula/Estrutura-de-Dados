#include <iostream>
using namespace std;
#include "../pilha-dinamica.hpp"

void ordena(Pilha *entrada) {
    Pilha ord, aux;
    
    // Processa cada elemento da pilha de entrada
    while (!vaziaP(entrada)) {
        int valor = desempilhaP(entrada);
        
        // Move elementos de ORD para AUX enquanto forem maiores que valor (encontra posição)
        while (!vaziaP(&ord) && espiaP(&ord) > valor) {
            empilhaP(&aux, desempilhaP(&ord));
        }
        
        // Insere o valor em ORD (agora no lugar correto)
        empilhaP(&ord, valor);
        
        // Move de volta de AUX para ORD (restaura ordem)
        while (!vaziaP(&aux)) {
            empilhaP(&ord, desempilhaP(&aux));
        }
    }
    
    // Copia resultado de ORD de volta para entrada (mantém interface original)
    while (!vaziaP(&ord)) {
        empilhaP(entrada, desempilhaP(&ord));
    }
    
    mostraP(entrada, "ORD (ordenada)");
    cout << endl << endl;
    
    destroiP(&aux);
}

int main() {
    cout << "Quantos valores deseja inserir na pilha? ";
    int qtd;
    cin >> qtd;

    Pilha p;
    for (int i = 0; i < qtd; i++) {
        cout << "Informe o valor " << i + 1 << " a ser adicionado a pilha: ";
        int val;
        cin >> val;
        empilhaP(&p, val);
    }

    ordena(&p);

    return EXIT_SUCCESS;
}
