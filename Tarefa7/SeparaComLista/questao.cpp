#include "questao.h"

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