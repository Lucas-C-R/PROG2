// Normalizar nome de pessoa

#include <iostream>
#include <string>

using namespace std;

string normaliza(string nome)
{
    string str;
    int i, j;

    i=nome.find(' ');

    if(i!=-1){
        for(i=nome.size()-1; nome[i]!=' '; i--){
            str += nome[i];
        }

        nome.erase(i, nome.size());

        for(i=0, j=str.size()-1;i<j;i++, j--){
            char c = str[j];
            str[j] = str[i];
            str[i] = c;
        }

        str += ", " + nome;
    }else
        return "";

    return str;
}

int main()
{
    string nome_comp="Joaquim José da Silva Xavier";

    nome_comp = normaliza(nome_comp);

    cout << endl << nome_comp << endl;

    return 0;
}
