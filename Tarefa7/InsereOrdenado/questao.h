#ifndef PROG_QUESTAO_H
#define PROG_QUESTAO_H

#include <string>
#include <list>

using namespace std;

template <typename T> void insere_ordenado(list<T> & l, const T & algo)
{
    auto it = l.begin();
    bool x = false;

    while(it != l.end()){
        if(algo < *it){
            x = true;
        }

        if(x){
            l.insert(it,algo);
            break;
        }
        it++;
    }

    if(it == l.end()){
        l.push_back(algo);
    }
}

#endif //PROG_QUESTAO_H