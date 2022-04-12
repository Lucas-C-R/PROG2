#include "pathname.h"

string reduz_caminho(const string & caminho)
{
    int i = 0, j = 0;
    stack<string> pilha;
    string aux;

    if(caminho != ""){
        while(i < caminho.size()){
            i = caminho.find('/', i + 1);

            if(caminho.substr(j, i - j) == "/.."){
                if(! pilha.empty()){
                    pilha.pop();
                }
            } else
            if(caminho.substr(j, i - j) != "/."){
                pilha.push(caminho.substr(j, i - j));
            }

            j = i;
        }
    } else
        return "";

    if(pilha.empty()){
        pilha.push("/");
    }
    while(! pilha.empty()){
        aux = pilha.top() + aux;
        pilha.pop();
    }

    return aux;
}