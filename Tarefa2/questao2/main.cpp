#include <iostream>
#include <string>

//Inversor de string

using namespace std;

int main()
{
    string alfa;
    char x;
    int i, j;

    cout<<endl<<"Informe a frase:"<<endl;
    getline(cin,alfa);

    for(i=alfa.size()-1,j=0; j<i; i--,j++){
        x=alfa[i];
        alfa[i]=alfa[j];
        alfa[j]=x;
    }

    i=alfa.size();
    alfa[i]=0;

    cout<<endl<<alfa<<endl;

    return 0;
}
