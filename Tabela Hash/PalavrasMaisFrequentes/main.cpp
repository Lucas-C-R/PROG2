#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

// Indico iteradores como parametro
bool compara(const pair<string,int> & x1, const pair<string,int> & x2)
{
    // Se a quantidade de vezes que as palavras aparecem forem iguais,
    // ordeno por ordem alfabetica
    if(x1.second == x2.second){
        return x1.first < x2.first;
    }
    return x1.second > x2.second; // Retorna em ordem decrescente, o maior valor
}

int main(int argc, char *argv[])
{
    ifstream arq(argv[1]);

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    string palavras;
    unordered_map<string,int> tab;

    // Lista que armazena um 'iterador (auto pode ser escrito
    // como pair<variavel,variavel>)'
    list<pair<string,int>> lista;
    int x = 0;

    while(arq >> palavras){
        if(tab.count(palavras)){
            tab[palavras]++;
        } else
            tab[palavras] = 1;
    }

    // Adiciono o iterador da tabela 'tab' a lista
    for(auto & k: tab){
        lista.push_back(k);
    }

    lista.sort(compara);

    for(auto & it: lista){
        if(x < stoi(argv[2])){
            // A lista contem um iterador de tabela, por isso, .first e .second
            cout << it.first << ' ' <<  it.second << endl;
        }
        x++;
    }
}