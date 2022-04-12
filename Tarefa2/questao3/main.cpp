#include <iostream>

//Verificador de numero primo

using namespace std;

int main()
{
    int x, i, n=0;

    cout<<endl<<"Digite o numero"<<endl;
    cin>>x;

    if(x>1){
        for(i=2;i<x;i++){
            if(x%i==0){
                cout<<endl<<"O numero "<<x<<" nao é primo"<<endl;
                n++;
                break;
            }
        }

        if(n==0){
            cout<<endl<<"O numero "<<x<<" é primo"<<endl;
        }

    }else
        cout<<endl<<"O numero "<<x<<" nao é primo"<<endl;

    return 0;
}