#include <iostream>
using namespace std;

#include "estrutura.hpp"

// Exercicio 13.6:
// Lista duplamente encadeada que armazena registros do tipo Reuniao (titulo e duracao em minutos).
// Dividir reunioes longas: se duracao exceder 240, criar uma segunda parte inserida logo apos
// a reuniao original. Proibido usar estruturas auxiliares.
//
// Este exercicio testa:
// - Manipulacao de ponteiros ant/prox durante insercao no meio.
// - Integridade da lista (inicio, fim, tamanho) apos insercoes.
//
// Como a solucao foi implementada:
// - Percorre a lista do inicio ao fim.
// - Quando encontra duracao > 240:
//   1) ajusta o duracao do no atual para 240
//   2) calcula o restante
//   3) insere um novo no imediatamente apos o atual com duracao restante
//   4) avanca corretamente para nao processar o novo no novamente.
//
// Funcionamento passo a passo:
// 1) Criar lista com algumas reunioes.
// 2) Mostrar antes.
// 3) Chamar dividirReunioesLongas.
// 4) Mostrar depois na ordem direta e inversa.

int main(void)
{
    Lista lista;

    Reuniao a;
    a.titulo = "ReuniaoA";
    a.duracao = 300;

    Reuniao b;
    b.titulo = "ReuniaoB";
    b.duracao = 200;

    Reuniao c;
    c.titulo = "ReuniaoC";
    c.duracao = 500;

    insereInicioL(&lista, c);
    insereInicioL(&lista, b);
    insereInicioL(&lista, a);

    cout << "\n#ANTES\n";
    mostraL(&lista, "lista normal   :");
    mostrarInversoL(&lista, "lista invertida:");

    cout << "\n#DEPOIS\n";
    dividirReunioesLongas(&lista);

    mostraL(&lista, "lista normal   :");
    mostrarInversoL(&lista, "lista invertida:");

    destroiL(&lista);
    return EXIT_SUCCESS;
}

