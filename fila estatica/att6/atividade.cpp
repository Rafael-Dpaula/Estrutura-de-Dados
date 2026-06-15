#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "filacircular.hpp"  // Fila circular comentada com todos métodos

int main() {
    // Programa principal para exercício att6.1 - lista6
    // Gerencia duas filas de impressão: P (prioridade) e N (normal)
    // Lê comandos de entrada.txt linha por linha
    // Segue política: sempre imprime P se tem, senão N
    
    Fila filaP, filaN;  // Declara as duas filas
    
    ifstream arq("entrada.txt");  // Abre arquivo de entrada
    if (!arq) {
        cout << "ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO" << endl;
        return 1;
    }
    
    string linha;
    while (getline(arq, linha)) {  // Processa cada linha/comando
        stringstream ss(linha);
        string cmd;
        ss >> cmd;
        
        if (cmd == "INICIALIZAR") {
            // Inicializa ou reinicializa as filas com novo tamanho
            int tam;
            ss >> tam;
            destroiF(&filaP);  // Limpa P antiga
            destroiF(&filaN);  // Limpa N antiga
            inicializaF(&filaP, tam);  // Nova P
            inicializaF(&filaN, tam);  // Nova N
            cout << "A fila P e N foram inicializadas com o tamanho " << tam << endl;
        } else if (!verificaInicializacaoF(&filaP) || !verificaInicializacaoF(&filaN)) {
            // Erro se não inicializadas
            cout << "ERRO: inicializar filas P e N" << endl;
            continue;
        } else if (cmd == "MOSTRAR") {
            string f;
            ss >> f;
            Fila* fila = (f == "P") ? &filaP : &filaN;
            if (!verificaInicializacaoF(fila)) {
                cout << "ERRO: inicializar fila " << f << endl;
            } else {
                mostraF(fila);  // Mostra usando função circular
            }
        } else if (cmd == "ENFILEIRARDOC") {
            string nome;
            int pag;
            string f;
            ss >> nome >> pag >> f;
            Fila* fila = (f == "P") ? &filaP : &filaN;
            if (!verificaInicializacaoF(fila)) {
                cout << "ERRO: inicializar fila " << f << endl;
            } else if (cheiaF(fila)) {
                cout << "FILA CHEIA" << endl;
            } else {
                Documento doc = {nome, pag};
                if (enfileiraF(fila, doc)) {
                    cout << "O documento " << nome << " (" << pag << " pag) foi adicionado na fila " << f << endl;
                }
            }
        } else if (cmd == "IMPRIMIRDOC") {
            // Política de prioridade: P primeiro
            if (vaziaF(&filaP)) {
                if (vaziaF(&filaN)) {
                    cout << "NÃO há documentos para imprimir" << endl;
                } else {
                    Documento doc = desenfileiraF(&filaN);
                    cout << "O documento " << doc.nome << " foi impresso." << endl;
                }
            } else {
                Documento doc = desenfileiraF(&filaP);
                cout << "O documento " << doc.nome << " foi impresso." << endl;
            }
        } else if (cmd == "TOTALPAG") {
            cout << somaF(&filaP) + somaF(&filaN) << " página(s)" << endl;
        } else if (cmd == "CONSULTAR") {
            string nome;
            string f;
            ss >> nome >> f;
            Fila* fila = (f == "P") ? &filaP : &filaN;
            if (!verificaInicializacaoF(fila)) {
                cout << "ERRO: inicializar fila " << f << endl;
            } else if (vaziaF(fila)) {
                cout << "Fila vazia" << endl;  // Match com mostraF
            } else if (buscaF(fila, nome)) {
                cout << "O documento " << nome << " encontra-se na fila " << f << endl;
            } else {
                cout << "O documento " << nome << " não está na fila " << f << endl;
            }
        }
    }
    
    destroiF(&filaP);  // Limpeza final de memória
    destroiF(&filaN);
    return 0;
}
