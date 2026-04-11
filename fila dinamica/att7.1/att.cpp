#include <iostream>
using namespace std;
#include "../exemplo-fila-dinamica/fila-dinamica.hpp"
#include "../../Pilha Dinamica/pilha-dinamica.hpp"

int main()
{
    Fila f;
    int menu;

    
    while (menu != 0)
    {
        cout << "===== MENU =====" << endl;
        cout << "1 - INCLUIR NA FILA" << endl;
        cout << "2 - REMOVER DA FILA" << endl;
        cout << "3 - MOSTRAR FILA" << endl;
        cout << "4 - INVERTER FILA" << endl;
        cout << "0 - SAIR" << endl
             << endl;
        cout << "-----> ";
        cin >> menu;

        switch (menu)
        {
        case 0:
        {
            cout << "ALERT: encerrando programa." << endl;
            return 0;
            break;
        }
        case 1:
        {
            cout << "informe o valor: ";
            int val;
            cin >> val;
            enfileiraF(&f, val);
            break;
        }
        case 2:
        {
            int sai = desenfileiraF(&f);
            cout << "ALERT: o valor " << sai << " foi removido da fila." << endl;
            break;
        }
        case 3:
        {
            mostraF(&f);
            break;
        }
        case 4:
        {
            Pilha p;
            while (!vaziaF(&f))
            {
                empilhaP(&p, desenfileiraF(&f));
            }
            while (!vaziaP(&p))
            {
                enfileiraF(&f, desempilhaP(&p));
            }
            cout << "ALERT: fila invertida." << endl;
            break;
        }
        default:
        {
            cout << "ERRO: entrada inválida." << endl;
            break;
        }
        }
    }

    EXIT_SUCCESS;
}