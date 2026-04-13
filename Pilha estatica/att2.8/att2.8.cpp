#include <iostream>
#include <string>
#include <clocale>
#include <cctype>
using namespace std;
#include "pilha-char.hpp"

/**
 * att2.8 - Lista 2 exercício 8: Palíndromo com pilha char estática.
 * Lê string, ignora espaços e pontos, empilha só letras (tolower).
 * Desempilha e compara com original limpa. Sem vetores aux.
 * Testa exemplos: Osso, Radar, Ovo, Arara, etc.
 * Menu para várias testes.
 */

bool pilhaCriada = false;
Pilha p;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int op;
    string texto, limpa, invertida = "";
    char ch;

    cout << "=== DETECTOR PALÍNDROMO COM PILHA CHAR ===" << endl;
    cout << "Ignora espaços e pontos. Ex: Osso, Radar." << endl;
    cout << "1-Testar texto 2-Exemplos 3-Sair" << endl;

    do {
        cout << "\nOp: ";
        cin >> op;
        cin.ignore();

        switch(op) {
            case 1:
                if(pilhaCriada) destroiP(&p);
                cout << "Tamanho máx (100 ok): ";
                int tam; cin >> tam;
                inicializaP(&p, tam);
                pilhaCriada = true;

                cout << "Texto: ";
                getline(cin, texto);
                limpa = "";

                // Limpa e empilha letras
                for(char c : texto) {
                    if(isalpha(c)) { // Se letra
                        ch = tolower(c);
                        empilhaP(&p, ch);
                        limpa += ch;
                    }
                    // Ignora espaços e pontos
                }

                // Desempilha para invertida
                while(!vaziaP(&p)) {
                    ch = desempilhaP(&p);
                    invertida = ch + invertida;
                }

                cout << "Limpa: " << limpa << endl;
                cout << "Reverse pilha: " << invertida << endl;
                cout << (limpa == invertida ? "É palíndromo!" : "Não é!") << endl;
                break;

            case 2:
                // Exemplos hard-coded
                cout << "Testes auto:" << endl;
                string exemplos[] = {"Osso", "Radar", "Ovo", "Arara", "abc"};
                for(string ex : exemplos) {
                    // Simula (recupera pilha ou nova pequena)
                    inicializaP(&p, 100);
                    string l = "", inv = "";
                    for(char c : ex) {
                        if(isalpha(c)) {
                            ch = tolower(c);
                            empilhaP(&p, ch);
                            l += ch;
                        }
                    }
                    while(!vaziaP(&p)) inv = desempilhaP(&p) + inv;
                    destroiP(&p);
                    cout << ex << " -> " << (l == inv ? "SIM" : "NÃO") << endl;
                }
                break;

            case 3:
                if(pilhaCriada) destroiP(&p);
                break;

            default: cout << "Inválido!" << endl;
        }
    } while(op != 3);

    return 0;
}

