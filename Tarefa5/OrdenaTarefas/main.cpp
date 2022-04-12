#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
    string prioridade = "12345";
    int i;

    ifstream arq(argv[1]);

    queue<string> A, B, C, D, E;

    string linha;
    while(getline(arq, linha)){
       i = linha.find_first_of(prioridade);

       // Encontrar as prioridades
       if(linha[i] == '1'){
           A.push(linha);
       } else if(linha[i] == '2'){
           B.push(linha);
       } else if(linha[i] == '3'){
           C.push(linha);
       } else if(linha[i] == '4'){
           D.push(linha);
       } else
           E.push(linha);
    }

    // Comecar o print das prioridades
    while(! A.empty()){
        cout << A.front() << endl;
        A.pop();
    }

    while(! B.empty()){
        cout << B.front() << endl;
        B.pop();
    }

    while(! C.empty()){
        cout << C.front() << endl;
        C.pop();
    }

    while(! D.empty()){
        cout << D.front() << endl;
        D.pop();
    }

    while(! E.empty()){
        cout << E.front() << endl;
        E.pop();
    }

    return 0;
}