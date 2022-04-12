#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
    stack<char> letras;
    string palavra = argv[1];

    // Passar as letras da palavra para a pilha
    for(int i = 0; i < palavra.size(); i++){
        letras.push(palavra[i]);
    }

    string inverso;

    // Copiar as letras da pilha para uma string
    while(! letras.empty()){
        inverso += letras.top();
        letras.pop();
    }

    // Verificar se e um palindromo
    if(palavra == inverso){
        cout << endl << "VERDADEIRO" << endl;
    }else
        cout << endl << "FALSO" << endl;

    return 0;
}
