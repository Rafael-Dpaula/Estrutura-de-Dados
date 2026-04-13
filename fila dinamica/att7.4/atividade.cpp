#include <iostream>
#include <clocale>
using namespace std;
#include "fila-produto.hpp"

/**
 * att7.4 - Lista 7 exercício 4: combinarF em fila dinâmica de Produto
 * Combina produtos mesmo nome somando quantidades, preserva ordem primeiro encontrado.
 * Usa filas aux para merge. Menu enfileira, show, combinar.
 * Adaptado para dinâmica (PDF menciona circular cap30, mas lista7 dinâmica).
 * Comentários PT-BR simples.
 */

void combinarF(FilaProduto *f) {
    if (vaziaF(f)) return;
    
    FilaProduto aux1, aux2; // Aux para elementos já processados e temporários
    
    while (!vaziaF(f)) {
        Produto atual = desenfileiraF(f);
        bool combinou = false;
        
        // Verifica se atual combina com topo de aux1 (já processados)
        FilaProduto temp;
        while (!vaziaF(&amp;aux1) &amp;&amp; !combinou) {
            Produto topo = desenfileiraF(&amp;aux1);
            if (topo.nome == atual.nome) {
                topo.quantidade += atual.quantidade;
                atual = topo;
                combinou = true;
            } else {
                enfileiraF(&amp;temp, topo);
            }
        }
        // Restaura temp para aux1
        while (!vaziaF(&amp;temp)) {
            enfileiraF(&amp;aux1, desenfileiraF(&amp;temp));
        }
        
        enfileiraF(&amp;aux1, atual);
    }
    
    // aux1 tem combinados, copia de volta para f
    while (!vaziaF(&amp;aux1)) {
        enfileiraF(f, desenfileiraF(&amp;aux1));
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    FilaProduto f;
    Produto p;
    int op;
    
    do {
        cout << "\n===== ATIVIDADE 7.4 - COMBINAR PRODUTOS =====" << endl;
        cout << "1 - Enfileirar Produto" << endl;
        cout << "2 - Mostrar Fila (tam/total)" << endl;
        cout << "3 - Combinar Produtos (chama combinarF)" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";
        cin >> op;
        
        switch (op) {
            case 1:
                cout << "Nome: ";
                cin >> p.nome;
                cout << "Quantidade: ";
                cin >> p.quantidade;
                enfileiraF(&amp;f, p);
                cout << "OK! Adicionado." << endl;
                break;
            case 2:
                mostraF(&amp;f);
                break;
            case 3:
                cout << "Antes:" << endl;
                mostraF(&amp;f);
                combinarF(&amp;f);
                cout << "Depois:" << endl;
                mostraF(&amp;f);
                break;
            case 0:
                break;
            default:
                cout << "Inválido!" << endl;
        }
    } while (op != 0);
    
    destroiF(&amp;f);
    return 0;
}

