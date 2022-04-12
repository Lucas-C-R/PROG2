// implemente aqui seu programa ...
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    queue<string> clientes;
    string dado;

    while(dado != "sair"){
        cout << ">";
        getline(cin, dado);

        if(dado == "?"){
            if(! clientes.empty()) {
                cout << clientes.front() << endl;
                clientes.pop();
            }
        } else if(dado == "sair"){
                break;
            } else{
                clientes.push(dado);
                cout << clientes.size() - 1 << endl;
            }
    }

    return 0;
}