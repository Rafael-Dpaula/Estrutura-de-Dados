#include <iostream>
#include <clocale>
#include <cstdlib>
using namespace std;

#include "../exemplo-fila-dinamica/fila-dinamica.hpp"

/**
 * att7.2 - Lista 7 exercício 2: concatenar duas filas dinâmicas
 * Função concatenaF(f1, f2, fRes): copia todos de f1 para fRes, depois todos de f2.
 * Menus para enfileirar em f1/f2, mostrar, concatenar e mostrar resultado.
 * Comentários simples em português brasileiro explicando cada parte do código.
 */

void concatenaF(Fila *f1, Fila *f2, Fila *fRes) {
    // Esta função concatena duas filas: pega todos elementos de f1 (na ordem FIFO) 
    // e coloca em fRes, depois pega todos de f2 e coloca no final de fRes.
    // f1 e f2 ficam vazias após isso, fRes tem f1 + f2.
    
    // Passo 1: Copia tudo de f1 para fRes
    while (!vaziaF(f1)) {
        // Desenfileira do início de f1 e enfileira no final de fRes
        enfileiraF(fRes, desenfileiraF(f1));
    }
    
    // Passo 2: Copia tudo de f2 para fRes (agora no final)
    while (!vaziaF(f2)) {
        enfileiraF(fRes, desenfileiraF(f2));
    }
    
    // Pronto! fRes tem concatenação completa. Exemplo: f1=[1,2], f2=[3,4] -> fRes=[1,2,3,4]
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura acentos para português brasileiro
    
    Fila f1, f2, fRes; // Três filas dinâmicas: origem 1, origem 2, resultado
    int op, valor; // Opção menu e valor para inserir
    
    do {
        // Menu principal simples e intuitivo em PT-BR
        cout << "\n===== ATIVIDADE 7.2 - CONCATENAR FILAS =====" << endl;
        cout << "1 - Enfileirar na Fila 1" << endl;
        cout << "2 - Enfileirar na Fila 2" << endl;
        cout << "3 - Mostrar Fila 1" << endl;
        cout << "4 - Mostrar Fila 2" << endl;
        cout << "5 - Concatenar F1 + F2 -> FResultado (mostra)" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";
        cin >> op;
        
        switch (op) {
            case 1:
                cout << "Valor para F1: ";
                cin >> valor;
                if (enfileiraF(&amp;f1, valor)) {
                    cout << "OK! " << valor << " adicionado no FINAL da Fila 1." << endl;
                } else {
                    cout << "Erro ao adicionar (memória?)." << endl;
                }
                break;
                
            case 2:
                cout << "Valor para F2: ";
                cin >> valor;
                if (enfileiraF(&amp;f2, valor)) {
                    cout << "OK! " << valor << " adicionado no FINAL da Fila 2." << endl;
                } else {
                    cout << "Erro ao adicionar." << endl;
                }
                break;
                
            case 3:
                cout << "Fila 1: ";
                mostraF(&amp;f1);
                break;
                
            case 4:
                cout << "Fila 2: ";
                mostraF(&amp;f2);
                break;
                
            case 5:
                if (vaziaF(&amp;f1) &amp;&amp; vaziaF(&amp;f2)) {
                    cout << "Filas vazias! Nada para concatenar." << endl;
                } else {
                    cout << "Concatenando F1 + F2..." << endl;
                    concatenaF(&amp;f1, &amp;f2, &amp;fRes);
                    cout << "Resultado (F1+F2): ";
                    mostraF(&amp;fRes);
                }
                break;
                
            case 0:
                cout << "Saindo..." << endl;
                break;
                
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (op != 0);
    
    // Libera memória antes de sair (importante para evitar vazamentos)
    destroiF(&amp;f1);
    destroiF(&amp;f2);
    destroiF(&amp;fRes);
    
    return 0;
}

