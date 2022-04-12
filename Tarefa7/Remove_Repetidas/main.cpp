#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream arq(argv[1]);
    list<string> lista, aux;

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    string alfa;
    while(arq >> alfa){
        auto it = lista.begin();

        if(lista.size() == 0){
            lista.push_back(alfa);
        }else {
            int i = 0;
            while (it != lista.end()) {
                if (alfa == *it) {
                    i = 1;
                    break;
                } else {
                    it++;
                }
            }

            if(i == 0){
                lista.push_back(alfa);
            }
        }
    }

    lista.sort();

    while(! lista.empty()) {
        auto it = lista.begin();
        cout << lista.front() << ' ';
        lista.erase(it);
    }

    return 0;
}
