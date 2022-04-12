#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

struct par{
    int aces, temp;
};

bool compara(const pair<string,par> & x1, const pair<string,par> & x2)
{
    if(x1.second.aces == x2.second.aces){
        return x1.first < x2.first;
    }
    return x1.second.aces > x2.second.aces;
}

int main()
{
    ifstream arq("../usuarios.txt");

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    unordered_map<string,par> tab;
    string escolha, usuario, hora;
    int tempo;

    getline(cin,escolha);

    while(arq >> usuario >> hora >> tempo){
        if(tab.count(usuario)){
            par & user = tab[usuario];
            user.aces++;
            user.temp += tempo;
        } else{
           par user;
           user.aces = 1;
           user.temp = tempo;
           tab[usuario] = user;
        }
    }

    if(escolha == ""){
        list<pair<string,par>> lista;

        for(auto & k: tab){
            lista.push_back(k);
        }

        lista.sort(compara);

        for(auto & it: lista){
            par & user = tab[it.first];
            cout << it.first << ' ' << user.aces << ' ' << user.temp << endl;
        }
    } else{
        auto it = tab.find(escolha);

        if(it != tab.end()){
            cout << endl << it->first << ' ';
            cout << it->second.aces << ' ' << it->second.temp << endl;
        } else{
            cout << endl << "usuario invalido" << endl;
        }
    }

    return 0;
}