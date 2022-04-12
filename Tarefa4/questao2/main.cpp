//Procurar Palavra

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream arq("teste.txt");

    if(not arq.is_open()){
        perror("Problemas ao abrir o arquivo");
        return errno;
    }

    string linha;
    while(getline(arq, linha)){
        if(linha.find('a') != string::npos){
            cout << endl << linha << endl;
        }
    }

    return 0;
}
