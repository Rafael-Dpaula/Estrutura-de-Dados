#include <iostream>
using namespace std;
#include "../pilha-dinamica.hpp"

/**
 * att4.3 - Lista 4 exercício 3: Ordenar sequência inteiros com 2 pilhas ORD e AUX.
 * Regra: Nenhum item empilhado sobre outro menor (ORD descending: topo maior, base menor).
 * Lógica insertion sort simples:
 * 1. Enquanto entrada não vazia:
 *    - Pega valor = desempilha(entrada)
 *    - Move de ORD para AUX enquanto topo(ORD) > valor (acha posição)
 *    - Empilha valor em ORD
 *    - Move AUX de volta para ORD
 * 2. Usa só pilhas, sem vetores.
 * 3. Menu intuitivo PT-BR.
 */

void ordena(Pilha *entrada) {
    Pilha ord, aux;
    
    // Passo 1: Processa todos valores da entrada original
    while (!vaziaP(entrada)) {
        int valor = desempilhaP(entrada); // Remove topo entrada
        
        // Passo 2: Encontra posição correta em ORD (insertion)
        while (!vaziaP(&ord) && espiaP(&ord) > valor) {
            // Move maiores de ORD para AUX temp
            empilhaP(&aux, desempilhaP(&ord));
        }
        
        // Passo 3: Insere valor no lugar certo
        empilhaP(&ord, valor);
        
        // Passo 4: Restaura ORD de AUX
        while (!vaziaP(&aux)) {
            empilhaP(&ord, desempilhaP(&aux));
        }
    }
    
    // Passo 5: Copia resultado ordenado de volta para entrada (interface limpa)
    while (!vaziaP(&ord)) {
        empilhaP(entrada, desempilhaP(&ord)); // Nota: reverse aqui, mas como descending ok
    }
    
    mostraP(entrada, "Pilha ORD ordenada (topo maior)");
    cout << endl << endl;
    
    destroiP(&aux); // Limpa aux (ord já copiado)
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Acentos PT-BR
    
    cout << "=== ORDENAR PILHA COM ORD/AUX ===" << endl;
    cout << "Quantos valores deseja inserir? ";
    int qtd;
    cin >> qtd;
    cin.ignore(); // Limpa buffer
    
    Pilha p;
    
    for (int i = 0; i < qtd; i++) {
        cout << "Informe o valor " << (i + 1) << ": ";
        int val;
        cin >> val;
        empilhaP(&p, val);
    }
    
    cout << endl << "Pilha original:" << endl;
    mostraP(&p, "Original");
    
    ordena(&p);
    
    destroiP(&p);
    return 0;
}
