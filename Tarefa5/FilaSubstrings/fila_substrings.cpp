// Separando substrings

#include "fila_substrings.h"

void separa(const string & algo, char sep, queue<string> & q)
{
    if(algo != "") {
        int i, j;
        string alfa = algo; // Para poder usar o ".erase()"

        // Encontrar o caractere que ira separar as strings e apagar a string auxiliar
        for(i = 0; i < alfa.size(); i++){
            j = alfa.find(sep);

            // Caso nao tenha mais o caractere separador, na string auxiliar
            if(j == string::npos){
                j = alfa.size();
            }
            q.push(alfa.substr(0, j));

            // Apagar a string da posicao 0 ao caractere separador
            alfa.erase(0, j + 1);
        }
    }
}