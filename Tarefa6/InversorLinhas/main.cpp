#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
    stack<string> pilha;

    ifstream arq(argv[1]);

    if(! arq.is_open()){
        cout << "arquivo invalido";
        return 0;
    }

    string linha;

    // Ler linhas e colocar na pilha
    while(getline(arq, linha)){
        pilha.push(linha);
    }

    // Printar a pilha
    while(! pilha.empty()){
        cout << pilha.top() << endl;
        pilha.pop();
    }

    return 0;
}