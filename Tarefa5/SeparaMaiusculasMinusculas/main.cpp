// Separa maiúsculas e minúsculas

#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream arq(argv[1]);

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo!");
        return errno;
    }

    queue<string> mai, min;

    cout << endl;

    string linha;
    while(arq >> linha){
        if(isupper(linha[0])){
            mai.push(linha);
        } else
            min.push(linha);
    }

    while(! mai.empty()){
        cout << mai.front() << " ";
        mai.pop();
    }

    cout << endl;

    while(! min.empty()){
        cout << min.front() << " ";
        min.pop();
    }

    return 0;
}