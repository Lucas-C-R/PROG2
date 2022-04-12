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

string roda(const string & cmd) {
    Terminal term(cmd);

    auto res = term.lePalavra();
    return res;
}

void verifica(const string & w1, const string & res) {
    string prog = PROG;
    prog += " "+w1;

    auto v = roda(prog);

    if (v != res) {
        FAIL() << "Palavra: " << w1
               << ", esperado: " << res
               << ", obtido: " << v;
    }

}

TEST(TermTest, Palindromos) {
    verifica("mamam", "VERDADEIRO");
    verifica("arara", "VERDADEIRO");
    verifica("aibofobia", "VERDADEIRO");
    verifica("omississimo", "VERDADEIRO");
    verifica("sopapos", "VERDADEIRO");
}

TEST(TermTest, Comuns) {
    verifica("matame", "FALSO");
    verifica("coisarada", "FALSO");
    verifica("reviveres", "FALSO");
    verifica("saiam", "FALSO");
    verifica("loreta", "FALSO");
}
