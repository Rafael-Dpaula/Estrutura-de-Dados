#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "pilha.hpp"

/**
 * att3.1 main - Testa buscaValor preserve pilha.
 * Menu: tam, emp rand/manual, mostra, busca val (sim/não), mostra after.
 * PT-BR intuitivo.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");  // Acentos PT-BR
    srand(time(NULL));  // Rand variado

    Pilha p;
    int tam, op, val, busca_val;
    bool achou;

    cout << "=== ATT3.1 BUSCA VALOR PILHA (preserve) ===" << endl;
    cout << "Tamanho pilha: ";
    cin >> tam;
    inicializaP(&p, tam);

    // Menu simples
    do {
        cout << "\n1-Empilha rand  2-Emp manual  3-Mostra  4-Busca valor  0-Sair" << endl;
        cout << "Op: ";
        cin >> op;

        if (op == 1) {  // Rand 1-99
            if (!cheiaP(&p)) {
                empilhaP(&p, rand() % 99 + 1);
                cout << "Empilhou rand OK" << endl;
            } else cout << "Cheia!" << endl;
        } else if (op == 2) {
            cout << "Valor: ";
            cin >> val;
            if (empilhaP(&p, val)) cout << "Empilhou!" << endl;
            else cout << "Cheia!" << endl;
        } else if (op == 3) {
            mostraP(&p);
        } else if (op == 4) {
            cout << "Buscar valor: ";
            cin >> busca_val;
            cout << "Antes busca: ";
            mostraP(&p);
            achou = buscaValor(&p, busca_val);
            cout << "Achou " << busca_val << "? " << (achou ? "SIM" : "NAO") << endl;
            cout << "Depois (intacta): ";
            mostraP(&p);  // Mesma pilha!
        }
    } while (op != 0);

    destroiP(&p);
    cout << "Fim att3.1 OK!" << endl;
    return 0;
}

