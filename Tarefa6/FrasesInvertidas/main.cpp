#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string frase, inverso;
    stack<string> pilha;

    getline(cin,frase);

    if(frase != ""){
        int i = 0, j = 0;

        // Pega palavra por palavra e coloca na pilha
        while(j < frase.size()){
            j = frase.find(' ', j + 1);

            if(j == string::npos){
                j = frase.size();
            }

            pilha.push(frase.substr(i, j - i));
            i = j + 1;
        }
         // Copia o conteudo da pilha, pra string auxiliar
        while(! pilha.empty()){
            if(pilha.size() > 1) {
                inverso += pilha.top() + ' ';
            } else
                inverso += pilha.top();
            pilha.pop();
        }

        if(frase == inverso){
            cout << endl << "VERDADEIRO" << endl;
        }else
            cout << endl << "FALSO" << endl;
    }

    return 0;
}