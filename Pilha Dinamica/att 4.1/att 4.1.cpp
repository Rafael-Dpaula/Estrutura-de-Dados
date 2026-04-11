#include <iostream>
using namespace std;
#include "pilha.hpp"


float media(Pilha *p)
{
    if (!vaziaP(p))
    {
        int cont = 0;
        float soma = 0;
        NoPilha *topo = p->topo;
        while (topo != NULL)
        {
            soma += topo->dado;
            cont++;
            topo = topo->prox;
        }

        float media = soma / cont;
        return media;
    }
    return 0;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p;

    empilhaP(&p, 12);
    empilhaP(&p, 21);
    empilhaP(&p, 44);
    empilhaP(&p, 19);
    empilhaP(&p, 3);

    mostraP(&p, "pilha");

    cout << "Media: " << media(&p) << endl;

    return EXIT_SUCCESS;

} // final do main
