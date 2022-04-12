#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

int main() {
    ifstream arq("../cliente.txt");

    if(!arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    unordered_map<string, float> tab;
    string dados;

    while(getline(arq,dados)){
       int aux = dados.find(' ');
       int aux2 = dados.find(' ', aux + 1);

       string cliente, mes;
       float valor;

       cliente = dados.substr(aux2 + 1);
       valor = stof(dados.substr(aux,aux2 - aux));
       mes = dados.substr(0, aux);

       aux = mes.find('/') + 1;
       aux2 = mes.find('/', aux);

       mes = mes.substr(aux, aux2 - aux);

       cliente += ' ' + mes;

       if(tab.count(cliente)){
           tab[cliente] += valor;
       } else
           tab[cliente] = valor;
    }

    string escolha;
    getline(cin, escolha);

    if(tab.count(escolha)){
        cout << endl << "Total: " << tab[escolha] << endl;
    } else
        cout << endl << "mes invalido" << endl;

    return 0;
}