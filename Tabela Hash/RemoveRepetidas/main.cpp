#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream arq(argv[1]);

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    unordered_set<string> conjunto;
    string matricula;
    list<string> lista;

    while(arq >> matricula){
       conjunto.insert(matricula);
    }

    for(auto & it: conjunto){
        lista.push_back(it);
    }

    lista.sort();

    for(auto & it: lista){
        cout << it << endl;
    }
}