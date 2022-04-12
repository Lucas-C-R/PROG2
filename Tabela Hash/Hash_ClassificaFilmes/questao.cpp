#include "questao.h"

void sumariza(const unordered_map<string,Categoria> & filmes, unordered_map<Categoria,int> & sumario)
{
    if(filmes.empty()){
        sumario[EXCELENTE];
        sumario[BOM];
        sumario[REGULAR];
        sumario[RUIM];
    } else
        for(auto & k: filmes){
           if(sumario.count(k.second)){
               sumario[k.second]++;
           } else
               sumario[k.second] = 1;
        }
}