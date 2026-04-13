#include <iostream>
#include <string>
using namespace std;
#include "pilha.hpp"

/**
 * att4.4 - Lista 4 exercício 4: Verificar se expressão com [(){}] está balanceada usando pilha.
 * Exemplos balanceadas: "[ { () () } {} ]", "{ [ ( [ { } ] ) ] }"
 * Não balanceadas: "{ [ ( } ] )", "{ [ ) () ( ] }"
 * Lógica simples passo-a-passo:
 * 1. Para cada char na expr:
 *    - Se abrindo '([{' : empilha o char (cast int)
 *    - Se fechando )]} : se pilha vazia ou topo não match pop(), false
 * 2. Fim: pilha vazia = true (balanceada)
 * 3. Ignora chars não parênteses (espaços etc).
 * 4. Menu PT-BR com exs PDF + input livre.
 */

bool isBalanceada(string expr) {
    Pilha p;
    
    for (char c : expr) {
        // Ignora não parênteses
        if (c != '(' && c != '[' && c != '{' && c != ')' && c != ']' && c != '}') continue;
        
        if (c == '(' || c == '[' || c == '{') {
            // Abrindo: empilha
            empilhaP(&p, (int)c);
        } else {
            // Fechando: verifica match
            if (vaziaP(&p)) return false;
            
            int topo = desempilhaP(&p);
            // Match: (40)=='(', )41==), etc.
            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                return false;
            }
        }
    }
    
    return vaziaP(&p); // Balanceada se vazia
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    cout << "=== VERIFICADOR EXPRESSOES BALANCEADAS COM PILHA ===" << endl;
    cout << "Exs balanceadas: [ { () () } {} ], { [ ( [ { } ] ) ] }" << endl;
    cout << "Exs não: { [ ( } ] ), { [ ) () ( ] }" << endl << endl;
    
    string expr;
    cout << "Digite a expressão: ";
    getline(cin, expr);
    
    if (isBalanceada(expr)) {
        cout << "\"" << expr << "\" -> BALANCEADA!" << endl;
    } else {
        cout << "\"" << expr << "\" -> NAO BALANCEADA!" << endl;
    }
    
    cout << endl << "=== FIM ===" << endl;
    
    return 0;
}

