#include <iostream>
#include <string>

#include "estrutura.hpp"

using namespace std;

// Exercicio:
// Manipular uma lista encadeada com descritor que armazena registros do tipo Reuniao.
//
// A estrutura possui descritores:
// - ponteiro para o primeiro no
// - ponteiro para o ultimo no
// - numero de elementos
//
// Deve-se implementar:
// void dividirReunioesLongas(Lista *lista);
//
// Criterio:
// - Se duracao > 240, dividir a reuniao em duas partes:
//   1) primeira parte fica no no original com duracao ajustada para 240
//   2) segunda parte com duracao restante e inserida imediatamente apos a reuniao original
//
// Regras adicionais:
// - Nao e permitido o uso de estrutura de dados auxiliares.
// - Preservar integridade da lista com descritor e manter descritores consistentes.
//
// Como a solucao foi implementada:
// 1) Percorremos a lista com um ponteiro "atual".
// 2) Quando encontramos uma reuniao com duracao > 240:
//    - calculamos restante = duracao - 240
//    - ajustamos o no original para 240
//    - criamos um novo no com mesma titulo e duracao = restante
//    - inserimos o novo no imediatamente apos o no original
//    - atualizamos fim se a insercao ocorreu no final
//    - incrementamos tamanho
// 3) Atualizamos o ponteiro para continuar a partir do no inserido/seguinte.
//
// Como o codigo funciona passo a passo:
// - Criamos uma lista de reunioes de exemplo.
// - Exibimos o estado inicial.
// - Chamamos dividirReunioesLongas.
// - Exibimos o estado final.

void dividirReunioesLongas(Lista *lista)
{
    if (lista == nullptr)
        return;

    No *atual = lista->inicio;

    while (atual != nullptr)
    {
        if (atual->dado.duracao > 240)
        {
            int restante = atual->dado.duracao - 240;

            // Ajusta a duracao da primeira parte no no original
            atual->dado.duracao = 240;

            // Cria a segunda parte
            Reuniao segunda;
            segunda.titulo = atual->dado.titulo;
            segunda.duracao = restante;

            No *novo = new No();
            novo->dado = segunda;
            novo->prox = atual->prox;
            atual->prox = novo;

            if (novo->prox == nullptr)
                lista->fim = novo;

            lista->tamanho++;

            // Para nao reprocessar a mesma distancia infinitamente:
            // agora seguimos a partir do no que vem depois do novo.
            atual = novo->prox;
        }
        else
        {
            atual = atual->prox;
        }
    }
}

int main()
{
    Lista l;

    Reuniao r1;
    r1.titulo = "Reuniao A";
    r1.duracao = 260;

    Reuniao r2;
    r2.titulo = "Reuniao B";
    r2.duracao = 100;

    Reuniao r3;
    r3.titulo = "Reuniao C";
    r3.duracao = 500;

    insereFimL(&l, r1);
    insereFimL(&l, r2);
    insereFimL(&l, r3);

    cout << "Lista inicial:" << "\n";
    mostraL(&l);

    dividirReunioesLongas(&l);

    cout << "Lista apos dividir reunioes longas (>240):" << "\n";
    mostraL(&l);

    destroiL(&l);
    return 0;
}

