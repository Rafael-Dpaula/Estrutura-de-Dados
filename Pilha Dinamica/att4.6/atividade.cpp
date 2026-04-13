#include <iostream>
#include <string>
using namespace std;
#include "pilha.hpp"

/**
 * att4.6 - Lista 4 exercício 6: Cadastro clientes banco em pilha ordenada alfabética por nome.
 * Struct Cliente: cod, nome, idade, saldo.
 * Regras:
 * - Sem código duplicado.
 * - Inserir sempre topo mantendo ordem alpha nomes (ex: inserir Maria em Ana/Nivaldo -> Ana/Maria/Nivaldo).
 * - Usar pilha AUX para ordenar/insert.
 * Lógica cadastrar:
 * 1. Lê dados novo cliente.
 * 2. Verifica cod dup? Não cadastra.
 * 3. Move CADASTRO para AUX até achar posição nome > novo.nome.
 * 4. Empilha novo.
 * 5. Restaura AUX em CADASTRO.
 * Menu loop "Cadastrar novo cliente?" PT-BR simples.
 */

void cadastraCliente(Pilha *cadastro) {
    Cliente novo;
    cout << "\n--- NOVO CADASTRO ---" << endl;
    cout << "Código: ";
    cin >> novo.cod;
    if (buscaCod(cadastro, novo.cod)) {
        cout << "ERRO: Código já existe!" << endl;
        return;
    }
    cin.ignore();
    cout << "Nome: ";
    getline(cin, novo.nome);
    cout << "Idade: ";
    cin >> novo.idade;
    cout << "Saldo inicial: ";
    cin >> novo.saldo;
    
    Pilha aux;
    // Passo 1: Desempilha CADASTRO para AUX até posição correta (nome alpha)
    while (!vaziaP(cadastro) && espiaP(cadastro).nome > novo.nome) {
        empilhaP(&aux, desempilhaP(cadastro));
    }
    
    // Passo 2: Empilha novo cliente
    empilhaP(cadastro, novo);
    
    // Passo 3: Restaura AUX de volta CADASTRO
    while (!vaziaP(&aux)) {
        empilhaP(cadastro, desempilhaP(&aux));
    }
    
    cout << "Cliente " << novo.nome << " cadastrado OK!" << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    cout << "=== CADASTRO BANCO BANPASSO (ORDEM ALFABÉTICA NOME) ===" << endl;
    cout << "Exemplo: Ana(1), Nivaldo(2), Otaviano(3) -> inserir Maria(4): Ana/Maria/Nivaldo/Otaviano" << endl << endl;
    
    Pilha cadastro;
    
    char continua;
    do {
        cadastraCliente(&cadastro);
        mostraP(&cadastro, "CADASTRO atual (topo primeiro)");
        cout << "\nCadastrar outro? (s/n): ";
        cin >> continua;
        cin.ignore();
    } while (continua == 's' || continua == 'S');
    
    cout << "\n=== FIM CADASTRO ===" << endl;
    destroiP(&cadastro);
    return 0;
}

