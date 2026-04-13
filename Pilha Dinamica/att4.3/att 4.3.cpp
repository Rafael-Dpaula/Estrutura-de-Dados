#include <iostream>
using namespace std;
#include "../pilha-dinamica.hpp"

void ordena(Pilha *p)
{
    Pilha ord, aux;
    while (!vaziaP(p))
    {
        int v = p->topo->dado;
        if (vaziaP(&ord) or v >= ord.topo->dado)
        {
            empilhaP(&ord, v);
            desempilhaP(p);
        }
        else
        {
            empilhaP(&aux, v);
            desempilhaP(p);

            while (!vaziaP(&aux))
            {
                if (ord.topo->dado >= aux.topo->dado)
                {
                    int vA = ord.topo->dado;
                    desempilhaP(&ord);
                    empilhaP(&ord, aux.topo->dado);
                    desempilhaP(&aux);
                    empilhaP(&ord, vA);
                }
            }
        }
    }

    // mostraP(&ord, "ord");
    // cout << endl
    //      << endl;

    bool troca = true;
    while (troca) {
        troca = false;
        while (!vaziaP(&ord)) {
            int atual = desempilhaP(&ord);
            if (!vaziaP(&aux)) {
                int anterior = desempilhaP(&aux);
                if (anterior > atual) {
                    empilhaP(&aux, atual);
                    empilhaP(&aux, anterior);
                    troca = true;
                } else {
                    empilhaP(&aux, anterior);
                    empilhaP(&aux, atual);
                }
            } else {
                empilhaP(&aux, atual);
            }
        }
        while (!vaziaP(&aux)) {
            empilhaP(&ord, desempilhaP(&aux));
        }
        destroiP(&aux);
    }

    mostraP(&ord, "ord");
    cout << endl
         << endl;

    //mostraP(&aux, "aux");

    destroiP(&ord);
    destroiP(&aux);
}

int main()
{

    cout << "Quantos valores deseja inserir na pilha?";
    int qtd;
    cin >> qtd;

    Pilha p;

    for (int i = 0; i < qtd; i++)
    {
        cout << "Informe o valor " << i + 1 << " a ser adicionado a pilha: ";
        int val;
        cin >> val;
        empilhaP(&p, val);
    }

    // mostraP(&p, "pilha");

    cout << endl
         << endl;

    ordena(&p);

    return EXIT_SUCCESS;
}