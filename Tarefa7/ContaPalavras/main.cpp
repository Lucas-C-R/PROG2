#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;


int main(int argc,char *argv[])
{
    ifstream arq(argv[1]);

    string alfa;

    list<string> palavras;

    while(arq >> alfa){
        palavras.push_back(alfa);
    }

    if(palavras.empty()){
        return 0;
    }

    palavras.sort();

    auto it1 = palavras.begin();
    auto it2 = it1;
    it2++;

    int i = 1;

    while(it2 != palavras.end()){
        if(*it1 == *it2){
            i++;
        } else{
            cout << *it1 << ' ' << i << endl;
            i = 1;
        }
        it1++;
        it2++;
    }

    cout << *it1 << ' ' << i << endl;
}