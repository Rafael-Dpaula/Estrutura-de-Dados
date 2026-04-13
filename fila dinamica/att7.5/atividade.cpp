#include <iostream>
#include <clocale>
using namespace std;
#include "../exemplo-fila-dinamica/fila-dinamica.hpp"

/**
 * att7.5 - Lista 7 exercício 5: ordenaF fila dinâmica int
 * Ordena por swaps de dados adjacentes (bubble), sem aux vetores/estruturas.
 * ordem=0 crescente, 1 decrescente. Para quando no swaps.
 * Comentários simples PT-BR explicando cada linha/grupo.
 */

void ordenaF(Fila *f, int ordem) {
    // Função para ordenar a fila em f (parâmetro por referência, altera original)
    if (vaziaF(f)) return; // Sai se fila vazia, nada a ordenar
    
    bool trocou; // Flag: true se houve troca em passada, para parar quando ordenada
    do {
        trocou = false; // Assume sem trocas nesta passada
        NoFila *atual = f->inicio; // Começa do primeiro nó
        
        // Percorre até penúltimo nó (para acessar atual->prox)
        while (atual != nullptr && atual->prox != nullptr) {
            int a = atual->dado; // Dado do nó atual
            int b = atual->prox->dado; // Dado do próximo nó
            
            bool deveTrocar = false; // Decide se troca
            
            if (ordem == 0) { // 0 = crescente
                if (a > b) deveTrocar = true; // Se atual maior que próximo, troca
            } else { // 1 = decrescente
                if (a < b) deveTrocar = true; // Se atual menor, troca
            }
            
            if (deveTrocar) {
                // Troca APENAS os valores dado, não ponteiros (conforme exercício)
                atual->dado = b;
                atual->prox->dado = a;
                trocou = true; // Marca que trocou, continua loop do/while
            }
            
            atual = atual->prox; // Avança para próximo par
        }
    } while (trocou); // Repete passada se houve trocas (como bubble sort otimizado)
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Acentos PT-BR
    
    Fila f; // Fila dinâmica vazia
    int op, valor, ordem; // Opções e valores
    
    do {
        // Menu intuitivo PT-BR
        cout << "\n===== ATIVIDADE 7.5 - ORDENAR FILA DINAMICA =====" << endl;
        cout << "1 - Enfileirar valor (final)" << endl;
        cout << "2 - Mostrar fila atual" << endl;
        cout << "3 - Ordenar fila (0=crescente, 1=decrescente)" << endl;
        cout << "0 - Sair do programa" << endl;
        cout << "Digite opção: ";
        cin >> op;
        cout << endl;
        
        switch (op) {
            case 1: {
                cout << "Digite valor inteiro: ";
                cin >> valor;
                if (enfileiraF(&f, valor)) {
                    cout << "Sucesso! " << valor << " adicionado no FINAL da fila." << endl;
                } else {
                    cout << "Erro ao alocar memória!" << endl;
                }
                break;
            }
            case 2: {
                if (vaziaF(&f)) {
                    cout << "Fila vazia!" << endl;
                } else {
                    mostraF(&f);
                }
                break;
            }
            case 3: {
                cout << "Tipo (0=crescente, 1=decrescente): ";
                cin >> ordem;
                cout << "\n--- ANTES da ordenação ---" << endl;
                mostraF(&f);
                ordenaF(&f, ordem);
                cout << "\n--- DEPOIS ordenada ---" << endl;
                mostraF(&f);
                break;
            }
            case 0: {
                cout << "Saindo..." << endl;
                break;
            }
            default: {
                cout << "Opção inválida! Tente 0-3." << endl;
            }
        }
    } while (op != 0);
    
    destroiF(&f); // Libera todos nós alocados
    return 0;
}

