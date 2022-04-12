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

void verifica(const string & w1, const string & w2, const string & res) {
    string prog = PROG;
    prog += " "+w1+" "+w2;

    auto v = roda(prog);

    if (v != res) {
        FAIL() << "Palavras: " << w1 << " " << w2
               << ", esperado: " << res
               << ", obtido: " << v;
    }

}

TEST(TermTest, Anagramas) {
    verifica("agonista", "santiago", "VERDADEIRO");
    verifica("conversadora", "conservadora", "VERDADEIRO");
    verifica("regalia", "alegria", "VERDADEIRO");
    verifica("catinga", "cantiga", "VERDADEIRO");
    verifica("ricardo", "corrida", "VERDADEIRO");
}

TEST(TermTest, Comuns) {
    verifica("esquecido", "contrario", "FALSO");
    verifica("tainhota", "tinhosas", "FALSO");
    verifica("moradia", "tremiam", "FALSO");
    verifica("fiscalizar", "arrebentar", "FALSO");
    verifica("volatil", "frageis", "FALSO");
}
