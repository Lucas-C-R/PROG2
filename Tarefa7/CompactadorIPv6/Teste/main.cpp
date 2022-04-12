#include <iostream>
#include <list>
#include <string>

using namespace std;

string compacta_ipv6(const string & ip6)
{
    list<string> bin;
    string compac;
    int inic = 0, fim = 0, x = 0, taman = 0;

    while(fim != ip6.size()){
        fim = ip6.find(':', inic + 1);

        if(fim == string::npos){
            fim = ip6.size();
        }

        bin.push_back(ip6.substr(inic, fim - inic));

        inic = fim;
        inic++;
    }

    while(! bin.empty()){
        auto it = bin.begin();
        int zero;

        zero = it->find("0");

        while(zero != string::npos){
            taman++;
            if(taman == it->size() || it->size() == 1){
                it->erase();
            }

            zero = it->find("0", zero + 1);
        }
        taman = 0;

        if(it != --bin.end()){
            if(*it == ""){
                x++;
                if(x == 1){
                    compac += ':';
                }
            } else{
                compac += *it + ':';
                x = 0;
            }
        } else
            compac += *it;

        bin.pop_front();
    }

    if(compac == ":" || compac[0] == ':'){
        compac = ':' + compac;
    }

    return compac;
}

int main() {
    string aux, a = "07:d21:e08:0:0:0:0:a6";
    aux = compacta_ipv6(a);

    cout << endl << aux << endl;
    return 0;
}
