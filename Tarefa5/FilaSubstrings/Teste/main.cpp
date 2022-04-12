#include <string>
#include <queue>

using namespace std;

void separa(const string & algo, char sep, queue<string> & q)
{
    if(algo != "") {
        int i, j;
        string alfa = algo;

        for(i = 0; i < alfa.size(); i++){
            j = alfa.find(sep);
            if(j == string::npos){
                j = alfa.size();
            }
            q.push(alfa.substr(0, j));
            alfa.erase(0, j + 1);
        }
    }
}

int main()
{
    string alfa = "Ola mundo, loucura demais, isso";
    queue<string> fila;

    separa(alfa,',', fila);
}