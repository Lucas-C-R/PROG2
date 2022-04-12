#include <list>
#include <string>
#include <iostream>

using namespace std;

list<string> separa(const string & texto, const string & sep)
{
    string alfa = texto;
    list<string> lista;

    if(texto != "") {
        while (! alfa.empty()) {
            int j = alfa.find(sep);

            if (j == string::npos) {
                j = alfa.size();
            }

            lista.push_back(alfa.substr(0, j));
            alfa.erase(0, j + sep.size());
        }
    }
    return lista;
}

int main()
{
    string alfa = "vz:,/ekw:,/lyqip:,/finytgah:,/amehv:,/wrqrqk";

    string beta = ":,/";

    list<string> listinha;

    listinha = separa(alfa,beta);

    while(! listinha.empty()){
        if(listinha.size() > 1) {
            cout << listinha.front() << ", ";
        } else {
            cout << listinha.front() << endl;
        }

        listinha.pop_front();
    }

}