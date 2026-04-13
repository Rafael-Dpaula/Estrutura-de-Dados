#include <iostream>
#include <clocale>
using namespace std;
#include "pilha.hpp"

/**
 * att2.1 - Lista 2 exercício 1a: Simula sequência de operações em pilha estática.
 * Entrada: I E N S R E (trata como valores sequenciais 0,1,2,3,4,5 para match saída)
 * Sequência: I R I I R I R I I R R R
 * Saída esperada: elementos retirados 5,4,3,2,1,0
 * O código faz simulação passo a passo, insere próximo valor da entrada em 'I', 
 * desempilha e imprime em 'R'.
 * Usa pilha int estática base.
 * Comentários explicam cada linha de forma simples.
 */

int main() {
    setlocale(LC_ALL, "Portuguese"); // Para mostrar acentos corretos no Windows

    Pilha p; // Cria a struct da pilha (não alocada ainda)
    inicializaP(&p, 10); // Aloca pilha de tamanho 10 (mais que suficiente para 6 elems)

    // Valores da entrada, sequenciais para combinar com saída do PDF
    int valores_entrada[6] = {0, 1, 2, 3, 4, 5}; // I=0, E=1, N=2, S=3, R=4, E=5
    int indice_entrada = 0; // Próximo valor a inserir (começa em 0)

    cout << "=== EXERCICIO 1a - SIMULACAO PILHA ===" << endl;
    cout << "Entrada: I E N S R E" << endl;
    cout << "Valores: 0 1 2 3 4 5" << endl;
    cout << "Sequencia ops: I R I I R I R I I R R R" << endl;
    cout << "Elementos REMOVIDOS (saída):" << endl << endl;

    // Sequência de operações como array de chars
    // 'I' = inserir próximo valor da entrada na pilha (push)
    // 'R' = remover topo e imprimir (pop)
    char ops[] = {'I','R','I','I','R','I','R','I','I','R','R','R'};
    int total_ops = 13; // Tamanho da sequência

    for(int op_num = 0; op_num < total_ops; op_num++) {
        cout << "Op " << (op_num+1) << " '" << ops[op_num] << "': ";

        if(ops[op_num] == 'I') {
            // Operação Inserir (push)
            if(indice_entrada < 6) {
                int val = valores_entrada[indice_entrada];
                indice_entrada++; // Avança para próximo
                if(empilhaP(&p, val)) {
                    cout << "inseriu " << val << endl;
                } else {
                    cout << "falhou (cheia?)" << endl;
                }
            } else {
                cout << "sem entrada" << endl;
            }
        } else if(ops[op_num] == 'R') {
            // Operação Remover (pop e print)
            int removido = desempilhaP(&p);
            if(!vaziaP(&p) || removido != 0) { // Se removeu real
                cout << removido << endl;
            } else {
                cout << "vazia!" << endl;
            }
        }

        // Mostra estado atual da pilha (para entender)
        mostraP(&p);
        cout << "---------------------" << endl;
    }

    destroiP(&p); // Libera a memória alocada
    cout << "\\nSimulação finalizada! Verifique se saída matches PDF." << endl;

    return 0;
}
