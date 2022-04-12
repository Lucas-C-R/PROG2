#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <list>

using namespace std;

struct carro{
    string veic;
    int km;
};

void separa(const string & linha, const string & delim, list<string> & lista)
{
    int inic = 0, fim = 0;

    while(fim != linha.size()){
        fim = linha.find(delim, inic+1);

        if(fim == string::npos){
            fim = linha.size();
        }

        lista.push_back(linha.substr(inic, fim - inic));
        inic = fim + 1;
    }
}

bool compara(const carro & x1, const carro & x2){
    // Compara os veiculos, por ordem alfabetica
    return x1.veic < x2.veic;
}

int main(int argc, char *argv[])
{
    ifstream arq(argv[1]);

    if(! arq.is_open()){
        cout << endl << "arquivo invalido" << endl;
        return 0;
    }

    unordered_map<string,list<carro>> tab;
    string dados;

    while(getline(arq,dados)){
        list<string> lista;
        carro usuar;

        separa(dados,",",lista);

        usuar.veic = lista.front();
        usuar.km = stoi(lista.back());

        // Obter o dado do meio da lista de strings
        auto it = lista.begin();
        it++;

        // Descobrir se ja existe a chave
        if(tab.count(*it)){
            bool existe = false;

            // Verifica se o veiculo ja esta na lista inclusa na tabela hash
            for(auto & itera: tab[*it]){
                if(itera.veic == usuar.veic){
                    itera.km += usuar.km;
                    existe = true;
                }
            }

            if(existe == false){
                tab[*it].push_back(usuar);
            }

            // Compara as structs
            tab[*it].sort(compara);
        } else
            tab[*it].push_back(usuar);
    }

    list<string> aux;

    // Pega a chave da tabela hash e passa para uma lista, para poder ser ordenado
    for(auto & k: tab){
        aux.push_back(k.first);
    }

    aux.sort();

    for(auto & it: aux){
        cout << it << ':' << endl;

        for(auto & par: tab[it]){
            cout << "--" << par.veic << ": " << par.km << endl;
        }
    }

    return 0;
}