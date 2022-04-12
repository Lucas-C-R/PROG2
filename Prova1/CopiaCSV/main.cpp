#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    int i, j, h, k, colunas;

    ifstream arq(argv[1]);

    if (not arq.is_open()) {
        perror("Erro o abrir o arquivo.");
        return errno;
    }

    string linha;
    while(getline(arq, linha)){
        for(h = 2; h < argc; h++) {
            colunas = stoi(argv[h]);

            // Comeco da coluna
            for (k = 0, i = 0; k < colunas; k++) {
                i = linha.find(',', i + 1) + 1;
            }

            // Final da coluna
            for (k = 0, j = 0; k <= colunas; k++) {
                j = linha.find(',', j + 1);
                if(j == string::npos){
                    j = linha.size();
                }
            }

            // Caso nao tenha acabado o numero de colunas, adiciona uma virgula, se nao, termina a linha
            if (h == argc - 1) {
                cout << linha.substr(i, j - i) << endl;
            } else
                cout << linha.substr(i, j - i) << ',';
        }
    }

    return 0;
}