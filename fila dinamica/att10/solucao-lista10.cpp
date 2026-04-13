#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
//#include <unistd.h>
using namespace std;

struct Pessoa
{
    string nome;
    char sexo;
    char tipo; //R ou L
    int qtd; // quantidade de peças
    Pessoa()
    {
        nome="";
        sexo=' ';
        tipo=' ';
        qtd = 0;
    }
};
#include "fila-dinamica.hpp"

int contF(Fila *f)
{
    int c=0;
    NoFila *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        c++;
        no = no->prox;
    }
    return c;
}

void menor(Fila *f1, Fila *f2, char sx, string *nome, int *qtd)
{
    NoFila *no;
    int cont =0;
    *qtd = 0;
    *nome = "";


    no = f1->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        if(no->dado.sexo == sx && (cont==0 || no->dado.qtd < (*qtd)  ))
        {
            cont++;
            *qtd = no->dado.qtd;
            *nome = no->dado.nome;
        }
        no = no->prox;
    }


    no = f2->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        if(no->dado.sexo == sx && (cont==0 || no->dado.qtd < (*qtd)  ))
        {
            cont++;
            *qtd = no->dado.qtd;
            *nome = no->dado.nome;
        }
        no = no->prox;
    }

}

void dadosFilas(Fila *f1, Fila *f2, int *qtdPessoas, float *percM, int *qtdLivros, int *qtdRoupas)
{
    NoFila *no;
    int contM =0;
    *qtdLivros = 0;
    *qtdRoupas = 0;
    *qtdPessoas = 0;

    no = f1->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        (*qtdPessoas)++;
        if(no->dado.sexo == 'M')
            contM++;
        if(no->dado.tipo == 'L')
            (*qtdLivros)+= no->dado.qtd;
        if(no->dado.tipo == 'R')
            (*qtdRoupas)+= no->dado.qtd;
        no = no->prox;
    }

    no = f2->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        (*qtdPessoas)++;
        if(no->dado.sexo == 'M')
            contM++;
        if(no->dado.tipo == 'L')
            (*qtdLivros)+= no->dado.qtd;
        if(no->dado.tipo == 'R')
            (*qtdRoupas)+= no->dado.qtd;
        no = no->prox;
    }

    if(*qtdPessoas==0)
        *percM = 0;
    else
        *percM = (contM * 100.0) / (*qtdPessoas);
}

void insereOrdenadoF(Fila* f, Pessoa d)
{
    Fila aux;
    bool add=false;

    while(!vaziaF(f))
    {
        Pessoa x = desenfileiraF(f);
        if(!add && x.qtd > d.qtd)
        {
           enfileiraF(&aux, d);
           add=true;
        }

        enfileiraF(&aux, x);
    }

    if(!add)
       enfileiraF(&aux, d);

    while(!vaziaF(&aux))
    {
        Pessoa x = desenfileiraF(&aux);
        enfileiraF(f, x);
    }
}

void mostraFOrdenada(Fila *f, string nome)
{

    Fila aux;
    NoFila *no;

    no = f->inicio;
    while (no != NULL )
    {
        insereOrdenadoF(&aux, no->dado);
        no = no->prox;
    }

    mostraF(&aux, nome);
    destroiF(&aux);
}


int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Fila f1, f2;
    string op, linha;
    stringstream strBuffer;
    bool atenderF1 = true;


    //comente as três linhas abaixo para exibir a saida no terminal
    //ofstream arqSaida("saidaEntrada2.txt");
    //streambuf *coutbuf = cout.rdbuf(); //salva o buffer de saida (cout)
    //cout.rdbuf(arqSaida.rdbuf());  //redireciona o cout para saidaCorrecao.txt !



    ifstream arq ("entrada.txt");
    int saida=0;

    if (!arq.is_open())
    {
        cout << "Erro: não foi possível abrir o arquivo texto.\n";
        return 0;
    }
     while(!arq.eof())
    {
        linha = ""; //IMPORTANTE
        getline(arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> op;

        if(op == "ADDFILA")
        {
            Pessoa d;
            strBuffer >> d.nome;
            strBuffer >> d.sexo;
            strBuffer >> d.tipo;
            strBuffer >> d.qtd;
            int conf1 = contF(&f1);
            int conf2 = contF(&f2);
            cout << ++saida << " - ";
            if(!buscaF(&f1, d.nome) && !buscaF(&f2, d.nome))
            {
                if(d.qtd<=0)
                    cout << "Erro: " << d.nome << " não foi enfileirado(a). Não há itens para serem doados.\n";
                else if( ( ((conf1-conf2)<3) && (d.qtd>10)) || ( (conf2-conf1)>=3) )
                {
                    enfileiraF(&f1, d);
                    cout << d.nome << " (qtd="<< d.qtd << ") foi adicionado(a) na fila F1\n";
                }
                else
                {
                    enfileiraF(&f2, d);
                    cout << d.nome << " (qtd="<< d.qtd << ") foi adicionado(a) na fila F2\n";
                }

            }
            else{
                cout << "Erro: " << d.nome << " já está em uma fila!\n";
            }

        }
        else if(op == "MOSTRAFILAS")
        {
            cout << ++saida << " -\n";
            mostraF(&f1, "F1");
            mostraF(&f2, "F2");
        }
        else if(op == "MOSTRADADOSFILAS")
        {
            int  qtdLivros, qtdRoupas, qtdPessoas;
            float percM;

            dadosFilas(&f1, &f2, &qtdPessoas, &percM, &qtdLivros, &qtdRoupas);
            cout << ++saida << " - ";
            cout << "Quantidade de pessoas: " << qtdPessoas << "; ";
            cout << "Percentual do sexo M: " << fixed << setprecision(2) << percM << "%; ";
            cout << "Quantidade de livros: " << qtdLivros << "; ";
            cout << "Quantidade de roupas: " << qtdRoupas << ";\n";


        }
        else if(op == "MOSTRAFILAORD")
        {
            string F;
            strBuffer >> F;
            cout << ++saida << " - ";
            if(F=="F1")
                mostraFOrdenada(&f1, "F1 Ordenada");
            else
                mostraFOrdenada(&f2, "F2 Ordenada");

        }
        else if(op == "MOSTRAMENORQTD")
        {
            string nome;
            int qtd;
            char sx;
            strBuffer >> sx;
            cout << ++saida << " - ";
            if(vaziaF(&f1) && vaziaF(&f2))
                cout << "Erro: filas vazias.\n";
            else
            {
                menor(&f1, &f2, sx, &nome, &qtd);
                cout << nome << " sexo("<< sx << ") possui a menor quantidade de itens (" << qtd << ")\n";
            }
        }

        else if(op == "REMOVEFILA")
        {
            cout << ++saida << " - ";
            if(vaziaF(&f1) && vaziaF(&f2))
                cout << "Erro: filas vazias.\n";
            else if(!vaziaF(&f1) && (atenderF1==true || vaziaF(&f2)) )
            {
                atenderF1 = false;
                Pessoa x = desenfileiraF(&f1);
                cout << x.nome << " foi atendido na fila F1.\n";
            }
            else
            {
                atenderF1 = true;
                Pessoa x = desenfileiraF(&f2);
                cout << x.nome << " foi atendido na fila F2.\n";
            }
        }



       // usleep(10000);
    } //fim while de leitura de arquivo




    //cout.rdbuf(coutbuf); //reseta o buffer de saida para o padrão novamente.
    arq.close();
    //arqSaida.close();


    //desalocar memória
    destroiF(&f1);
    destroiF(&f2);


    return EXIT_SUCCESS;

}//final do main

