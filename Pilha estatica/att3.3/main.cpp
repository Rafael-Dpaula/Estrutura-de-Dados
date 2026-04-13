#include <iostream>
#include <clocale>
using namespace std;
#include "pilha.hpp"

/**
 * att3.3 - Lista 3 exercício 3: Verifica se duas pilhas P1 e P2 são iguais.
 * Mesmos elementos mesma ordem topo-base.
 * Usa aux temps para desemp/compare/restore sem alterar originais.
 * Menu cria P1 P2 rand/ex, testa pilhasIguais.
 * Comentários simples PT-BR.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha p1, p2;
    int tam;
    bool igual;

    cout << "=== EX3 PILHAS IGUAIS ===" << endl;
    cout << "Tam P1: ";
    cin >> tam;
    inicializaP(&p1, tam);
    cout << "Tam P2: ";
    cin >> tam;
    inicializaP(&p2, tam);

    // Menu inserir para P1 P2
    int op, val;
    do {
        cout << "1-Emp P1 2-Emp P2 3-Testa iguais 4-Mostra 0-Fim" << endl;
        cin >> op;
        if(op == 1) {
            cout << "Val P1: ";
            cin >> val;
            empilhaP(&p1, val);
        } else if(op == 2) {
            cout << "Val P2: ";
            cin >> val;
            empilhaP(&p2, val);
        } else if(op == 3) {
            igual = pilhasIguais(&p1, &p2);
            cout << "P1 == P2? " << (igual ? "SIM" : "NÃO") << endl;
        } else if(op == 4) {
            mostraP(&p1);
            mostraP(&p2);
        }
    } while(op != 0);

    destroiP(&p1);
    destroiP(&p2);
    return 0;
}

