#include <iostream>
#include <string>
#include <clocale>
using namespace std;
#include "pilha-cliente.hpp"

/**
 * att2.6 - Lista 2 exercício 6: Pilha para Cliente struct.
 * Struct: codigo(int), nome(string), idade(int).
 * Menu inserir/remover/mostrar (formato topo {[...], [...]} base).
 * Sem duplicados por codigo.
 * Adaptado de base.
 */

bool pilhaCriada = false;
Pilha p;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int op, tam, cod, idad;
    string nom;
    Cliente c;

    cout << "=== MENU PILHA CLIENTE ===" << endl;
    cout << "1-Criar 2-Inserir 3-Remover 4-Mostrar 5-Sair" << endl;

    do {
        cout << "\nOp: ";
        cin >> op;
        cin.ignore();

        switch(op) {
            case 1:
                if(pilhaCriada) destroiP(&p);
                cout << "Tamanho: ";
                cin >> tam;
                inicializaP(&p, tam);
                pilhaCriada = true;
                cout << "OK!" << endl;
                break;

            case 2:
                if(!pilhaCriada || cheiaP(&p)) {
                    cout << "Erro!" << endl;
                } else {
                    cout << "Codigo: ";
                    cin >> cod;
                    cin.ignore();
                    cout << "Nome: ";
                    getline(cin, nom);
                    cout << "Idade: ";
                    cin >> idad;
                    c = {cod, nom, idad};
                    if(buscaP(&p, c)) {
                        cout << "Codigo existe!" << endl;
                    } else if(empilhaP(&p, c)) {
                        cout << "Inserido!" << endl;
                    }
                }
                break;

            case 3:
                if(!pilhaCriada || vaziaP(&p)) cout << "Erro!" << endl;
                else {
                    c = desempilhaP(&p);
                    cout << "Removido [" << c.codigo << "," << c.nome << "," << c.idade << "]" << endl;
                }
                break;

            case 4:
                if(pilhaCriada) mostraP(&p);
                break;

            case 5:
                if(pilhaCriada) destroiP(&p);
                break;

            default: cout << "Inválido!" << endl;
        }
    } while(op != 5);

    return 0;
}

