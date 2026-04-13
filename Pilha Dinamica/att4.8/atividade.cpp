#include "pilha.hpp"

/**
 * att4.8 - Lista 4 exercício 8: verificaIntervalosInversos - [i1-f1] P1 == reverse [i2-f2] P2?
 * Posições topo-base: 0=topo, T-1=base.
 * Valida: i>=0, f>=0, f>=i, f<T (T=tamanho).
 * Preserva P1 P2 inalterados.
 * Lógica com auxs:
 * 1. Copia prefixo P1 até i1 para temp1
 * 2. Copia [i1..f1] para interval1 (pop f1-i1+1 elems)
 * 3. Copia resto P1 para temp1 resto, restaura P1
 * 4. Mesmo para P2 -> interval2
 * 5. Inverte interval2 in aux_inv
 * 6. Compara interval1 == aux_inv elem-por-elem sem pop
 * Ex PDF: P1 topo[-1,20,10,5] i1=1 f1=2 [20,10] , P2 topo[10,20,-1,5] i2=0 f2=1 [10,20] reverse [20,10] == sim
 */

bool verificaIntervalosInversos(Pilha *p1, Pilha *p2, int i1, int f1, int i2, int f2) {
    int t1 = tamanhoP(p1), t2 = tamanhoP(p2);
    
    // Valida intervalos
    if (i1 < 0 || f1 < 0 || f1 < i1 || f1 >= t1 || i2 < 0 || f2 < 0 || f2 < i2 || f2 >= t2) return false;
    
    // Copia interval [i,f] para aux sem alterar original
    auto copiaIntervalo = [](Pilha *orig, int i, int f, Pilha *interval) {
        Pilha temp;
        // Pula i elems (move temp)
        for (int k = 0; k < i; k++) empilhaP(&temp, desempilhaP(orig));
        // Copia [i..f] to interval (reverse ordem!)
        for (int k = i; k <= f; k++) empilhaP(interval, desempilhaP(orig));
        // Restaura resto orig de temp reverse
        while (!vaziaP(&temp)) empilhaP(orig, desempilhaP(&temp));
    };
    
    Pilha int1, int2;
    copiaIntervalo(p1, i1, f1, &int1);
    copiaIntervalo(p2, i2, f2, &int2);
    
    // Inverte int2 para comparar (move int2 -> inv reverse)
    Pilha inv2;
    while (!vaziaP(&int2)) empilhaP(&inv2, desempilhaP(&int2));
    
    // Compara int1 == inv2 (mesmo tamanho já)
    bool igual = true;
    NoPilha *n1 = int1.topo, *n2 = inv2.topo;
    while (n1 && n2) {
        if (n1->dado != n2->dado) {
            igual = false;
            break;
        }
        n1 = n1->prox;
        n2 = n2->prox;
    }
    
    // Limpa aux
    destroiP(&int1); destroiP(&int2); destroiP(&inv2);
    
    return igual;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    cout << "=== VERIFICA INTERVALOS INVERSOS P1 P2 ===" << endl;
    cout << "Ex: P1 topo[-1,20,10,5] i1=1 f1=2 [20,10]" << endl;
    cout << "P2 topo[10,20,-1,5] i2=0 f2=1 [10,20] reverse== [20,10] SIM" << endl << endl;
    
    // Demo PDF
    Pilha p1, p2;
    empilhaP(&p1, 5); empilhaP(&p1, 10); empilhaP(&p1, 20); empilhaP(&p1, -1); // topo -1
    empilhaP(&p2, 5); empilhaP(&p2, -1); empilhaP(&p2, 20); empilhaP(&p2, 10); // topo 10
    
    mostraP(&p1, "P1");
    mostraP(&p2, "P2");
    
    int i1=1, f1=2, i2=0, f2=1;
    cout << "Interval P1[" << i1 << "-" << f1 << "] vs reverse P2[" << i2 << "-" << f2 << "]: ";
    cout << (verificaIntervalosInversos(&p1, &p2, i1,f1,i2,f2) ? "SIM" : "NAO") << endl;
    
    mostraP(&p1, "P1 após (inalterada)");
    mostraP(&p2, "P2 após (inalterada)");
    
    cout << "=== FIM ===" << endl;
    
    destroiP(&p1); destroiP(&p2);
    return 0;
}

