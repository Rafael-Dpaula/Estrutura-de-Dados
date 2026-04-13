#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Documento
{
    string nome;
    int qtdPaginas;

    Documento()
    {
        nome = "";
        qtdPaginas = 0;
    }
};
#include "filacircular.hpp"

int main()
{
    stringstream icStream;
    string ic, ln;
    Fila n, p;
    ifstream arquivo("entrada.txt");
    if (!arquivo.good())
    {
        cout << "ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO" << endl;
        return 1;
    }
    while (!arquivo.eof())
    {
        cout << "-----------------------------" << endl;
        ln = "";
        getline(arquivo, ln);
        icStream = stringstream(ln);
        icStream >> ic;
        cout << "Comando: " << ic << endl;
        if (ic == "INICIALIZAR")
        {
            if (verificaInicializacaoF(&p) == true || verificaInicializacaoF(&n) == true)
            {
                destroiF(&p);
                destroiF(&n);
            }
            int tamFila;
            icStream >> tamFila;
            inicializaF(&n, tamFila);
            inicializaF(&p, tamFila);
            cout << "A fila P e N foram inicializadas com o tamanho " << tamFila << endl;
        }
        else if (ic == "MOSTRAR")
        {
            string fila;
            icStream >> fila;
            if (fila == "P")
            {
                if (!verificaInicializacaoF(&p))
                {
                    cout << "ERRO: INICIALIZAR FILA P" << endl;
                }
                else
                {
                    mostraF(&p);
                }
            }
            else if (fila == "N")
            {
                if (!verificaInicializacaoF(&n))
                {
                    cout << "ERRO: INICIALIZAR FILA N" << endl;
                }
                else
                {
                    mostraF(&n);
                }
            }
        }
        else if (ic == "IMPRIMIRDOC")
        {
            if (!verificaInicializacaoF(&n) or !verificaInicializacaoF(&p))
            {
                cout << "ERRO: INICIALIZAR FILAS 'P' E 'N'" << endl;
            }
            else
            {

                if (!vaziaF(&p))
                {
                    Documento imprime = desenfileiraF(&p);
                    cout << "O documento " << imprime.nome << " foi impresso" << endl;
                }
                else if (vaziaF(&p) and !vaziaF(&n))
                {
                    Documento imprime = desenfileiraF(&n);
                    cout << "O documento " << imprime.nome << " foi impresso" << endl;
                }
                else
                    cout << "NÃO HÁ DOCUMENTOS PARA IMPRIMIR" << endl;
            }
        }
        else if (ic == "ENFILEIRARDOC")
        {
            if (!verificaInicializacaoF(&n) or !verificaInicializacaoF(&p))
            {
                cout << "ERRO: INICIALIZAR FILAS 'P' E 'N'" << endl;
            }
            else
            {
                Documento doc;
                string fila;
                icStream >> doc.nome >> doc.qtdPaginas >> fila;
                if (fila == "P")
                    enfileiraF(&p, doc);
                else if (fila == "N")
                    enfileiraF(&n, doc);
                cout << "O documento " << doc.nome << " (" << doc.qtdPaginas << " pag) foi adicionado a fila " << fila << endl;
            }
        }
        else if (ic == "TOTALPAG")
        {
            cout << somaF(&n) + somaF(&p) << " página (s)" << endl;
        }
        else if (ic == "CONSULTAR"){
            string nome, fila;
            icStream >> nome >> fila;
            if(buscaF(&p, nome))
                cout << "O documento " << nome << " foi encontrado na fila P" << endl;
            else if(buscaF(&p, nome))
                cout << "O documento " << nome << " foi encontrado na fila N" << endl;
            else
                cout << "Documento não foi encontrado" << endl;
        }
    }
}

