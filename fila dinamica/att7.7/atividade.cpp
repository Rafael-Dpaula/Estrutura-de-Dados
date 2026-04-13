#include <iostream>
#include <clocale>
using namespace std;
#include "../exemplo-fila-dinamica/fila-dinamica.hpp"

/**
 * att7.7 - Lista 7 exercício 7: separaIntercalado
 * Divide f1 em f2 (ímpar pos, mais se ímpar tamanho), f3 (par pos).
 * Ex: f1=[1,20,3,40,5] -> f2=[1,3,5], f3=[20,40]
 * Reset f2/f3 antes. Menu fill f1, separa, show.
 * Comentários simples PT-BR.
 */

void separaIntercalado(Fila *f1, Fila *f2, Fila *f3) {
    // Destrói f2 e f3 antes (reset vazias)
    destroiF(f2);
    destroiF(f3);
    
    // Alterna desenfileira f1 para f2/f3
    bool paraF2 = true; // Começa par/impar para f2
    while (!vaziaF(f1)) {
        int val = desenfileiraF(f1);
        if (paraF2) {
            enfileiraF(f2, val);
        } else {
            enfileiraF(f3, val);
        }
        paraF2 = !paraF2; // Alterna
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Fila f1, f2, f3;
    int op, valor;
    
    do {
        cout << "\n===== ATIVIDADE 7.7 - SEPARA INTERCALADO =====" << endl;
        cout << "1 - Enfileirar em F1" << endl;
        cout << "2 - Mostrar F1" << endl;
        cout << "3 - Separar intercalado F1 -> F2/F3 (show)" << endl;
        cout << "4 - Mostrar F2 e F3" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opção: ";
        cin >> op;
        
        switch (op) {
            case 1:
                cout << "Valor F1: ";
                cin >> valor;
                enfileiraF(&f1, valor);
                break;
            case 2:
                mostraF(&f1);
                break;
            case 3:
                if (vaziaF(&f1)) {
                    cout << "F1 vazia!" << endl;
                } else {
                    cout << "Antes: ";
                    mostraF(&f1);
                    separaIntercalado(&f1, &f2, &f3);
                    cout << "F2: ";
                    mostraF(&f2);
                    cout << "F3: ";
                    mostraF(&f3);
                }
                break;
            case 4:
                mostraF(&f2);
                mostraF(&f3);
                break;
            case 0:
                break;
            default:
                cout << "Inválido!" << endl;
        }
    } while (op != 0);
    
    destroiF(&f1);
    destroiF(&f2);
    destroiF(&f3);
    return 0;
}

