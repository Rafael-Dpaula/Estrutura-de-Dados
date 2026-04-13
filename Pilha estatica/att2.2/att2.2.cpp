#include <iostream>
#include <clocale>
using namespace std;
#include "pilha.hpp"

/**
 * att2.2 - Lista 2 exercício 1b: Simula sequência de operações em pilha estática.
 * Entrada: A, B, C, D, E, F (trata como 0,1,2,3,4,5 para match saída PDF)
 * Sequência: I I R I I R I R R I R R 
 * Saída esperada: elementos retirados 5 4 3 2 1 0
 * Simulação passo a passo igual att2.1.
 * Comentários simples PT-BR.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha p;
    inicializaP(&p, 10);

    int valores_entrada[6] = {0, 1, 2, 3, 4, 5}; // A=0 B=1 C=2 D=3 E=4 F=5
    int indice_entrada = 0;

    cout << "=== EXERCICIO 1b - SIMULACAO PILHA ===" << endl;
    cout << "Entrada: A B C D E F" << endl;
    cout << "Valores: 0 1 2 3 4 5" << endl;
    cout << "Sequencia: I I R I I R I R R I R R" << endl;
    cout << "REMOVIDOS:" << endl << endl;

    char ops[] = {'I','I','R','I','I','R','I','R','R','I','R','R'};
    int total_ops = 12;

    for(int op_num = 0; op_num < total_ops; op_num++) {
        cout << "Op " << (op_num+1) << " '" << ops[op_num] << "': ";

        if(ops[op_num] == 'I') {
            if(indice_entrada < 6) {
                int val = valores_entrada[indice_entrada++];
                if(empilhaP(&p, val)) {
                    cout << "inseriu " << val << endl;
                } else {
                    cout << "falhou" << endl;
                }
            } else {
                cout << "sem entrada" << endl;
            }
        } else if(ops[op_num] == 'R') {
            int removido = desempilhaP(&p);
            if(!vaziaP(&p) || removido != 0) {
                cout << removido << endl;
            } else {
                cout << "vazia" << endl;
            }
        }

        mostraP(&p);
        cout << "---------------------" << endl;
    }

    destroiP(&p);
    cout << "Concluído!" << endl;

    return 0;
}

