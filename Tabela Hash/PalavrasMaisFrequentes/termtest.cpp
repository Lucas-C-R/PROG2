//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <fstream>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./Prog"

vector<string> roda(const string & cmd) {
    Terminal term(cmd);
    vector<string> res;

    auto v = term.leLinhas();
    for (auto & s: v) strip(s);
    return v;
}

vector<string> conta(const string & name, int n) {
    ifstream arq(name);
    string w;
    unordered_map<string,int> tab;

    while (arq >> w) {
        if (tab.count(w)) tab[w]++;
        else tab[w]=1;
    }

    // cria lista com pares da tabela
    list<pair<string,int>> l(tab.begin(), tab.end());
    // ordena pela frequencia (campo second)
    l.sort([](auto & p1, auto & p2) {if (p1.second == p2.second) return p1.first < p2.first; else return p1.second > p2.second;});
    // remove os pares da posição n em diante
    vector<string> v;
    for (auto & par: l) {
        if (! n--) break;
        v.push_back(par.first+' '+to_string(par.second));
    }

    return v;
}

void verifica(int num_arq, int Nfreq) {
    string arq = "../data/arquivo"+to_string(num_arq)+".txt";
    string arqres = PROG;
    arqres += ' ' + arq+' '+to_string(Nfreq);

    auto v = roda(arqres);
    auto res = conta(arq, Nfreq);

    if (v != res) {
        FAIL() << "Esperado: " << v2str(res)
               << ", obtido: " << v2str(v);
    }

}

TEST(TermTest, TopMais) {
    verifica(1,1);
    verifica(5,1);
}

TEST(TermTest, DuasMais) {
    verifica(1,2);
    verifica(5,2);
}

TEST(TermTest, TresMais) {
    verifica(1,3);
    verifica(5,3);
}

TEST(TermTest, QuatroMais) {
    verifica(1,4);
    verifica(5,4);
}

TEST(TermTest, DezMais) {
    verifica(1,10);
    verifica(5,10);
}

TEST(TermTest, MenosQueExiste) {
    verifica(3,3);
}

