#include <iostream>
#include <clocale>
#include <cstdlib>
using namespace std;
#include "../exemplo-fila-dinamica/fila-dinamica.hpp"
#include "../../Pilha Dinamica/pilha-dinamica.hpp"



int main()
{
    setlocale(LC_ALL, "Portuguese"); // Configura o idioma para português brasileiro para acentos
    Fila f; // Declara a fila dinâmica
    int op; // Opção do menu

    do { // Loop do menu principal, repete até escolher sair (0)
        cout << "===== MENU FILA DINAMICA =====" << endl;
        cout << "1 - Incluir valor na fila (enfileirar)" << endl;
        cout << "2 - Remover valor da fila (desenfileirar)" << endl;
        cout << "3 - Mostrar a fila atual" << endl;
        cout << "4 - Inverter a ordem da fila usando pilha" << endl;
        cout << "0 - Sair do programa" << endl << endl;
        cout << "Digite sua opcao: ";
        cin >> op;

        switch (op)
        {
        case 0:
        {
            cout << "ALERT: encerrando programa." << endl;
            return 0;
            break;
        }
        case 1:
        {
            // Lê um valor inteiro do usuário e adiciona no final da fila (enfileira)
            // A fila dinâmica cresce automaticamente conforme necessário
            cout << "Informe o valor para adicionar na fila: ";
            int val;
            cin >> val;
            if (enfileiraF(&f, val)) {
                cout << "Valor " << val << " adicionado com sucesso na fila!" << endl;
            } else {
                cout << "Erro ao adicionar valor (fila pode estar com problema de memória)." << endl;
            }
            break;
        }
        case 2:
        {
            // Remove o valor do início da fila (frente) e mostra qual foi removido
            // Se fila vazia, desenfileiraF tipicamente retorna 0 ou valor padrão
            int sai = desenfileiraF(&f);
            if (vaziaF(&f) == false || sai != 0) { // Verifica se removeu algo válido
                cout << "Valor " << sai << " removido do início da fila!" << endl;
            } else {
                cout << "Erro: Fila vazia, nada para remover!" << endl;
            }
            break;
        }
        case 3:
        {
            // Mostra todos os elementos da fila do início ao fim
            // Formato típico: início -> [val1, val2, ...] <- fim
            if (vaziaF(&f)) {
                cout << "A fila está vazia!" << endl;
            } else {
                mostraF(&f);
            }
            break;
        }
        case 4:
        {
            // Inverte a fila usando uma pilha dinâmica auxiliar
            // Passo 1: Desenfileira tudo da fila e empilha na pilha (inverte ordem)
            // Passo 2: Desempilha da pilha e enfileira na fila (inverte novamente, resultado fila original invertida)
            cout << "Invertendo a fila..." << endl;
            if (vaziaF(&f)) {
                cout << "Fila vazia, nada a inverter!" << endl;
            } else {
                Pilha p; // Pilha auxiliar dinâmica
                while (!vaziaF(&f)) // Transfere fila -> pilha
                {
                    empilhaP(&p, desenfileiraF(&f));
                }
                while (!vaziaP(&p)) // Transfere pilha -> fila
                {
                    enfileiraF(&f, desempilhaP(&p));
                }
                cout << "Fila invertida com sucesso!" << endl;
            }
            break;
        }
        default:
        {
            // Caso o usuário digite opção inválida, mostra erro e continua no loop
            cout << "Erro: Opção inválida! Digite um número entre 0 e 4." << endl;
            break;
        }
        }
    }

        cout << endl << endl;
    } while(op != 0); // Continua enquanto não for 0

    destroiF(&f); // Libera a memória da fila antes de sair
    return 0;
}
