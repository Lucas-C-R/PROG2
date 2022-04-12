#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <list>

using namespace std;

int main()
{
    string arquivo;
    string numero;
    unordered_map<int, int> tab;

    cin >> arquivo;

    ifstream arq(arquivo);

    if(! arq.is_open()){
        cout << endl << "arquivo inacessivel" << endl;
        return 0;
    }

    while(arq >> numero){
        long int n = 0, x = 1000000, valor;

        try {
            valor = stoi(numero);
        } catch (...) {
            cout << endl << "arquivo corrompido" << endl;
            return 0;
        }

        while(true){
            if(valor >= x*n && valor < x*(n+1)){
                if(tab.count(x*n)){
                    tab[x*n]++;
                    break;
                } else{
                    tab[x*n] = 1;
                    break;
                }
            }
            n++;
        }
    }

    list<int> lista;

    for(auto & k: tab){
        lista.push_back(k.first);
    }

    lista.sort();

    for(auto & it: lista){
        cout << it << ' ' << tab[it] << endl;
    }

    return 0;
}