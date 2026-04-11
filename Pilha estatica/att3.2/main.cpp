#include<iostream>
using namespace std;
#include "pilha.hpp"

int main(){
    Pilha p;
    srand(time(NULL));
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