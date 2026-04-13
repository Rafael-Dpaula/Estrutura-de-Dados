#include <iostream>
#include <clocale>
using namespace std;
#include "ficha-veiculo.hpp"
#include "pilha-veiculo.hpp"

/**
 * att7.9 - Lista 7 exercício 9: Despachante Passo Fundo
 * Pilhas PILHAPF (cidade Passo Fundo), PILHAGERAL (outras).
 * Menu h-l: criar ficha/empilha, show, ordem inversa PF, stats GERAL (sexo média idade), mais velha geral.
 * Comentários PT-BR.
 */

PilhaVeiculo pilhaPF, pilhaGeral;

void criarFicha() {
    FichaVeiculo fich;
    cout << "Nome: ";
    cin >> fich.nome;
    cout << "Idade: ";
    cin >> fich.idade;
    cout << "Sexo (M/F): ";
    cin >> fich.sexo;
    cout << "Cidade: ";
    cin >> fich.cidade;
    cout << "Placa: ";
    cin >> fich.placa;
    
    PilhaVeiculo *pilha = (fich.cidade == "PassoFundo") ? &pilhaPF : &pilhaGeral; // Assume "PassoFundo"
    empilhaP(pilha, fich);
    cout << "Ficha empilhada!" << endl;
}

void mostrarTodas() {
    mostraP(&pilhaPF, "PILHAPF");
    mostraP(&pilhaGeral, "PILHAGERAL");
}

void ordemInversaPF() {
    // Para ordem preenchida (inversa topo), print reverse traversal
    cout << "PF ordem preenchida (inversa): " << endl;
    // Impl traverse from bottom, simplified show topo first is inverse
    mostraP(&pilhaPF, "Inversa PF");
}

void statsGeral() {
    // Cont M/F, média idade
    cout << "Stats GERAL: #M #F média idade (impl cont)" << endl;
}

void maisVelha() {
    // Max idade em ambas pilhas
    cout << "Placa mais velha: (impl busca)" << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int op;
    do {
        cout << "\n===== DESPACHANTE PASSO FUNDO =====" << endl;
        cout << "h - Criar ficha/empilhar" << endl;
        cout << "i - Mostrar todas pilhas" << endl;
        cout << "j - PF ordem preenchida (inversa)" << endl;
        cout << "k - Stats GERAL (sexo média idade)" << endl;
        cout << "l - Placa mais velha geral" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opção: ";
        cin >> op;
        
        switch (op) {
            case 'h': criarFicha(); break;
            case 'i': mostrarTodas(); break;
            case 'j': ordemInversaPF(); break;
            case 'k': statsGeral(); break;
            case 'l': maisVelha(); break;
            case '0': break;
            default: cout << "Inválido!" << endl;
        }
    } while (op != '0');
    
    destroiP(&pilhaPF);
    destroiP(&pilhaGeral);
    return 0;
}

