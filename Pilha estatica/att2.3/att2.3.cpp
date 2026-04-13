#include <iostream>
#include <clocale>
using namespace std;
#include "pilha.hpp"

/**
 * att2.3 - Lista 2 exercícios 2 e 3: Pilha estática.
 * Ex3: Conjunto 7,20,6,15. Sequência para saída 20 15 6 7.
 * Sequência encontrada: I(7) I(20) R(20) I(6) I(15) R(15) R(6) R(7)
 * Ex2: Questão em branco no PDF, simulamos com mesmo.
 * Simula passo a passo, mostra removidos.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha p;
    inicializaP(&p, 10);

    int entrada[4] = {7, 20, 6, 15};
    int idx = 0;

    cout << "=== EXERCICIO 3 - SEQUENCIA PARA 20 15 6 7 ===" << endl;
    cout << "Entrada: 7, 20, 6, 15" << endl;
    cout << "Sequência: I I R I I R R R" << endl;
    cout << "Saída removidos: 20 15 6 7" << endl << endl;

    char ops[] = {'I','I','R','I','I','R','R','R'};
    int n_ops = 8;

    for(int i = 0; i < n_ops; i++) {
        cout << "Op " << (i+1) << ": ";

        if(ops[i] == 'I') {
            if(idx < 4) {
                int val = entrada[idx++];
                empilhaP(&p, val);
                cout << "I " << val << endl;
            }
        } else {
            int rem = desempilhaP(&p);
            cout << "R " << rem << endl;
        }
        mostraP(&p);
    }

    destroiP(&p);
    cout << "Ex3 OK. Ex2 (blank PDF) similar." << endl;

    return 0;
}

