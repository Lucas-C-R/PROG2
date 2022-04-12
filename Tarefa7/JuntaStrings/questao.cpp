#include "questao.h"

string junta(list<string> & l, const string & delim)
{
    string alfa;

    auto it = l.begin();
    while(it != l.end()){
        if(it != --l.end()){
            alfa += *it + delim;
        } else
            alfa += *it;

        it++;
    }

    return alfa;
}