#include <iostream>
#include <cstdlib> // Para srand/rand
#include <ctime>   // Para time
using namespace std;
#include "pilha.hpp"

/**
 * att3.2 - Lista 3 exercício 2: Estatísticas da pilha (maior, menor, média).
 * Regras: estatisticasP preenche *maior, *menor, *media via ref, pilha inalterada.
 * hpp já tem func completa (loop topo-base sem aux, soma/tam).
 * main: preenche rand, mostra, chama estatisticasP, print resultados.
 */

int main(){
    Pilha p;
    srand(time(NULL)); // Semente para rand variado
    inicializaP(&p, 6);
    empilhaP(&p, rand()%100);
    empilhaP(&p, rand()%100);
    empilhaP(&p, rand()%100);
    empilhaP(&p, rand()%100);
    empilhaP(&p, rand()%100);
    empilhaP(&p, rand()%100);
    mostraP(&p);
    
    int maior, menor;
    float media;

    estatisticasP(&p, &maior, &menor, &media);
    cout << "maior:" << maior << endl;
    cout << "menor:" << menor << endl;
    cout << "media:" << media << endl;
}