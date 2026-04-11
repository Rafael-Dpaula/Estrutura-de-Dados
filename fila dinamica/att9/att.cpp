#include <iostream>
using namespace std;
#include "Cadastro.hpp"
#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"

struct Banco
{
    string nome;
    float saldoT;
    int totalCli;
    int devedores;

    Banco()
    {
        nome = "BanPasso";
        saldoT = 0;
        totalCli = 0;
        devedores = 0;
    }
} banco;

void ordena(Pilha *p)
{
    Pilha aux, ord;
    Cadastro atual;
    while (!vaziaP(p))
    {
        atual = desempilhaP(p);
        if (!vaziaP(&ord) and espiaP(&ord).nome > atual.nome)
        {
            empilhaP(&aux, desempilhaP(&ord));
        }

        empilhaP(&ord, atual);

        while (!vaziaP(&aux))
        {
            empilhaP(&ord, desempilhaP(&aux));
        }
    }
    while (!vaziaP(&ord))
    {
        empilhaP(p, desempilhaP(&ord));
    }
    destroiP(&aux);
    destroiP(&ord);
}

void dadosBanco(Pilha *p)
{
    if (!vaziaP(p))
    {
        NoPilha *no = p->topo;
        float soma = 0;
        int clientes = 0, devedores = 0;
        while (no != NULL)
        {
            soma += no->dado.saldo;
            clientes++;
            if (no->dado.saldo < 0)
                devedores++;
            no = no->prox;
        }
        banco.totalCli = clientes;
        banco.saldoT = soma;
        banco.devedores = devedores;
    }
}

void salvar(Pilha *p, int codigo, float saldo)
{
    if (!vaziaP(p))
    {
        NoPilha *no = p->topo;
        while (no->dado.codigo != codigo)
        {
            no = no->prox;
        }
        no->dado.saldo = saldo;
    }
}

int main()
{
    Pilha p;
    Fila fP, fN, fD;

    int menu;
    bool flag = false;
    do
    {

        cout << "==== MENU ====" << endl;
        cout << "1 - Cadastrar cliente" << endl;
        cout << "2 - Adicionar cliente a fila" << endl;
        cout << "3 - Mostrar Pilhas ou Filas" << endl;
        cout << "4 - Atender cliente na fila" << endl;
        cout << "5 - Dados do banco" << endl;
        cout << "0 - Sair" << endl;
        cout << "----> ";
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            Cadastro cli;
            cout << "==== CADASTRO ====" << endl;
            cout << "Código: ";
            cin >> cli.codigo;
            while (buscaP(&p, cli.codigo))
            {
                cout << "ERROR: código repetido detectado." << endl;
                cout << "Código: ";
                cin >> cli.codigo;
            }
            cout << "Nome: ";
            cin.ignore();
            getline(cin, cli.nome);
            cout << "Idade: ";
            cin >> cli.idade;
            cout << "Saldo: ";
            cin >> cli.saldo;
            empilhaP(&p, cli);
            ordena(&p);
            flag = true;
            break;
        }

        case 2:
        {
            if (!flag)
            {
                cout << "ALERT: nenhum cliente cadastrado" << endl;
                break;
            }
            Cadastro cli;
            int cod;
            cout << "==== ADICIONAR CLIENTE A FILA ====" << endl;
            cout << "código: ";
            cin >> cod;
            if (!buscaP(&p, cod))
            {
                cout << "ERROR: codigo inexistente." << endl;
                break;
            }
            cli = encontraP(&p, cod);

            if (buscaF(&fD, cli) or buscaF(&fP, cli) or buscaF(&fN, cli))
            {
                cout << "ALERT: cliente já está na fila" << endl;
                break;
            }
            if (cli.idade >= 60)
            {
                cout << "ALERT: transferindo para fila prioritária" << endl;
                enfileiraF(&fP, cli);
            }
            else if (cli.idade < 60 and cli.saldo >= 0)
            {
                cout << "ALERT: transferindo para fila Não-Prioritária" << endl;
                enfileiraF(&fN, cli);
            }
            else if (cli.idade < 60 and cli.saldo < 0)
            {
                cout << "ALERT: transferindo para fila Devedores" << endl;
                enfileiraF(&fD, cli);
            }

            break;
        }

        case 3:
        {
            if (!flag)
            {
                cout << "ALERT: nenhum cliente cadastrado" << endl;
                break;
            }
            cout << "==== MOSTRAR ====" << endl;
            cout << "Pilhas(P) ou Filas(F): ";
            char op;
            cin >> op;
            if (op == tolower('p'))
            {
                mostraP(&p, "Cadastros");
            }
            else if (op == tolower('f'))
            {
                mostraF(&fP, "Fila P");
                cout << endl;
                mostraF(&fN, "Fila N");
                cout << endl;
                mostraF(&fD, "Fila D");
            }

            break;
        }

        case 4:
        {
            if (!flag)
            {
                cout << "ALERT: nenhum cliente cadastrado" << endl;
                break;
            }
            Cadastro cli;
            cout << "==== ATENDIMENTO ====" << endl;
            if (!vaziaF(&fP))
            {
                cli = desenfileiraF(&fP);
            }
            else if (!vaziaF(&fN) and vaziaF(&fP))
            {
                cli = desenfileiraF(&fN);
            }
            else if (!vaziaF(&fD) and vaziaF(&fP) and vaziaF(&fN))
            {
                cli = desenfileiraF(&fD);
            }
            else
            {
                cout << "ALERT: não há cliente nas filas" << endl;
                break;
            }

            cout << "1 - Saque\n2 - Depósito" << endl;
            cout << "---->";
            int op;
            cin >> op;

            if (op == 1)
            {
                float valor;
                cout << "Qual o valor a ser sacado? ";
                cin >> valor;
                if (valor > (banco.saldoT * 0.8))
                {
                    cout << "ALERT: valor de saque supera o limite do banco de: " << banco.saldoT * 0.8 << "R$" << endl;
                    do
                    {
                        cout << "Qual o valor a ser sacado? ";
                        cin >> valor;
                    } while (valor > (banco.saldoT * 0.8));
                }
                cli.saldo = cli.saldo - valor;
                cout << endl
                     << "ALERT: foi realizado o saque de " << valor << " da conta do cliente: " << cli.nome << " | codigo: " << cli.codigo << endl;
            }
            else if (op == 2)
            {
                float valor;
                cout << "Qual o valor a ser depositado? ";
                cin >> valor;
                if (valor < 0)
                {
                    cout << "ALERT: valor a ser depositado deve ser positivo" << endl;
                    do
                    {
                        cout << "Qual o valor a ser depositado? ";
                        cin >> valor;
                    } while (valor < 0);
                }
                cli.saldo = cli.saldo + valor;
                cout << endl
                     << "ALERT: foi realizado o deposito de " << valor << " da conta do cliente: " << cli.nome << " | codigo: " << cli.codigo << endl;
            }
            else
                cout << "ERROR: opção inválida";
            salvar(&p, cli.codigo, cli.saldo);

            break;
        }

        case 5:
        {
            if (!flag)
            {
                cout << "ALERT: nenhum cliente cadastrado" << endl;
                break;
            }

            cout << "==== DADOS DO BANCO ====" << endl;
            cout << banco.nome << ":" << endl;
            cout << "Total de clientes: " << banco.totalCli << endl;
            cout << "Total de devedores: " << banco.devedores << endl;
            cout << "Saldo total: " << banco.saldoT << endl;
            cout << "Saldo médio: " << banco.saldoT / banco.totalCli << endl;
            break;
        }

        case 0:
        {
            cout << "ALERT: encerrando programa." << endl;
            break;
        }
        default:
        {
            cout << "ERROR: entrada inválida" << endl;
            break;
        }
        }

        dadosBanco(&p);
    } while (menu != 0);

    EXIT_SUCCESS;
}