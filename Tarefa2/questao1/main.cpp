#include <iostream>

//Calculo da area de um triangulo

using namespace std;

int main()
{
    float b, h;

    for(;;){
        cout<<endl<<"Informe a base e a altura do triangulo"<<endl;
        cin>>b>>h;

        if(b<0 || h<0){
            cout<<endl<<"Os valores precisam ser positivos!"<<endl;
        }else
            break;
    }

    cout<<endl<<"A area do trinangulo é: "<<b*h/2<<" u.m"<<endl;

    return 0;
}
