//Conferir se string contém uma data

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int dia, mes, ano, i, j;
    string alfa;
    char beta[2], gamma[4];

    alfa=argv[1];

    for(i=0; alfa[i]!='/'; i++){
        dia = stoi(alfa);
    }

    //Ver se o dia e valido
    if(dia>0 && dia<=31){
        for(i=i+1, j=0; alfa[i]!='/'; i++, j++){
            beta[j]=alfa[i];
        }
        mes = stoi(beta);

        //Ver se o mes e valido
        if(mes>0 && mes<=12){
            if(mes==2 && dia>28){ //Mes de fevereiro so tem 28 dias
                cout << endl << "data invalida" << endl;
            }else
                if(dia>30 && mes<=6 && mes%2==0){ //Ate o mes 6, so os pares tem 30 dias
                    cout << endl << "data invalida" << endl;
                }else
                    if(dia>30 && mes>=9 && mes%2!=0){ //Acima do mes nove, so os impares
                        cout << endl << "data invalida" << endl;
                    }else{
                        for(i=i+1, j=0; alfa[i]!='\0'; i++, j++){
                            gamma[j] = alfa[i];
                        }
                        ano = stoi(gamma);

                        //Ver se o ano e valido
                        if(ano>999 && ano<9999){
                            cout << endl << alfa << endl;
                        }else
                            cout << endl << "data invalida" << endl;
                    }
        }else
            cout << endl << "data invalida" << endl;
    }else
        cout << endl << "data invalida" << endl;

    return 0;
}
