#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <errno.h>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream arq(argv[1]);

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    unordered_map<int,list<string>> tab;
    string palavra;
    list<int> lista;

    while(arq >> palavra){
        // Pega a lista que esta dentro da tabela hash e adiciono a palavra
        tab[palavra.size()].push_back(palavra);
    }

    for(auto & par: tab){
        lista.push_back(par.first);
    }

    lista.sort();

    for(auto & it: lista){
        // Acessa diretamente (&) a lista que esta dentro da tabela hash
        list<string> & palavras = tab[it];

        palavras.sort();

        for(auto & it: palavras){
            cout << it << " ";
        }
        cout << endl;
    }
}