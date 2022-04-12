#include <iostream>
#include <fstream>
#include <string>
#include <prglib.h>

using namespace std;
using prglib::arvore;

int main()
{
    ifstream arq("../portugues.txt");

    if(!arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    arvore<string> arv(arq);

    cout << "Tamanho da arvore: " << arv.tamanho() << endl;
    cout << "Altura: " << arv.altura() << endl;
    cout << "Fator de Balanceamento: " << arv.fatorB() << endl << endl;

    arv.balanceia(true);

    cout << "Tamanho da arvore: " << arv.tamanho() << endl;
    cout << "Altura: " << arv.altura() << endl;
    cout << "Fator de Balanceamento: " << arv.fatorB() << endl;

    return 0;
}