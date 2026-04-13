#include <iostream>
#include <clocale>
#include <cstdlib>
using namespace std;
#include "pilha.hpp"

/**
 * att2.4 - Lista 2 exercício 4: Pilha estática com menu.
 * Regras:
 * - Criar: informa tamanho, desaloca anterior.
 * - Inserir: valor, sem duplicados, msg cheia.
 * - Remover: mostra removido topo, msg vazia.
 * - Consultar: se valor existe.
 * - Mostrar: pilha.
 * - Sair.
 * Msg erro se não criada para ops.
 * Sem dups inserir.
 * Comentários simples PT-BR.
 */

bool pilhaCriada = false;
Pilha p;
Pilha aux;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    int tamanho;
    int valor;

    cout << "=== MENU DA PILHA ESTATICA ===" << endl;
    cout << "1 - Criar pilha" << endl;
    cout << "2 - Inserir valor" << endl;
    cout << "3 - Remover valor" << endl;
    cout << "4 - Consultar valor" << endl;
    cout << "5 - Mostrar pilha" << endl;
    cout << "6 - Sair" << endl;

    do {
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1: // Criar pilha
                if (pilhaCriada) {
                    destroiP(&p); // Desaloca pilha anterior se existir
                    cout << "Pilha anterior destruida." << endl;
                }
                cout << "Digite o tamanho da pilha: ";
                cin >> tamanho;
                if (tamanho > 0) {
                    inicializaP(&p, tamanho); // Inicializa nova pilha
                    pilhaCriada = true;
                    cout << "Pilha criada com sucesso! Tamanho: " << tamanho << endl;
                } else {
                    cout << "Tamanho invalido!" << endl;
                }
                break;

            case 2: // Inserir valor (sem duplicados)
                if (!pilhaCriada) {
                    cout << "Erro: Pilha nao criada! Crie primeiro." << endl;
                    break;
                }
                if (cheiaP(&p)) {
                    cout << "Erro: Pilha cheia! Nao da para inserir mais." << endl;
                    break;
                }
                cout << "Digite o valor a inserir: ";
                cin >> valor;
                // Verifica se ja existe (sem duplicados)
                if (buscaP(&p, valor)) {
                    cout << "Erro: Valor " << valor << " ja existe na pilha!" << endl;
                } else {
                    if (empilhaP(&p, valor)) {
                        cout << "Valor " << valor << " inserido com sucesso!" << endl;
                    } else {
                        cout << "Erro ao inserir!" << endl;
                    }
                }
                break;

            case 3: // Remover valor do topo
                if (!pilhaCriada) {
                    cout << "Erro: Pilha nao criada!" << endl;
                    break;
                }
                if (vaziaP(&p)) {
                    cout << "Erro: Pilha vazia! Nada para remover." << endl;
                } else {
                    valor = desempilhaP(&p); // Remove e pega valor
                    cout << "Valor removido do topo: " << valor << endl;
                }
                break;

            case 4: // Consultar se valor existe
                if (!pilhaCriada) {
                    cout << "Erro: Pilha nao criada!" << endl;
                    break;
                }
                cout << "Digite o valor para consultar: ";
                cin >> valor;
                if (buscaP(&p, valor)) {
                    cout << "Valor " << valor << " encontrado na pilha!" << endl;
                } else {
                    cout << "Valor " << valor << " NAO encontrado!" << endl;
                }
                break;

            case 5: // Mostrar pilha
                if (!pilhaCriada) {
                    cout << "Erro: Pilha nao criada!" << endl;
                    break;
                }
                mostraP(&p); // Mostra usando funcao da pilha.hpp
                break;

            case 6:
                cout << "Saindo..." << endl;
                if (pilhaCriada) {
                    destroiP(&p); // Limpa memoria antes de sair
                }
                break;

            default:
                cout << "Opcao invalida! Tente 1-6." << endl;
        }
    } while (opcao != 6);

    return 0;
}
