#ifndef FILA_CIRCULAR_HPP
#define FILA_CIRCULAR_HPP

// Esta é a definição da estrutura para Fila Circular Estática
// Fila circular é uma fila que usa um array fixo, onde o final conecta ao início
// Usamos índices 'inicio' e 'fim' que 'andam' em círculo usando % tam
// 'total' conta quantos elementos tem na fila realmente

#include <iostream>
using namespace std;

struct Documento {
    string nome;     // Nome do documento para impressão
    int qtdPaginas;  // Número de páginas do documento
};

struct Fila {
    int tam;    // Tamanho máximo do array (capacidade da fila)
    int total;  // Quantidade atual de documentos na fila
    int inicio; // Índice onde está o primeiro documento (frente da fila)
    int fim;    // Índice onde será adicionado o próximo documento (trás da fila)
    Documento *dados; // Array dinâmico que guarda os documentos

    Fila() : tam(0), total(0), inicio(0), fim(0), dados(nullptr) {} // Construtor: fila vazia não inicializada
};

void inicializaF(Fila* f, int tam) {
    // Esta função prepara a fila para uso
    // 1. Define o tamanho máximo do array
    // 2. Zera contadores (total=0 significa vazia)
    // 3. Posiciona início e fim no começo do array
    // 4. Aloca memória para o array de documentos
    
    f->tam = tam;
    f->total = 0;
    f->inicio = 0;
    f->fim = 0;
    f->dados = new Documento[tam];
}

bool verificaInicializacaoF(Fila* f) {
    // Verifica se a fila já foi preparada com inicializaF
    // Retorna true se dados != nullptr (memória alocada)
    return f->dados != nullptr;
}

void destroiF(Fila* f) {
    // Limpa a fila completamente para reutilizar ou finalizar
    // 1. Zera todos os contadores
    // 2. Libera a memória do array para evitar vazamento
    // 3. Define dados como nullptr para marcar não inicializada
    
    f->total = 0;
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
    if (f->dados) {
        delete[] f->dados;
        f->dados = nullptr;
    }
}

bool vaziaF(Fila* f) {
    // Fila vazia quando não tem nenhum elemento (total == 0)
    // Não depende dos índices, só do contador total
    return f->total == 0;
}

bool cheiaF(Fila* f) {
    // Fila cheia quando tem elementos iguais ao tamanho máximo
    return f->total == f->tam;
}

bool enfileiraF(Fila* f, Documento doc) {
    // Adiciona um documento no FINAL da fila (trás)
    // Pré-condições: fila inicializada e não cheia
    // 1. Coloca o doc na posição 'fim'
    // 2. Avança 'fim' em círculo: (fim + 1) % tam
    // 3. Incrementa total
    // Retorna true se sucesso
    
    if (!verificaInicializacaoF(f) || cheiaF(f)) return false;
    f->dados[f->fim] = doc;
    f->fim = (f->fim + 1) % f->tam;
    f->total++;
    return true;
}

Documento desenfileiraF(Fila* f) {
    // Remove e retorna o documento do INÍCIO da fila (frente)
    // Pré-condição: não vazia (se vazia, retorna doc vazio)
    // 1. Pega o doc na posição 'inicio'
    // 2. Avança 'inicio' em círculo: (inicio + 1) % tam  
    // 3. Decrementa total
    
    Documento doc = {\"\", 0};
    if (vaziaF(f)) return doc;
    doc = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->tam;
    f->total--;
    return doc;
}

void mostraF(Fila* f) {
    // Mostra todos documentos da fila na ordem (do início ao fim)
    // Começa em 'inicio' e percorre 'total' elementos, avançando em círculo
    // Se vazia, mostra mensagem específica
    
    if (vaziaF(f)) {
        cout << \"Fila vazia\" << endl;  // CORRIGIDO para match PDF sample
        return;
    }
    int idx = f->inicio;
    for (int i = 0; i < f->total; i++) {
        cout << f->dados[idx].nome;
        if (i < f->total - 1) cout << \", \";
        idx = (idx + 1) % f->tam;
    }
    cout << endl;
}

int somaF(Fila* f) {
    // Calcula soma de páginas de TODOS documentos na fila
    // Percorre do início ao fim em círculo somando qtdPaginas
    
    int s = 0;
    if (vaziaF(f)) return 0;
    int idx = f->inicio;
    for (int i = 0; i < f->total; i++) {
        s += f->dados[idx].qtdPaginas;
        idx = (idx + 1) % f->tam;
    }
    return s;
}

bool buscaF(Fila* f, string nome) {
    // Procura um documento pelo nome na fila
    // Percorre do início ao fim em círculo comparando nomes
    // Retorna true se achar
    
    if (vaziaF(f)) return false;
    int idx = f->inicio;
    for (int i = 0; i < f->total; i++) {
        if (f->dados[idx].nome == nome) return true;
        idx = (idx + 1) % f->tam;
    }
    return false;
}

#endif
