//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./Prog"

vector<string> roda(const string & cmd) {
    Terminal term(cmd);

    auto res = term.leLinhas();
    return res;
}

bool confere(vector<string> & v, vector<string> & r) {
    if (v.size() != r.size()) return false;
    unordered_map<string,int> tab;

    for (auto & s: r) tab[s] = 1;
    for (auto & s: v) {
        if (! tab.count(s)) return false;
    }
    return true;
}

void verifica(int n) {
    string arq = "cat ../data/arquivo"+to_string(n)+".txt";
    string arqres = PROG;
    arqres += " ../data/res"+to_string(n)+".txt";

    auto v = roda(arq);
    auto res = roda(arqres);

    if (! confere(v, res)) {
        FAIL() << "Esperado: " << v2str(v)
               << ", obtido: " << v2str(res);
    }

}

TEST(TermTest, OK) {
    verifica(1);
    verifica(4);
}

TEST(TermTest, Vazio) {
    verifica(2);
}

TEST(TermTest, Simples) {
    verifica(3);
}
