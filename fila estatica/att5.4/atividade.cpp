#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "filacircular-aviao.hpp"
#include "aviao.hpp"

// Programa exercício 4 lista5: Gerenciar pista de decolagem (fila max 5 aviões)
// Menu: a) nº aviões, b) entrada novo avião, c) decolagem, d) listar, e) próximo
// Imprime dados em b,c,e
// Comentado em PT-BR simples

int main() {
    setlocale(LC_ALL, "Portuguese");

    FilaAviao pista;  // Fila da pista (max 5)
    inicializaFA(&pista);  // Sempre tam=5

    int opcao;
    string codigo, empresa;
    int pass;
    Aviao novo, decolou, proximo;

    cout << "=== EXERCÍCIO 4 - PISTA DE DECOLAGEM AEROPORTO ===" << endl;
    cout << "Pista comporta MAX 5 aviões. Fila circular!" << endl << endl;

    do {
        // Menu PT-BR intuitivo
        cout << "=== MENU PISTA ===" << endl;
        cout << "1 - Número de aviões esperando (conta)" << endl;
        cout << "2 - Entrada novo avião" << endl;
        cout << "3 - Decolagem (remove frente)" << endl;
        cout << "4 - Listar todos esperando" << endl;
        cout << "5 - Próximo a decolar (peek)" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa buffer

        switch (opcao) {
            case 1:
                cout << "Aviões esperando: " << contaFA(&pista) << endl;
                break;

            case 2:  // Entrada novo
                cout << "Código do avião: ";
                getline(cin, codigo);
                cout << "Empresa: ";
                getline(cin, empresa);
                cout << "Nº passageiros: ";
                cin >> pass;
                novo.codigo = codigo;
                novo.empresa = empresa;
                novo.passageiros = pass;
                if (enfileiraFA(&pista, novo)) {
                    cout << "Avião adicionado à pista!" << endl;
                    novo.mostrar();
                } else {
                    cout << "Pista CHEIA! Não pode adicionar." << endl;
                }
                cin.ignore();  // Limpa
                break;

            case 3:  // Decolagem
                decolou = desenfileiraFA(&pista);
                if (decolou.codigo != "") {
                    cout << "AVIÃO DECOLOU:" << endl;
                    decolou.mostrar();
                } else {
                    cout << "Nenhum avião para decolar (pista vazia)!" << endl;
                }
                break;

            case 4:
                listaFA(&pista);
                break;

            case 5:  // Peek
                proximo = proximoFA(&pista);
                if (proximo.codigo != "") {
                    cout << "PRÓXIMO A DECOLAR:" << endl;
                    proximo.mostrar();
                } else {
                    cout << "Nenhum avião esperando!" << endl;
                }
                break;

            case 0:
                break;

            default:
                cout << "Opção inválida!" << endl;
        }
        cout << endl;
    } while (opcao != 0);

    destroiFA(&pista);
    cout << "Programa encerrado. Pista liberada!" << endl;

    return 0;
}

