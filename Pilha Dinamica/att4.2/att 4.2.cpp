#include <iostream>
#include <string>
using namespace std;
#include "pilha.hpp"

/**
 * att4.2 - Lista 4 exercício 2: Inverter ordem das letras nas palavras de uma frase usando pilha.
 * Exemplo: "teste de pilha" -> "etset ed ahlip"
 * Lógica simples:
 * 1. Lê a frase inteira com getline (mantém espaços).
 * 2. Percorre cada char:
 *    - Se letra, empilha na pilha (topo vira última letra).
 *    - Se espaço ou fim, desempilha/printa todos até vazio (palavra invertida), printa espaço.
 * 3. Não usa vetores, só pilha dinâmica int (char cast to int ok).
 * 4. Menu intuitivo em PT-BR.
 */

void inverterFrase(Pilha *p) {
    // Passo 1: Pede frase ao usuário
    cout << "=== INVERTER PALAVRAS COM PILHA ===" << endl;
    cout << "Digite uma frase para inverter as palavras (ex: \"teste de pilha\"): " << endl;
    string frase;
    getline(cin, frase);

    // Passo 2: Percorre cada caractere da frase
    for (char c : frase) {
        if (c != ' ') {
            // Se é letra/espaço não, empilha o char (converte para int)
            empilhaP(p, (int)c);
        } else {
            // Se é espaço, desempilha e printa a palavra invertida
            while (!vaziaP(p)) {
                cout << (char)desempilhaP(p);
            }
            cout << " "; // Printa o espaço separador
        }
    }
    // Passo 3: Desempilha última palavra se não terminou com espaço
    while (!vaziaP(p)) {
        cout << (char)desempilhaP(p);
    }
    cout << endl << endl;
    cout << "=== FIM ===" << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura acentos PT-BR

    Pilha p; // Cria pilha vazia

    inverterFrase(&p); // Chama função principal

    destroiP(&p); // Limpa memória
    return 0;
}

