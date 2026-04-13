#include <iostream>
#include <string>
#include <clocale>
using namespace std;
#include "pilha-cliente.hpp"

/**
 * att2.7 - Lista 2 exercício 7: buscaCliente na pilha Cliente.
 * Usa pilha do Ex6, adiciona bool buscaCliente(Pilha*, int codigo).
 * Menu para inserir alguns clientes e testar busca por codigo.
 */

bool pilhaCriada = false;
Pilha p;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int op, tam, cod, idad;
    string nom;
    Cliente c;

    cout << "=== PILHA CLIENTE COM BUSCA CODIGO ===" << endl;
    cout << "1-Criar e inserir exemplos 2-Buscar 3-Mostrar 4-Sair" << endl;

    do {
        cout << "\nOp: ";
        cin >> op;
        cin.ignore();

        switch(op) {
            case 1:
                if(pilhaCriada) destroiP(&p);
                cout << "Tamanho: ";
                cin >> tam;
                inicializaP(&p, tam);
                pilhaCriada = true;
                // Exemplos
                c = {1, "João", 25}; empilhaP(&p, c);
                c = {2, "Maria", 30}; empilhaP(&p, c);
                c = {3, "Pedro", 28}; empilhaP(&p, c);
                cout << "Criada com 3 exemplos!" << endl;
                break;

            case 2:
                if(!pilhaCriada) {
                    cout << "Crie primeiro!" << endl;
                } else {
                    cout << "Codigo: ";
                    cin >> cod;
                    if(buscaCliente(&p, cod)) {
                        cout << "Cliente com codigo " << cod << " existe!" << endl;
                    } else {
                        cout << "Não encontrado!" << endl;
                    }
                }
                break;

            case 3:
                if(pilhaCriada) mostraP(&p);
                break;

            case 4:
                if(pilhaCriada) destroiP(&p);
                break;

            default: cout << "Erro!" << endl;
        }
    } while(op != 4);

    return 0;
}

