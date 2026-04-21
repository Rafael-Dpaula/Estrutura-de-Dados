#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
#include "pacote.hpp"
#include "pilha-dinamica.hpp"
#include "fila-dinamica.hpp"

void Adicionar_fila(Fila *f, int codigo, float peso, int fNome)
{
    Pacote pack;
    pack.codigo = codigo;
    pack.peso = peso;
    if(enfileiraF(f, pack))
    {
        cout<<"O pacote de c�digo=" << codigo <<" foi enfileirado na Fila " << fNome;
    }
    else
    {
        cout << "ERROR: o pacote n�o foi enfileirado."<<endl;
    }

}

void Ajustar_Peso_Media_fila(Fila *f, int cod1, int cod2)
{
    bool flag = false;
    if(!vaziaF(f))
    {
        float pack1, pack2;
        NoFila *no = f->inicio;
        while (no != NULL)
        {
            if(no and no->prox)
            {
                if((no->dado.codigo == cod1) and (no->prox->dado.codigo == cod2))
                {
                    pack1 = no->dado.peso;
                    pack2 = no->prox->dado.peso;
                    no->dado.peso = (pack1 + pack2) / 2;
                    no->prox->dado.peso = (pack1 + pack2) / 2;
                    cout << "Os pesos dos pacotes de codigo " << cod1 << " e " << cod2 << " foram ajustados pela m�dia."<<endl;
                    flag = true;
                    break;
                }
            }
            no = no->prox;

        }
    }
    if(flag)
        cout << "Os pesos dos pacotes de codigo "<< cod1 << " e "<< cod2 << " foram ajustados pela m�dia."<<endl;
    else
        cout << "Os pesos dos pacotes de codigo "<< cod1 << " e "<< cod2 << " N�O foram ajustados pela m�dia."<<endl;
}

void Fracionar_Pacotes_Pilha(Pilha *p, float pesoMax)
{
    Pilha aux;
    Pacote valor, pack;
    float sobra;
    while(!vaziaP(p))
    {
        valor = desempilhaP(p);

        sobra = valor.peso;
        while(sobra > pesoMax)
        {
            cout << sobra << endl;
            if(sobra > 0)
            {

                pack.peso = pesoMax;
                pack.codigo = valor.codigo;
                empilhaP(&aux, pack);
                sobra = sobra - pesoMax;

            }

        }
        valor.peso = sobra;
        empilhaP(&aux, valor);
    }



    while(!vaziaP(&aux))
    {
        empilhaP(p, desempilhaP(&aux));
    }
    cout << "Os pacotes da pilha foram fracionados respeitando o peso m�ximo de " << pesoMax << "!" << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Fila f1, f2;
    Pilha p;

    ifstream arq("entrada2.txt"); // arquivo de entrada
    if(!arq)
    {
        cout <<"ERROR: n�o foi poss�vel abrir o arquivo."<<endl;
        return 0;
    }
    string linha;
    while(getline(arq, linha))
    {
        stringstream ss(linha);
        string cmd;
        ss >> cmd;

        if(cmd == "ADICIONAR_FILA")
        {

            int fila, codigo;
            float peso;
            ss >> fila >> codigo >> peso;
            if(fila == 1)
                Adicionar_fila(&f1, codigo, peso, 1);
            else if(fila == 2)
                Adicionar_fila(&f2, codigo, peso, 2);
            cout << endl;
        }

        else if(cmd == "MOSTRAR_FILAS")
        {
            mostraF(&f1, "F1");
            mostraF(&f2, "F2");
        }
        else if(cmd == "REMOVER_FILA")
        {
            if(vaziaF(&f1) and vaziaF(&f2))
            {
                cout << "Erro ao remover da fila. Ambas est�o vazias!" << endl;
            }
            else
            {
                Pacote pack;
                float packF1, packF2;
                packF1 = espiaF(&f1);
                packF2 = espiaF(&f2);
                if(packF1 > packF2)
                {
                    if(vaziaF(&f1))
                        pack = desenfileiraF(&f2);
                    else
                        pack = desenfileiraF(&f1);
                }
                else if(packF2 > packF1)
                {
                    if(vaziaF(&f2))
                        pack = desenfileiraF(&f1);
                    else
                        pack = desenfileiraF(&f2);
                }
                else if(packF1 == packF2)
                {
                    if(vaziaF(&f1))
                        pack = desenfileiraF(&f2);
                    else
                        pack = desenfileiraF(&f1);
                }
                empilhaP(&p, pack);
                cout << "O pacote de codigo="<<pack.codigo << " foi retirado da fila e empilhado!"<<endl;
            }
        }
        else if(cmd == "MOSTRAR_PILHA")
        {
            mostraP(&p);
        }
        else if(cmd == "AJUSTAR_PESO_MEDIA_FILA")
        {
            int cod1, cod2;
            ss >> cod1 >> cod2;
            if(buscaF(&f1, cod1, cod2))
                Ajustar_Peso_Media_fila(&f1, cod1, cod2);
            else if(buscaF(&f2, cod1, cod2))
                Ajustar_Peso_Media_fila(&f2, cod1, cod2);
            else
                cout << "Os pesos dos pacotes de codigo "<< cod1 << " e "<< cod2 << " N�O foram ajustados pela m�dia."<<endl;
        }
        else if(cmd == "FRACIONAR_PACOTES_PILHA")
        {
            float pesoMax;
            ss >> pesoMax;
            Fracionar_Pacotes_Pilha(&p, pesoMax);
        }
    }
    return 0;
}
