#include <iostream>
#include <locale>
#include "pilha-dinamica.hpp"
using namespace std;

int tamanhoPilha(Pilha *p) {
    int tam = 0;
    NoPilha *no = p->topo;
    while (no != nullptr) {
        tam++;
        no = no->prox;
    }
    return tam;
}

void substituir(Pilha *p1, Pilha *p2, int i, int f) {
    // Substitui elementos da p1 entre posições i e f (0-based do topo?) pelos de p2
    // p2 permanece inalterada
    // Usa pilhas aux
    // Posições: assume i=0 topo, i crescente para base
    // Erro se i<0, f<0, i>f, i>=T, f>=T onde T=tamanho p1
    
    int T = tamanhoPilha(p1);
    if (i < 0 || f < 0 || i > f || i >= T || f >= T) {
        cout << "Erro: Intervalo inválido!" << endl;
        return;
    }
    
    // Copia p2 para aux_p2 (para não modificar original)
    Pilha aux_p2;
    NoPilha *no = p2->topo;
    while (no != nullptr) {
        empilhaP(&aux_p2, no->dado);
        no = no->prox;
    }
    
    // Desempilha p1 em 3 partes: antes i, entre i-f, depois f
    Pilha antes, meio, depois;
    int count = 0;
    while (!vaziaP(p1)) {
        int val = desempilhaP(p1);
        if (count < i) {
            empilhaP(&antes, val);
        } else if (count <= f) {
            // Ignora meio
        } else {
            empilhaP(&depois, val);
        }
        count++;
    }
    
    // Reconstrói p1: antes + p2 + depois
    // antes (reverse pois empilhado invertido)
    while (!vaziaP(&antes)) {
        empilhaP(p1, desempilhaP(&antes));
    }
    // + p2 from aux_p2
    while (!vaziaP(&aux_p2)) {
        empilhaP(p1, desempilhaP(&aux_p2));
    }
    // + depois
    while (!vaziaP(&depois)) {
        empilhaP(p1, desempilhaP(&depois));
    }
    
    destroiP(&antes);
    destroiP(&depois);
    destroiP(&aux_p2);
}

int main(void) 
{
    setlocale(LC_ALL, "Portuguese"); 
    Pilha p1, p2; 
 
    cout << "\n#Teste 1\n"; 
    empilhaP(&p1, 6); 
    empilhaP(&p1, 5); 
    empilhaP(&p1, 4); 
    empilhaP(&p1, 3); 
    empilhaP(&p1, 2); 
    empilhaP(&p1, 1); // topo 6 5 4 3 2 1 base? Wait, empilha topo 1 base 6?
    
    empilhaP(&p2, 300); 
    empilhaP(&p2, 200); 
    empilhaP(&p2, 100); // topo 300 200 100 base
    
    mostraP(&p1, "P1");
    mostraP(&p2, "P2");
    substituir(&p1, &p2, 2, 4); // substitui posições 2 a 4 por p2
    mostraP(&p1, "P1");
    mostraP(&p2, "P2"); 
    
    destroiP(&p1); 
    destroiP(&p2); 
    
    // Outros testes...
    
    return 0; 
}

