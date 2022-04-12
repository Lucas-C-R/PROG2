
// Verifica se uma lista esta ordenada

#include "verifica.h"

bool ordenada(const list<int> & umaLista)
{
    list<int> lista = umaLista;

    lista.sort();

    return (lista == umaLista);
}
