// Copiar colunas de uma tabela

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    int i, j, k, h, colunas;

    ifstream arq(argv[1]);

    if(! arq.is_open()){
        perror("Problemas ao abrir o arquivo!");
        return errno;
    }

    string linha;
    while(getline(arq, linha)){
        for(h=2; h<argc; h++) {
            colunas = stoi(argv[h]);

            for (k = 0, i = 0; k < colunas; k++) {
                i = linha.find(',', i + 1) + 1;
            }

            for (k = 0, j = 0; k <= colunas; k++) {
                j = linha.find(',', j + 1);

                if(j == string::npos){
                    j = linha.size();
                }
            }

            if (h == argc - 1) {
                cout << linha.substr(i, j - i) << endl;
            } else
                cout << linha.substr(i, j - i) << ',';
        }
    }

    return 0;
}
