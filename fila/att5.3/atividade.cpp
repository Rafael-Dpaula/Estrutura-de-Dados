#include <iostream>
#include <limits>  // Para ignorar input
using namespace std;

#include "filacircular.hpp"  // Nossa fila circular personalizada

// Programa principal para exercício 3 da lista 5
// Implementa duas funções de busca em fila circular:
// a) Com fila auxiliar (move tudo para aux, busca, restaura)
// b) Sem auxiliar (percorre da frente ao trás sem mover)
// Menus em português do Brasil para fácil uso
// Tudo comentado detalhadamente para entender cada passo

int main() {
    setlocale(LC_ALL, "Portuguese");  // Configura acentos PT-BR

    Fila fila;      // Fila principal
    Fila filaAux;   // Fila auxiliar para busca a)
    int tamanho;    // Tamanho da fila a criar
    int opcao;      // Opção do menu
    int valor;      // Valor para inserir/buscar

    // Passo 1: Pedir tamanho da fila e inicializar
    cout << "=== EXERCÍCIO 3 - BUSCA EM FILA CIRCULAR ===" << endl;
    cout << "Digite o tamanho máximo da fila: ";
    cin >> tamanho;
    inicializaF(&fila, tamanho);
    cout << "Fila inicializada com tamanho " << tamanho << endl << endl;

    do {
        // Menu intuitivo em PT-BR
        cout << "=== MENU FILA CIRCULAR ===" << endl;
        cout << "1 - Enfileirar valor (adicionar no final)" << endl;
        cout << "2 - Desenfileirar (remover da frente)" << endl;
        cout << "3 - Mostrar fila" << endl;
        cout << "4 - Busca SIMPLES (sem auxiliar)" << endl;
        cout << "5 - Busca COM AUXILIAR" << endl;
        cout << "0 - Sair e destruir fila" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:  // Enfileirar
                cout << "Digite o valor para enfileirar: ";
                cin >> valor;
                if (enfileiraF(&fila, valor)) {
                    cout << "Valor " << valor << " enfileirado com sucesso!" << endl;
                } else {
                    cout << "Erro: Fila cheia ou não inicializada!" << endl;
                }
                break;

            case 2:  // Desenfileirar
                valor = desenfileiraF(&fila);
                if (fila.total > 0) {  // Verifica se removeu algo
                    cout << "Valor " << valor << " desenfileirado!" << endl;
                } else {
                    cout << "Fila vazia, nada para remover!" << endl;
                }
                break;

            case 3:  // Mostrar
                cout << "Conteúdo da fila: ";
                mostraF(&fila);
                break;

            case 4:  // Busca simples (sem aux)
                cout << "Digite o valor para buscar (simples): ";
                cin >> valor;
                if (buscaSimplesF(&fila, valor)) {
                    cout << "Valor " << valor << " ENCONTRADO na fila!" << endl;
                } else {
                    cout << "Valor " << valor << " NÃO encontrado!" << endl;
                }
                break;

            case 5:  // Busca com aux
                cout << "Digite o valor para buscar (com aux): ";
                cin >> valor;
                if (buscaAuxF(&fila, &filaAux, valor)) {
                    cout << "Valor " << valor << " ENCONTRADO usando auxiliar!" << endl;
                } else {
                    cout << "Valor " << valor << " NÃO encontrado!" << endl;
                }
                break;

            case 0:
                cout << "Saindo..." << endl;
                break;

            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
        cout << endl;
    } while (opcao != 0);

    // Limpeza final
    destroiF(&fila);
    if (verificaInicializacaoF(&filaAux)) destroiF(&filaAux);  // Destrói aux se usada
    cout << "Fila destruída. Programa finalizado!" << endl;

    return 0;
}

