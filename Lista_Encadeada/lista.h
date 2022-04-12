#ifndef CLIONPROJECTSLISTA_20211_LISTA_H
#define CLIONPROJECTSLISTA_20211_LISTA_H

#include <string>

using std::string;

// um nodo (a caixinha)
struct Nodo {
    // um dado armazenado
    string dado;

    // isto indica qual o próximo nodo da sequência
    // e tb seu antecessor
    Nodo * proximo, * anterior;
};

struct Lista {
    // o primeiro nodo da lista
    Nodo guarda;

    // o comprimento da lista (quantos nodos existem)
    int comprimento;
};

// operações da lista: cada operação é uma função

// cria uma lista inicialmente vazia
Lista cria_lista();

// acrescenta um dado ao final da lista
void anexa(Lista & l, const string & dado);

// insere um dado no início da lista
void insere(Lista & l, const string & dado);

// insere um dado em uma posição qualquer
void insere(Lista & l, int posicao, const string & dado);

// acessa um dado no início da lista
string & acessa_inicio(Lista & l);

// acessa um dado no final da lista
string & acessa_final(Lista & l);

// acessa um dado em posição qualquer da lista
string & acessa(Lista & l, int posicao);

// remove o dado do início da lista
void remove_inicio(Lista & l);

// remove o dado do final da lista
void remove_final(Lista & l);

// remove o dado de uma posição qualquer
void remove(Lista & l, int pos);

#endif //CLIONPROJECTSLISTA_20211_LISTA_H