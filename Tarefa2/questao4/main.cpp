#include <iostream>
#include <time.h>
#include <stdlib.h>

//Enontrar o numero escolhido

using namespace std;

int main()
{
    int base=0, teto=100, tent=1, sort;
    char x;

    srand(time(NULL));

    sort=rand()%101;

    for(;;){
        cout<<endl<<"O numero que voce escolheu é, "<<sort<<"?"<<endl;
        cin>>x;

        if(x=='s'){
            cout<<endl<<"O numero de tentativas necessarias foi => "<<tent<<endl;
            break;
        }else
            tent++;

        cout<<endl<<"O numero é maior que "<<sort<<"?"<<endl;
        cin>>x;

        if(x=='s'){
            sort++;
            base=sort;
        }else{
            sort--;
            teto=sort;
        }

        sort=(base+teto)/2;
    }

    return 0;
}