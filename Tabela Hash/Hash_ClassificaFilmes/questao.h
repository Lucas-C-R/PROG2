#ifndef PROG_QUESTAO_H
#define PROG_QUESTAO_H

#include "categoria.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void sumariza(const unordered_map<string,Categoria> & filmes, unordered_map<Categoria,int> & sumario);

#endif //PROG_QUESTAO_H
