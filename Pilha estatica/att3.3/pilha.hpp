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

void inicializaP(Pilha *p, int tam);
bool cheiaP(Pilha *p);
bool vaziaP(Pilha *p);
bool empilhaP(Pilha *p, int valor);
int desempilhaP(Pilha *p);
int espiaP(Pilha *p);
void mostraP(Pilha *p);
void destroiP(Pilha *p);
bool buscaP(Pilha *p, Pilha *aux, int valor);
void estatisticasP(Pilha *p, int *maior, int *menor, float *media);

/**
 * Ex3 Lista3: verifica se P1 e P2 iguais (mesmos elementos mesma ordem topo-base).
 * Usa pilhas temp preserve originais: desemp P1 P2 to temp compare seq, restore temp to P1 P2.
 * Retorna true se tam/elementos idênticos.
 */

// Implementações...
void inicializaP(Pilha *p, int tam) {
    p->base = -1;
    p->topo = -1;
    p->tam = tam;
    p->dados = new int[tam];
}

bool cheiaP(Pilha *p) {
    return p->topo == p->tam - 1;
}

bool vaziaP(Pilha *p) {
    return p->topo == p->base;
}

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

int espiaP(Pilha *p) {
    int valor = 0;
    if (!vaziaP(p)) valor = p->dados[p->topo];
    return valor;
}

void mostraP(Pilha *p) {
    cout << "topo ";
    if (!vaziaP(p)) {
        for (int i = p->topo; i > p->base; i--) cout << p->dados[i] << " ";
    } else cout << "vazia";
    cout << " base" << endl;
}

void destroiP(Pilha *p) {
    if (p->dados) delete[] p->dados;
    p->dados = NULL;
    p->tam = 0;
    p->topo = p->base = -1;
}

bool pilhasIguais(Pilha *p1, Pilha *p2) {
    /**
     * Passo1: cria temps mesmo tam P1 P2 para backup.
     */
    Pilha temp1, temp2;
    inicializaP(&temp1, p1->tam);
    inicializaP(&temp2, p2->tam);
    
    /**
     * Passo2: desemp P1 P2 paralelo, emp temps, compare v1==v2 cada par topo.
     * Para se tam diferente (um esvazia primeiro).
     */
    bool igual = true;
    while (!vaziaP(p1) && !vaziaP(p2)) {
        int v1 = desempilhaP(p1);  // Tira topo P1
        int v2 = desempilhaP(p2);  // Tira topo P2
        empilhaP(&temp1, v1);      // Backup temp1
        empilhaP(&temp2, v2);      // Backup temp2
        if (v1 != v2) igual = false;  // Diferente? false
    }
    if (!vaziaP(p1) || !vaziaP(p2)) igual = false;  // Tam diferente?
    
    /**
     * Passo3: restore temps back para P1 P2 (mesma ordem pois double LIFO reverse).
     */
    while (!vaziaP(&temp1)) empilhaP(p1, desempilhaP(&temp1));
    while (!vaziaP(&temp2)) empilhaP(p2, desempilhaP(&temp2));
    destroiP(&temp1);
    destroiP(&temp2);
    return igual;
}

/* Base funcs comentadas acima, att3.3 completa para pilhasIguais preserve. */

#endif

