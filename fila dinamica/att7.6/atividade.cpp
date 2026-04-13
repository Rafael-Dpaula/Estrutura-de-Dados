#include <iostream>
#include <clocale>
using namespace std;
#include "../exemplo-fila-dinamica/fila-dinamica.hpp"

/**
 * att7.6 - Lista 7 exercício 6: furaFila
 * Insere novo elemento no INÍCIO da fila dinâmica (furando fila).
 * Mantém ordem relativa dos outros elementos.
 * Menu: enf normal, furaFila, show before/after.
 * Comentários simples PT-BR.
 */

void furaFila(Fila *f, int dado) {
    // Cria novo nó no início, atualiza ponteiros.
    NoFila *novo = new NoFila(); // Novo nó com dado
    if (novo == nullptr) return; // Erro memória
    
    novo->dado = dado;
    novo->prox = f->inicio; // Próximo é antigo início
    f->inicio = novo; // Novo início
    
    if (f->fim == nullptr) f->fim = novo; // Se vazia, fim também novo
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Fila f;
    int op, valor;
    
    do {
        cout << "\n===== ATIVIDADE 7.6 - FURAR FILA =====" << endl;
        cout << "1 - Enfileirar normal (final)" << endl;
        cout << "2 - FuraFila (início)" << endl;
        cout << "3 - Mostrar fila" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opção: ";
        cin >> op;
        
        switch (op) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                enfileiraF(&f, valor);
                cout << "OK no final." << endl;
                break;
            case 2:
                cout << "Valor para furar (início): ";
                cin >> valor;
                cout << "Antes: ";
                mostraF(&f);
                furaFila(&f, valor);
                cout << "Depois: ";
                mostraF(&f);
                break;
            case 3:
                mostraF(&f);
                break;
            case 0:
                break;
            default:
                cout << "Inválido!" << endl;
        }
    } while (op != 0);
    
    destroiF(&f);
    return 0;
}

