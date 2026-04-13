#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Struct Documento definida no header, aqui só usamos

#include \"filacircular.hpp\"  // Nossa fila circular comentada e adaptada para Documento

int main() {
    // Programa principal para gerenciar filas de impressão P (Prioritária) e N (Normal)
    // Lê comandos de entrada.txt e executa operações conforme lista6
    
    Fila filaP, filaN;  // Duas filas: P prioritária, N normal
    
    ifstream arq(\"entrada.txt\");  // Abre arquivo com comandos linha por linha
    if (!arq) {
        cout << \"ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO\" << endl;
        return 1;
    }
    
    string linha;  // Cada linha do arquivo
    while (getline(arq, linha)) {  // Lê linha por linha até fim
        stringstream ss(linha);  // Parser para separar palavras da linha
        string cmd;  // Comando atual (INICIALIZAR, MOSTRAR, etc.)
        ss >> cmd;
        
        // Comando INICIALIZAR: limpa antigas e cria novas filas com tamanho dado
        if (cmd == \"INICIALIZAR\") {
            int tam;  // Tamanho novo das filas
            ss >> tam;
            destroiF(&amp;filaP);  // Libera memória antiga P
            destroiF(&amp;filaN);  // Libera memória antiga N
            inicializaF(&amp;filaP, tam);  // Cria nova P
            inicializaF(&amp;filaN, tam);  // Cria nova N
            cout << \"A fila P e N foram inicializadas com o tamanho \" << tam << endl;
            
        // Se filas não inicializadas, erro para todos outros comandos
        } else if (!verificaInicializacaoF(&amp;filaP) || !verificaInicializacaoF(&amp;filaN)) {
            cout << \"ERRO: inicializar filas P e N\" << endl;
            continue;
            
        // MOSTRAR F: mostra fila P ou N
        } else if (cmd == \"MOSTRAR\") {
            string f;  // 'P' ou 'N'
            ss >> f;
            Fila* fila = (f == \"P\") ? &amp;filaP : &amp;filaN;
            if (!verificaInicializacaoF(fila)) {
                cout << \"ERRO: inicializar fila \" << f << endl;
            } else {
                mostraF(fila);  // Usa função da fila circular
            }
            
        // ENFILEIRARDOC nome pag F: adiciona doc em P ou N
        } else if (cmd == \"ENFILEIRARDOC\") {
            string nome;  // Nome do PDF
            int pag;      // Páginas
            string f;     // 'P' ou 'N'
            ss >> nome >> pag >> f;
            Fila* fila = (f == \"P\") ? &amp;filaP : &amp;filaN;
            if (!verificaInicializacaoF(fila)) {
                cout << \"ERRO: inicializar fila \" << f << endl;
            } else if (cheiaF(fila)) {  // cheiaF da fila circular
                cout << \"FILA CHEIA\" << endl;
            } else {
                Documento doc = {nome, pag};  // Cria doc
                if (enfileiraF(fila, doc)) {  // Adiciona no final (círculo)
                    cout << \"O documento \" << nome << \" (\" << pag << \" pag) foi adicionado na fila \" << f << endl;
                }
            }
            
        // IMPRIMIRDOC: imprime de P se não vazia, senão de N
        } else if (cmd == \"IMPRIMIRDOC\") {
            if (vaziaF(&amp;filaP)) {  // Prioridade P
                if (vaziaF(&amp;filaN)) {
                    cout << \"NÃO há documentos para imprimir\" << endl;
                } else {
                    Documento doc = desenfileiraF(&amp;filaN);  // Remove início N
                    cout << \"O documento \" << doc.nome << \" foi impresso.\" << endl;
                }
            } else {
                Documento doc = desenfileiraF(&amp;filaP);  // Remove início P
                cout << \"O documento \" << doc.nome << \" foi impresso.\" << endl;
            }
            
        // TOTALPAG: soma páginas de P + N
        } else if (cmd == \"TOTALPAG\") {
            cout << somaF(&amp;filaP) + somaF(&amp;filaN) << \" página(s)\" << endl;
            
        // CONSULTAR nome F: verifica se nome está em P ou N
        } else if (cmd == \"CONSULTAR\") {
            string nome;
            string f;
            ss >> nome >> f;
            Fila* fila = (f == \"P\") ? &amp;filaP : &amp;filaN;
            if (!verificaInicializacaoF(fila)) {
                cout << \"ERRO: inicializar fila \" << f << endl;
            } else if (vaziaF(fila)) {
                cout << \"Fila vazia\" << endl;  // Consistente com mostraF
            } else if (buscaF(fila, nome)) {
                cout << \"O documento \" << nome << \" encontra-se na fila \" << f << endl;
            } else {
                cout << \"O documento \" << nome << \" não está na fila \" << f << endl;
            }
        }
    }
    
    // Ao final, limpa memória das filas
    destroiF(&amp;filaP);
    destroiF(&amp;filaN);
    return 0;
}
