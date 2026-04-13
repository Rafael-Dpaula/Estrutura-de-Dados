#include <iostream>
#include <climits>
#include <locale>
#include "pilha.hpp"
using namespace std;

void removeMaiorMenor(Pilha *P) {
    // Esta função encontra o maior e o menor valor na pilha P e remove UM de cada
    // Mesmo se houver repetidos, remove apenas um de cada
    // A ordem dos outros elementos fica mantida
    // Usa pilha auxiliar para reconstruir sem os elementos removidos
    
    if (vaziaP(P) || P->topo < 1) {
        cout << "Pilha tem menos de 2 elementos!" << endl;
        return;
    }
    
    // Pilha auxiliar para reconstruir
    Pilha aux;
    inicializaP(&aux, P->tam);
    
    // Variáveis para encontrar o primeiro max e min (da base para topo? Mas remove primeiro encontrado desempilhando do topo)
    int maximo = INT_MIN;
    int minimo = INT_MAX;
    
    // Para encontrar, precisamos varrer, mas para remover correta ordem, desempilha tudo, pula um max e um min na primeira ocorrência
    bool removeu_max = false;
    bool removeu_min = false;
    
    // Desempilha tudo para aux, pulando um max e um min
    while (!vaziaP(P)) {
        int valor = desempilhaP(P);
        if (!removeu_max && valor == maximo) {
            removeu_max = true;
            // Não empilha este
            continue;
        }
        if (!removeu_min && valor == minimo) {
            removeu_min = true;
            continue;
        }
        empilhaP(&aux, valor);
    }
    
    // Problema: maximo e minimo não foram encontrados antes do primeiro loop
    // Correção: primeiro encontra max/min varrendo sem remover, depois remove
    
    // Primeiro loop para encontrar max/min
    Pilha temp;
    inicializaP(&temp, P->tam);
    int novo_max = INT_MIN;
    int novo_min = INT_MAX;
    while (!vaziaP(P)) {
        int valor = desempilhaP(P);
        empilhaP(&temp, valor);
        if (valor > novo_max) novo_max = valor;
        if (valor < novo_min) novo_min = valor;
    }
    
    // Volta do temp para P
    while (!vaziaP(&temp)) {
        empilhaP(P, desempilhaP(&temp));
    }
    destroiP(&temp);
    
    // Agora remove um max e um min do topo para baixo
    removeu_max = false;
    removeu_min = false;
    Pilha aux2;
    inicializaP(&aux2, P->tam);
    while (!vaziaP(P)) {
        int valor = desempilhaP(P);
        if (!removeu_max && valor == novo_max) {
            removeu_max = true;
            continue; // Remove este
        }
        if (!removeu_min && valor == novo_min) {
            removeu_min = true;
            continue;
        }
        empilhaP(&aux2, valor);
    }
    
    // Reconstrói P
    while (!vaziaP(&aux2)) {
        empilhaP(P, desempilhaP(&aux2));
    }
    destroiP(&aux2);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Pilha P;
    inicializaP(&P, 10);
    
    // Preenche para teste (base ... topo)
    empilhaP(&P, 4); // base
    empilhaP(&P, 3);
    empilhaP(&P, 6);
    empilhaP(&P, 3);
    empilhaP(&P, 5);
    empilhaP(&P, 9); // topo, max
    empilhaP(&P, 7);
    empilhaP(&P, 9);
    empilhaP(&P, 8); // novo topo
    
    cout << "Antes da remoção:" << endl;
    mostraP(&P);
    
    removeMaiorMenor(&P);
    
    cout << "Depois da remoção (removeu um 9 max e um 3 min):" << endl;
    mostraP(&P);
    
    destroiP(&P);
    
    return 0;
}

