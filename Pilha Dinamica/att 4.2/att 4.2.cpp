#include <iostream>
using namespace std;
#include "pilha.hpp"

void inverterFrase(Pilha *p){
    cout << "Digite uma frase: ";
    string frase;
    getline(cin, frase);
    frase+=" ";
    for(int i = 0; frase[i] != '\0'; i++){
        if(frase[i] != ' '){
            empilhaP(p, frase[i]);
        }
        else{
            empilhaP(p, frase[i]);
            while(!vaziaP(p)){
                cout << desempilhaP(p);
            }
        }
    }
    cout << endl;

}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p;

    inverterFrase(&p);
    
    return EXIT_SUCCESS;

} // final do main
