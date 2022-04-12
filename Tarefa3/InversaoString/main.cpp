#include <iostream>
#include <string>

using namespace std;

int main()
{
    string alfa;
    char c;
    int i,j;

    getline(cin,alfa);

    for(i=0, j=alfa.size()-1;i<j;i++, j--){
        c=alfa[j];
        alfa[j]=alfa[i];
        alfa[i]=c;
    }

    j=alfa.size();
    alfa[j]=0;

    cout<<alfa;

    return 0;
}