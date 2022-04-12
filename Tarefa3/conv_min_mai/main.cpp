//Conversão para maiúsculas

#include <iostream>

using namespace std;

int main()
{
    string alfa;
    int i;

    getline(cin,alfa);

    for(i=0;i<alfa.size();i++){
        alfa[i]=toupper(alfa[i]);
    }

    cout<<endl<<alfa<<endl;

    return 0;
}
