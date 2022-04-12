#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

list<string> separa(const string & linha, const string & delim)
{
    int inic = 0, fim = 0;
    list<string> lista;

    while(fim != linha.size()){
        fim = linha.find(delim, inic+1);

        if(fim == string::npos){
            fim = linha.size();
        }

        lista.push_back(linha.substr(inic, fim));
        inic = fim + 1;
    }

    return lista;
}

int main(int argc, char *argv[])
{
    ifstream arq(argv[1]);

    if(! arq.is_open()){
        perror("Ero ao abrir o arquivo");
        return errno;
    }

    list<string> lista;
    unordered_map<string,string> tab;

    for(int n = 2; n < argc; n++){
        lista = separa(argv[n],"=");

        tab["$" + lista.front()] = lista.back();
    }

    string linha;
    while(getline(arq, linha)){
        int aux;
        if(! linha.empty()) {
            for(auto & par: tab){
                aux = linha.find(par.first);

                while(aux != string::npos){
                    linha.replace(aux, par.first.size(), par.second);
                    aux = linha.find(par.first);
                }
            }
        }
        cout << linha << endl;
    }

    return 0;
}