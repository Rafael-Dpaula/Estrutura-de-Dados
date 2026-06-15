// Struct para avião do exercício 4 lista5
// Representa um avião com código, empresa e número de passageiros
// Usado na fila do aeroporto

#include <string>
#include <iostream>
using namespace std;

struct Aviao
{
    string codigo;   // Código único do avião (ex: "AA123")
    string empresa;  // Nome da empresa (ex: "Latam")
    int passageiros; // Número de passageiros a bordo

    // Construtor vazio para inicializações seguras
    Aviao() : codigo(""), empresa(""), passageiros(0) {}

    // Função para mostrar detalhes do avião de forma clara
    void mostrar()
    {
        cout << "Código: " << codigo
             << " | Empresa: " << empresa
             << " | Passageiros: " << passageiros << endl;
    }
};

// Função para mostrar detalhes do avião de forma clara
void mostrar(Aviao a)
{
    cout << "Código: " << a.codigo
         << " | Empresa: " << a.empresa
         << " | Passageiros: " << a.passageiros << endl;
};
