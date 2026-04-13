#include <iostream>
#include <clocale>
using namespace std;
#include "pilha.hpp"

/**
 * att3.9 - Lista 3 ex9: Conversão decimal para binário usando pilha.
 * Div N por 2, emp resto (0/1), desemp print reverse bin.
 * Menu teste números.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");

    cout << "=== DEC to BIN PILHA ===" << endl;

    int n;
    cout << "N (dec): ";
    cin >> n;
    cout << n << " = " << decToBin(n) << " bin" << endl;

    // Exemplos
    int tests[] = {0, 1, 2, 10, 13, 255};
    for (int t : tests) {
        cout << t << " = " << decToBin(t) << endl;
    }

    cout << "Ex9 OK!" << endl;
    return 0;
}

