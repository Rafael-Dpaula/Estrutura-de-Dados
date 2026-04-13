#include <iostream>
#include <string>
#include <clocale>
using namespace std;
#include "pilha-string.hpp"

/**
 * att2.5 - Lista 2 exercício 5: Pilha estática para strings.
 * Modificada de int para string*.
 * Menu similar att2.4, mas com strings, sem duplicados.
 * Testa todas funções adaptadas.
 * Comentários simples PT-BR.
 */

bool pilhaCriada = false;
Pilha p;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao, tamanho;
    string valor;

    cout << "=== MENU PILHA STRING ===" << endl;
    cout << "1-Criar 2-Inserir 3-Remover 4-Consultar 5-Mostrar 6-Sair" << endl;

    do {
        cout << "\nOpção: ";
        cin >> opcao;
        cin.ignore(); // Limpa buffer para string

        switch(opcao) {
            case 1:
                if(pilhaCriada) destroiP(&p);
                cout << "Tamanho: ";
                cin >> tamanho;
                inicializaP(&p, tamanho);
                pilhaCriada = true;
                cout << "Criada!" << endl;
                break;

            case 2:
                if(!pilhaCriada || cheiaP(&p)) {
                    cout << "Erro: não criada ou cheia!" << endl;
                    break;
                }
                cout << "Valor string: ";
                getline(cin, valor);
                if(buscaP(&p, valor)) {
                    cout << "Já existe!" << endl;
                } else if(empilhaP(&p, valor)) {
                    cout << "Inserida!" << endl;
                }
                break;

            case 3:
                if(!pilhaCriada || vaziaP(&p)) {
                    cout << "Erro!" << endl;
                } else {
                    valor = desempilhaP(&p);
                    cout << "Removido: " << valor << endl;
                }
                break;

            case 4:
                if(!pilhaCriada) {
                    cout << "Erro!" << endl;
                    break;
                }
                cout << "Consultar: ";
                getline(cin, valor);
                cout << (buscaP(&p, valor) ? "Sim" : "Não") << endl;
                break;

            case 5:
                if(pilhaCriada) mostraP(&p);
                else cout << "Erro!" << endl;
                break;

            case 6:
                if(pilhaCriada) destroiP(&p);
                cout << "Sair." << endl;
                break;

            default: cout << "Inválida!" << endl;
        }
    } while(opcao != 6);

    return 0;
}

