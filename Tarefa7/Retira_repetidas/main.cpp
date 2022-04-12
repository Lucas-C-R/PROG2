
// Retira palavars repetidas

#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream arq(argv[1]);
    list<string> lista;

    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo");
        return errno;
    }

    string palavras;
    while(arq >> palavras){
        if(lista.size() == 0){
            lista.push_back(palavras);
        }else{
            int i = 0;
            for(auto & it: lista) {
                if (palavras == it) {
                    i = 1;
                    break;
                }
            }

            if(i == 0){
                lista.push_back(palavras);
            }
        }
    }

    while(! lista.empty()) {
        auto it = lista.begin();
        cout << lista.front() << ' ';
        lista.erase(it);
    }

    return 0;
}
