#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
   string alfa = argv[1], beta = argv[2];
   list<char> lista, lista2;

   if(alfa.size() != beta.size()){
       cout << endl << "FALSO" << endl;
       return 0;
   }

   for(int i = 0; i < alfa.size(); i++){
       lista.push_back(alfa[i]);
   }
   lista.sort();

    for(int i = 0; i < beta.size(); i++){
        lista2.push_back(beta[i]);
    }
    lista2.sort();

    if(lista == lista2) {
        cout << endl << "VERDADEIRO" << endl;
    } else{
        cout << endl << "FALSO" << endl;
    }

    return 0;
}