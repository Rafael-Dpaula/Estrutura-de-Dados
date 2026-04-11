#include <iostream>
using namespace std;
#include "pilha.hpp"

bool testeP2P(Pilha *p1, Pilha *p2)
{
    if (!vaziaP(p1) and !vaziaP(p2))
    {
        if (p1->tam == p2->tam)
        {
            bool igual = true;
            for (int i = p1->topo; i > p2->base; i--)
            {
                if (p1->dados[i] != p2->dados[i])
                {
                    igual = false;
                }
            }
            return igual;
        }
        else
            cout << "Pilha com tamanhos diferentes!" << endl;
    }
    else
        cout << "Pilha vazia!" << endl;
    return false;
}

int main()
{
    Pilha p1, p2;
    srand(time(NULL));
    inicializaP(&p1, 4);
    inicializaP(&p2, 4);
    empilhaP(&p1, 100);
    empilhaP(&p1, 101);
    empilhaP(&p1, 102);
    empilhaP(&p1, 103);
    //codigo de merda!
    empilhaP(&p2, 100);
    empilhaP(&p2, 101);
    empilhaP(&p2, 102);
    empilhaP(&p2, 103);

    mostraP(&p1);
    cout << endl << endl;
    mostraP(&p2);

    if(testeP2P(&p1, &p2))
        cout << "Pilhas idênticas." << endl;
    else
        cout << "Pilhas diferentes." << endl;

}