#include <iostream>
#include <prglib.h>
#include <string>
#include <fstream>
#include <stack>

using namespace std;
using prglib::arvore;

int main()
{
    string aux;
    arvore<string> arv;

    cin >> aux;

    ifstream arq(aux);

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    while(arq >> aux){
        arv.adiciona(aux);
    }

    arv.balanceia(true);

    int x = 0;
    stack<string> pilha;

    for(auto it = arv.inorder_rbegin(); it != arv.inorder_rend();it++){
        if(x < 5){
            pilha.push(*it);
        }
        x++;
    }

    while(! pilha.empty()){
        cout << pilha.top() << ' ';
        pilha.pop();
    }

    return 0;
}