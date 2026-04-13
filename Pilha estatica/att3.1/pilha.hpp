#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iostream>
using std::cout;
using std::endl;
#define NULL 0

/**
 * att3.1 - Lista 3 exercício 1: Pilha estática base + buscaValor.
 * Struct int dados, funcs básicas + busca usa aux preserve P.
 * Comentários simples português brasileiro explicando cada linha/função.
 */

struct Pilha {
    int tam;     // Tamanho máximo alocado
    int base;    // Posição base (-1 inicial)
    int topo;    // Posição topo elemento (-1 vazia)
    int *dados;  // Vetor dinâmico elementos
    Pilha() : tam(0), base(-1), topo(-1), dados(NULL) {}  // Construtor inicia tudo zero
};

// Função inicializa: aloca vetor tam, seta base/topo -1
void inicializaP(Pilha *p, int tam) {
    p->base = -1;
    p->topo = -1;
    p->tam = tam;
    p->dados = new int[tam];  // Aloca memória vetor tamanho tam
}

// Cheia: topo no final vetor
bool cheiaP(Pilha *p) {
    return p->topo == p->tam - 1;
}

// Vazia: topo == base
bool vaziaP(Pilha *p) {
    return p->topo == p->base;
}

// Empilha (push): se não cheia, topo++, coloca valor
bool empilhaP(Pilha *p, int valor) {
    if (cheiaP(p)) return false;  // Não empilha se cheia
    p->topo++;
    p->dados[p->topo] = valor;
    return true;
}

// Desempilha (pop): pega topo, topo--, retorna valor (0 se vazia)
int desempilhaP(Pilha *p) {
    int valor = 0;
    if (!vaziaP(p)) {
        valor = p->dados[p->topo];
        p->topo--;
    }
    return valor;
}

// Espia topo sem tirar
int espiaP(Pilha *p) {
    int valor = 0;
    if (!vaziaP(p)) valor = p->dados[p->topo];
    return valor;
}

// Mostra: topo ... base ou 'vazia'
void mostraP(Pilha *p) {
    cout << "topo ";
    if (!vaziaP(p)) {
        for (int i = p->topo; i > p->base; i--) {  // Loop descendente topo->base
            cout << p->dados[i] << " ";
        }
    } else {
        cout << "vazia";
    }
    cout << " base" << endl;
}

// Destroi: libera dados
void destroiP(Pilha *p) {
    if (p->dados) delete[] p->dados;
    p->dados = NULL;
    p->tam = 0;
    p->topo = p->base = -1;
}

// Ex1: busca valor V em P usa AUX preserve P
// Desemp P emp AUX check V, restore AUX to P
bool buscaValor(Pilha *p, int valor) {
    Pilha aux;  // AUX mesmo tam P
    inicializaP(&aux, p->tam);
    
    bool encontrou = false;
    // Passo1: desemp P -> emp AUX, check cada
    while (!vaziaP(p)) {
        int v = desempilhaP(p);  // Tira topo P
        empilhaP(&aux, v);       // Coloca em AUX
        if (v == valor) {        // Achou?
            encontrou = true;
            // Pode break ou continuar (PDF break OK)
        }
    }
    
    // Passo2: restore AUX -> P
    while (!vaziaP(&aux)) {
        empilhaP(p, desempilhaP(&aux));
    }
    
    destroiP(&aux);
    return encontrou;  // true se achou
}

#endif

