#ifndef FILA_CIRCULAR_HPP
#define FILA_CIRCULAR_HPP

// Arquivo cabeçalho para Fila Circular Estática
// Esta estrutura usa um vetor fixo para simular fila circular com início e fim modulados
// Não usa bibliotecas de fila, tudo manual para entender o funcionamento passo a passo

struct Fila {
    int tam;     // Tamanho máximo do vetor (capacidade da fila)
    int total;   // Número atual de elementos na fila
    int inicio;  // Índice onde está o primeiro elemento (frente da fila)
    int fim;     // Índice onde será inserido o próximo elemento (trás da fila)
    int *dados;  // Vetor que armazena os valores inteiros da fila

    Fila() : tam(0), total(0), inicio(0), fim(0), dados(nullptr) {}  // Construtor: inicializa tudo vazio
};

// Função para inicializar a fila com um tamanho específico
// Aloca memória para o vetor dados e zera contadores
void inicializaF(Fila* f, int tam) {
    f->tam = tam;
    f->total = 0;
    f->inicio = 0;
    f->fim = 0;
    f->dados = new int[tam];  // Cria o vetor com 'tam' posições
}

// Verifica se a fila foi inicializada corretamente (dados não nulo)
bool verificaInicializacaoF(Fila* f) {
    return f->dados != nullptr;
}

// Destrói a fila: libera memória e zera tudo
void destroiF(Fila* f) {
    if (f->dados) {
        delete[] f->dados;
        f->dados = nullptr;
    }
    f->total = 0;
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
}

// Verifica se a fila está vazia (nenhum elemento)
bool vaziaF(Fila* f) {
    return f->total == 0;
}

// Verifica se a fila está cheia (total == tam)
bool cheiaF(Fila* f) {
    return f->total == f->tam;
}

// Insere (enfileira) um valor no final da fila (trás)
// Usa módulo % para circular: se fim==tam, volta a 0
// Retorna true se sucesso, false se cheia ou não inicializada
bool enfileiraF(Fila* f, int valor) {
    if (!verificaInicializacaoF(f) || cheiaF(f)) return false;
    f->dados[f->fim] = valor;  // Coloca o valor na posição fim
    f->fim = (f->fim + 1) % f->tam;  // Avança fim circularmente
    f->total++;  // Aumenta contador de elementos
    return true;
}

// Remove (desenfileira) o valor da frente da fila
// Retorna o valor removido (0 se vazia)
int desenfileiraF(Fila* f) {
    int valor = 0;
    if (vaziaF(f)) return valor;
    valor = f->dados[f->inicio];  // Pega o valor da frente
    f->inicio = (f->inicio + 1) % f->tam;  // Avança início circularmente
    f->total--;  // Diminui contador
    return valor;
}

// Mostra todos os elementos da fila da frente ao trás
void mostraF(Fila* f) {
    if (vaziaF(f)) {
        std::cout << "Fila vazia!" << std::endl;
        return;
    }
    int idx = f->inicio;
    for (int i = 0; i < f->total; i++) {
        std::cout << f->dados[idx];
        if (i < f->total - 1) std::cout << " -> ";
        idx = (idx + 1) % f->tam;
    }
    std::cout << std::endl;
}

// Busca SIMPLES (sem auxiliar): procura valor da frente ao trás
// Retorna true se encontrou, false se não
bool buscaSimplesF(Fila* f, int valor) {
    if (vaziaF(f)) return false;
    int idx = f->inicio;
    for (int i = 0; i < f->total; i++) {
        if (f->dados[idx] == valor) return true;
        idx = (idx + 1) % f->tam;
    }
    return false;
}

// Busca COM FILA AUXILIAR: move elementos para aux até encontrar ou fim
// Restaura fila original após busca (requer segunda fila aux)
bool buscaAuxF(Fila* f_orig, Fila* f_aux, int valor) {
    if (vaziaF(f_orig)) return false;
    
    // Inicializa aux se preciso
    if (!verificaInicializacaoF(f_aux)) {
        inicializaF(f_aux, f_orig->tam);
    }
    
    bool encontrado = false;
    while (!vaziaF(f_orig)) {
        int val = desenfileiraF(f_orig);
        if (val == valor) encontrado = true;
        enfileiraF(f_aux, val);  // Move para aux
    }
    
    // Restaura original de aux
    while (!vaziaF(f_aux)) {
        enfileiraF(f_orig, desenfileiraF(f_aux));
    }
    return encontrado;
}

#endif
