//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./Prog"

vector<string> roda(const string & cmd) {
    Terminal term(cmd);

    auto res = term.leLinhas();
    return res;
}

void verifica(int n, const string & caso) {
    string arq = "cat ../data/res"+to_string(n)+".txt";
    string arqres = PROG;
    arqres += " ../data/arquivo"+to_string(n)+".txt";

    auto v = roda(arq);
    auto res = roda(arqres);

    if (v != res) {
        FAIL() << "Caso " << caso << ": esperado: " << v2str(v) << endl
               << "Obtido: " << v2str(res);
    }

}

TEST(TermTest, Vazio) {
    verifica(2, "Arquivo vazio");
}

TEST(TermTest, Normal) {
    verifica(1, "Relatório usual");
}
