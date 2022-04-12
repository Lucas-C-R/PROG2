#ifndef PRG2_TREES_SISTEMA_H
#define PRG2_TREES_SISTEMA_H

#include <string>
#include <queue>
#include <prglib.h>
#include <unordered_map>
#include <fstream>
#include <list>

using namespace std;
using prglib::arvore;

// Cria uma struct que contem a posicao da linha no arquivo e o valor/conteudo da respeciva linha e coluna
struct dados{
    string inf;
    list<int> posicao;

    bool operator == (const dados & x2){
        return (inf == x2.inf);
    }

    bool operator < (const dados & x2){
        return (inf < x2.inf);
    }
};

void separa(const string & linha, const char & delim, queue<string> & palavras);

void conta_colunas(const string & linha,const list<string> & nome_colunas, list<int> & conta_virg);

void cria_arvores(ifstream & arq, unordered_map<string, arvore<dados>> & tab, list<string> & nome_das_colunas);

void procura_na_arvore(ifstream & arq, queue<string> & coluna, queue<string> & valor, unordered_map<string, arvore<dados>> & tab, list<string> & lista_linhas);

bool verifica_se_colunas_existem(ifstream & arq, queue<string> colunas);

#endif //PRG2_TREES_SISTEMA_H