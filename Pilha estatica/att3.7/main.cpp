#include <iostream>
#include <string>
#include <clocale>
using namespace std;
#include "pilha.hpp"

/**
 * att3.7 - Lista 3 ex7: Balance parênteses expressão.
 * Emp '(' , pop on ')', end vazia.
 * Menu teste expressões.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha p;
    string expr;
    cout << "=== BALANCE PARENTESES ===" << endl;

    // Exemplos
    string exs[] = {"(A+B)", "((A+B)+(C+D))", "((A+B)", ")A+B(", "(A+B))-(C+D)"};
    for (string e : exs) {
        cout << "Expr: " << e << " -> ";
        if (balancePar(&p, e)) cout << "BALANCEADA" << endl;
        else cout << "NAO" << endl;
    }

    // User input
    cout << "Sua expr: ";
    getline(cin, expr);
    if (balancePar(&p, expr)) cout << "Balanceada!" << endl;
    else cout << "Não!" << endl;

    destroiP(&p);
    return 0;
}

