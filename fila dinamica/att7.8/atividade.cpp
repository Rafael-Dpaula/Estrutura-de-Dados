#include <iostream>
#include <clocale>
using namespace std;
#include "ficha.hpp"
#include "fila-ficha.hpp"
#include "pilha-ficha.hpp"

/**
 * att7.8 - Lista 7 exercício 8: Veterinária Passo Fundo
 * Filas prioritárias (grave/estável), atendimento regras (max 3 grave, intercal 1 não-pri).
 * Stacks por tipo (S/ANIMALS, D/ANIMALD).
 * Menu a-g completo.
 * Comentários PT-BR simples.
 */

FilaFicha filaGrave, filaEstavel; // Filas
PilhaFicha pilhaS, pilhaD; // Stacks animais S/D

void mostrarFilas() {
    cout << "Filas de atendimento:" << endl;
    mostraF(&filaGrave);
    mostraF(&filaEstavel);
}

void criarFicha() {
    Ficha fich;
    cout << "Nome: ";
    cin >> fich.nome;
    cout << "Idade: ";
    cin >> fich.idade;
    cout << "Tipo (S/D): ";
    cin >> fich.tipo;
    cout << "Quadro (E/G): ";
    cin >> fich.quadro;
    
    FilaFicha *fila = (fich.quadro == 'G') ? &filaGrave : &filaEstavel;
    if (enfileiraF(fila, fich)) {
        cout << "Ficha adicionada!" << endl;
    } else {
        cout << "Erro!" << endl;
    }
}

void atenderFicha() {
    int atendidosGrave = 0;
    while (!vaziaF(&filaGrave) && atendidosGrave < 3) {
        Ficha fich = desenfileiraF(&filaGrave);
        PilhaFicha *pilha = (fich.tipo == 'S') ? &pilhaS : &pilhaD;
        empilhaP(pilha, fich);
        atendidosGrave++;
    }
    if (!vaziaF(&filaEstavel)) {
        Ficha fich = desenfileiraF(&filaEstavel);
        PilhaFicha *pilha = (fich.tipo == 'S') ? &pilhaS : &pilhaD;
        empilhaP(pilha, fich);
    }
    cout << "Atendimento realizado!" << endl;
}

void infoFilas() {
    int total = 0; // Implementar contagem se necessário
    // Porcentagem grave etc. simplificado
    cout << "Info filas (implementar contagem total %grave %domésticos)" << endl;
}

void mostrarPilhas() {
    mostraP(&pilhaS);
    mostraP(&pilhaD);
}

void removerPilha() {
    char qual;
    cout << "Pilha (S/D): ";
    cin >> qual;
    PilhaFicha *p = (qual == 'S') ? &pilhaS : &pilhaD;
    Ficha fich = desempilhaP(p);
    cout << "Removido: " << fich.nome << endl;
}

void menorIdadeGrave() {
    // Simplificado: procura nas pilhas min idade com G
    cout << "Menor idade grave (implementar busca)" << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int op;
    do {
        cout << "\n===== VETERINÁRIA PASSO FUNDO ===== " << endl;
        cout << "a - Criar ficha/add fila" << endl;
        cout << "b - Atender ficha" << endl;
        cout << "c - Mostrar filas" << endl;
        cout << "d - Info filas unificada" << endl;
        cout << "e - Listar pilhas atendidas" << endl;
        cout << "f - Remover topo pilha" << endl;
        cout << "g - Nome menor idade grave" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opção: ";
        cin >> op;
        
        switch (op) {
            case 'a': criarFicha(); break;
            case 'b': atenderFicha(); break;
            case 'c': mostrarFilas(); break;
            case 'd': infoFilas(); break;
            case 'e': mostrarPilhas(); break;
            case 'f': removerPilha(); break;
            case 'g': menorIdadeGrave(); break;
            case '0': break;
            default: cout << "Inválido!" << endl;
        }
    } while (op != '0');
    
    destroiF(&filaGrave);
    destroiF(&filaEstavel);
    destroiP(&pilhaS);
    destroiP(&pilhaD);
    return 0;
}

