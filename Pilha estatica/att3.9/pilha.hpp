#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iostream>
using std::cout;
using std::endl;
#define NULL 0

struct Pilha {
    int tam;
    int base;
    int topo;
    int *dados;
    Pilha() : tam(0), base(-1), topo(-1), dados(NULL) {}
};

void inicializaP(Pilha *p, int tam) {
    p->base = -1;
    p->topo = -1;
    p->tam = tam;
    p->dados = new int[tam];
}

bool cheiaP(Pilha *p) { return p->topo == p->tam - 1; }
bool vaziaP(Pilha *p) { return p->topo == p->base; }

bool empilhaP(Pilha *p, int valor) {
    if (cheiaP(p)) return false;
    p->topo++;
    p->dados[p->topo] = valor;
    return true;
}

int desempilhaP(Pilha *p) {
    int valor = 0;
    if (!vaziaP(p)) {
        valor = p->dados[p->topo];
        p->topo--;
    }
    return valor;
}

void destroiP(Pilha *p) {
    if (p->dados) delete[] p->dados;
    p->dados = NULL;
}

// Ex9: string decToBin(int n) div2 emp resto, desemp print reverse
string decToBin(int n);

string decToBin(int n) {
    Pilha pilha;
    inicializaP(&pilha, 32); // Máx 32 bits
    if (n == 0) return "0";
    
    while (n > 0) {
        empilhaP(&pilha, n % 2);
        n /= 2;
    }
    
    string bin = "";
    while (!vaziaP(&pilha)) bin += '0' + desempilhaP(&pilha);
    
    destroiP(&pilha);
    return bin;
}

#endif

