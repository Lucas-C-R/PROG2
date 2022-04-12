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

    auto res = term.lePalavras();
    return res;
}

void verifica(int n) {
    string arq = "cat ../data/res"+to_string(n)+".txt";
    string arqres = PROG;
    arqres += " ../data/arquivo"+to_string(n)+".txt";

    auto v = roda(arq);
    auto res = roda(arqres);

    if (v != res) {
        FAIL() << "Esperado: " << v2str(v) << endl
               << ", obtido: " << v2str(res);
    }

}

TEST(TermTest, Arquivo1) {
    verifica(1);
}

TEST(TermTest, Arquivo2) {
    verifica(2);
}

TEST(TermTest, Arquivo3) {
    verifica(3);
}
