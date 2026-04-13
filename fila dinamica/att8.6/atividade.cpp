#include <iostream>
#include <iomanip>
#include "fila-dinamica.hpp"
using namespace std;

void deslocar(Fila *f, int k, int n) {
    // Função para deslocar n posições dos primeiros k elementos do início da fila
    // Só faz se n > 0 e (k + n) <= tamanho total da fila
    // Mantém ordem relativa dos elementos
    
    // Primeiro, verifica se é possível fazer o deslocamento
    if (n <= 0) return; // Não desloca se n <= 0
    
    // Conta o tamanho total da fila
    int tamanho = 0;
    NoFila *no = f->inicio;
    while (no != NULL) {
        tamanho++;
        no = no->prox;
    }
    
    if (k + n > tamanho || k <= 0) return; // Condição inválida, não faz nada
    
    // Cria filas auxiliares simples para separar partes
    Fila auxPrimeiros; // Primeiros k elementos
    Fila auxRestante; // Resto da fila
    
    // Separa os primeiros k elementos
    for (int i = 0; i < k; i++) {
        enfileiraF(&auxPrimeiros, desenfileiraF(f));
    }
    
    // Salva o restante
    NoFila *temp = f->inicio;
    while (temp != NULL) {
        enfileiraF(&auxRestante, temp->dado);
        temp = temp->prox;
    }
    destroiF(f); // Limpa original
    
    // Desloca os primeiros k: rotaciona n posições à direita dentro dos primeiros k+n? Mas lógica: desloca n pos dos primeiros k
    // Interpretação: os primeiros k são deslocados n pos para direita, circular
    // Ex: fila 10,1,3,5,90; k=3 n=1 -> primeiros 3: 10,1,3 -> desloca 1: 3,10,1 + resto 5,90 = 3,10,1,5,90
    
    // Para rotacionar à direita n pos: tira últimos n dos k e coloca no início
    Fila tempPrimeiros;
    // Copia k para temp
    no = auxPrimeiros.inicio;
    while (no != NULL) {
        enfileiraF(&tempPrimeiros, no->dado);
        no = no->prox;
    }
    
    // Tira últimos n e coloca no início novo
    Fila novosPrimeiros;
    for (int i = 0; i < n; i++) {
        // Desenfileira últimos: usa pilha aux ou reverse
        // Melhor: copia todos menos últimos n, depois adiciona últimos n no início
        // Para simplicidade, usa vetor aux temporário (permitido pois não é estrutura proibida, só para cálculo)
        
    int primeiros[k];
    int idx = 0;
    no = auxPrimeiros.inicio;
    while (no != NULL && idx < k) {
        primeiros[idx++] = no->dado;
        no = no->prox;
    }
    
    // Rotaciona à direita n: últimos n vão para frente
    Fila rotacionados;
    for (int i = k - n; i < k; i++) {
        enfileiraF(&rotacionados, primeiros[i]);
    }
    for (int i = 0; i < k - n; i++) {
        enfileiraF(&rotacionados, primeiros[i]);
    }
    
    // Coloca rotacionados de volta na f
    no = rotacionados.inicio;
    while (no != NULL) {
        enfileiraF(f, no->dado);
        no = no->prox;
    }
    destroiF(&rotacionados);
    
    // Adiciona restante
    no = auxRestante.inicio;
    while (no != NULL) {
        enfileiraF(f, no->dado);
        no = no->prox;
    }
    
    destroiF(&auxPrimeiros);
    destroiF(&auxRestante);
}

int main(void) 
{
    int k, n; 
    Fila f; 
    enfileiraF(&f, 10); 
    enfileiraF(&f, 1); 
    enfileiraF(&f, 3); 
    enfileiraF(&f, 5); 
    enfileiraF(&f, 90); 
  
    cout << "Teste 1\n";  
    mostraF(&f);  
    k=3; n=1; 
    deslocar(&f, k, n); 
    mostraF(&f); 
 
    cout << "\nTeste 2\n"; 
    mostraF(&f); 
    k=3; n=2; 
    deslocar(&f, k, n);  
    mostraF(&f); 
 
    cout << "\nTeste 3\n"; 
    mostraF(&f); 
    k=3; n=3; 
    deslocar(&f, k, n); 
    mostraF(&f); 
 
    cout << "\nTeste 4\n"; 
    mostraF(&f); 
    k=3; n=0; 
    deslocar(&f, k, n); 
    mostraF(&f);  
    
    cout << "\nTeste 5\n"; 
    mostraF(&f); 
    k=1; n=2; 
    deslocar(&f, k, n); 
    mostraF(&f); 
 
    cout << "\nTeste 6\n"; 
    mostraF(&f); 
    k=4; n=1; 
    deslocar(&f, k, n); 
    mostraF(&f); 
 
    destroiF(&f); 
    return 0; 
}
