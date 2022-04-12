#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

bool compara(const pair<string,int> & par1, const pair<string,int> par2)
{
    if(par1.second == par2.second){
        return par1.first < par2.first;
    } else
        return par1.second > par2.second;
}

int main(int argc, char *argv[])
{
    fstream arq(argv[1]);
    unordered_map<string,int> tab;

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    string palavra;
    while(arq >> palavra){
        if(tab.count(palavra)){
            tab[palavra]++;
        } else
            tab.emplace(palavra,1);
    }

    list<pair<string,int>> lista;
    for(auto & it: tab){
        lista.push_back(it);
    }

    lista.sort(compara);

    for(auto & it: lista){
        cout << it.first << " " << it.second << endl;
    }
}