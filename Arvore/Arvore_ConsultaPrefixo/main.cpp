#include <iostream>
#include <fstream>
#include <prglib.h>
#include <string>

using namespace std;
using prglib::arvore;

int main()
{
    ifstream arq("../dados.txt");

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    string dados;
    arvore<string> arv;

    while(arq >> dados){
        arv.adiciona(dados);
    }

    while(true){
        cout << ">";
        getline(cin,dados);

        if(dados.empty()){
            break;
        }

        string fim = dados;
        fim.back()++;

        list<string> ret;
        arv.obtemIntervalo(ret,dados,fim);
        ret.sort();

        if(ret.back() == fim){
            ret.pop_back();
        }

        for(auto & palavra: ret){
            cout << palavra << endl;
        }
    }
}