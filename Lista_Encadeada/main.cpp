#include <iostream>
#include "lista.h"

using namespace std;

int main() {
    Lista l1 = cria_lista();

    cout << "Comprimento: " << l1.comprimento << endl;
    try {
        cout << "dado no início: " << acessa_inicio(l1) << endl;
    } catch (...) {
        cout << "Opa ! Lista vazia !" << endl;
    }

    anexa(l1, "algo");
    cout << "Comprimento: " << l1.comprimento << endl;
    cout << "dado no início: " << acessa_inicio(l1) << endl;
    cout << "dado no final: " << acessa_final(l1) << endl;

    insere(l1, "coisa");
    cout << "Comprimento: " << l1.comprimento << endl;
    cout << "dado no início: " << acessa_inicio(l1) << endl;
    cout << "dado no final: " << acessa_final(l1) << endl;

    insere(l1, 1,"treco");
    cout << "Comprimento: " << l1.comprimento << endl;
    cout << "dado no início: " << acessa_inicio(l1) << endl;
    cout << "dado no final: " << acessa_final(l1) << endl;
    cout << "dado na posição 1: " << acessa(l1, 1) << endl;
    cout << endl;

    string & s = acessa_inicio(l1);
    s = "xyz";

    for (int i=0; i < l1.comprimento; i++) {
        cout << "posição " << i << ": " << acessa(l1, i) << endl;
    }

    remove(l1, 0);
    cout << endl;
    for (int i=0; i < l1.comprimento; i++) {
        cout << "posição " << i << ": " << acessa(l1, i) << endl;
    }


    return 0;
}