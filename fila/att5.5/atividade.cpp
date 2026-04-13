#include <iostream>
#include <string>
using namespace std;

#include "filacirc-char.hpp"
#include "pilha-char.hpp"

// Ex5 lista5: Verifica se string é palíndromo usando fila + pilha
// Insere cada char nas duas estruturas
// Compara desenfileira (fila) == desempilha (pilha)
// Se todas iguais, é palíndromo
// Comentário PT-BR detalhado

int main() {
    setlocale(LC_ALL, "Portuguese");

    string frase;
    cout << "=== EXERCÍCIO 5 - PALÍNDROMO COM FILA + PILHA ===" << endl;
    cout << "Digite uma frase (sem espaços para simplicidade): ";
    cin >> frase;

    int tam = frase.length();
    FilaChar fila;
    PilhaChar pilha;
    inicializaFC(&fila, tam);
    inicializaPC(&pilha, tam);

    // Passo 1: Insere cada char na fila E na pilha
    cout << "Inserindo chars nas estruturas:" << endl;
    for (char c : frase) {
        enfileiraFC(&fila, c);
        empilhaPC(&pilha, c);
        cout << "'" << c << "' inserido." << endl;
    }

    // Passo 2: Compara retirando (fila preserva ordem, pilha inverte)
    bool ehPalindromo = true;
    cout << "\nComparando (fila vs pilha invertida):" << endl;
    for (int i = 0; i < tam; i++) {
        char daFila = desenfileiraFC(&fila);
        char daPilha = desempilhaPC(&pilha);
        cout << "Fila: '" << daFila << "' == Pilha: '" << daPilha << "' ? " << (daFila == daPilha ? "SIM" : "NÃO") << endl;
        if (daFila != daPilha) ehPalindromo = false;
    }

    // Resultado
    if (ehPalindromo) {
        cout << "\nA frase '" << frase << "' É PALÍNDROMO!" << endl;
    } else {
        cout << "\nA frase '" << frase << "' NÃO é palíndromo." << endl;
    }

    destroiFC(&fila);
    destroiPC(&pilha);
    return 0;
}

