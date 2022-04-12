// Contar linhas, palavras e caracteres de um arquivo

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream arq(argv[1]);

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo!");
        return errno;
    }

    string linha;
    int n_linhas=0, palavras=0, caracteres = 0;

    while(getline(arq, linha)){
        n_linhas++;
        bool espaco = true;

        for(int i=0; i<linha.size(); i++){
            if(isspace(linha[i])){
                espaco = true;
            }else
                if(espaco){
                    palavras++;
                    espaco = false;
                }
        }

        caracteres = linha.size() + 1 + caracteres;
    }

    cout << endl << n_linhas << ' ' << palavras << ' ' << caracteres << endl;
}
