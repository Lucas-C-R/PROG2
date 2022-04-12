#include <iostream>
#include <string>

using namespace std;

// ex: imagine que frase seja: " um  teste qualquer"

int main() {
    string str;
    int i, palavras = 0;
    bool espaco=true; // 0: caractere anterior não foi espaço
    // 1: caractere anterior foi espaço

    // para cada caractere da string
    //   se for um espaço então espaco=true
    //   senão
    //     se caractere anterior foi um espaço então
    //       incrementa palavras
    //       espaco=false
    //     fim se
    //   fim se
    // fim para

    getline(cin, str);
    for(i=0;i<str.size();i++){
        if(isspace(str[i])){
            espaco = true;
        } else{
            if (espaco){
                palavras++;
                espaco = false;
            }
        }

    }

    cout << palavras << "  " << str.size() << endl;

    return 0;
}
