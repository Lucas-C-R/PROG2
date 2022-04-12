//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./Prog"


class Tester : public ::testing::Test {

protected:
    const vector<string> frases_ok = {"gentileza gera gentileza", "coisa gera gera coisa",
                                       "mar bravio distante bravio mar","coisarada",
                                       "onibus transita rapido e pontual onde pontual e rapido transita onibus"};
    const vector<string> frases_nao = {"onibus transita rapido e pontual onde rapido e pontual transita onibus",
                                       "por muitos caminhos seguiu o andarilho",
                                       "certo estava de seus acertos mas os acertos nao significavam que estava certo",
                                       "coelho corre era um livro que nada tinha do bicho coelho",
                                       "noite calada o cao latia e latia o cao calada noite"};
    virtual void SetUp() {
//        srand(clock());
    }

    string roda(const string & w) {
        Terminal term(PROG);

        term.escreva(w+'\n');
        auto res = term.leLinha();
        strip(res);
        return res;
    }

    void testa(const vector<string> & v, const string & correto) {
        for (auto & w: v) {
            auto r = roda(w);

            if (r != correto) {
                FAIL() << "frase: " << w<< ", esperado: " << correto << ", obtido: " << r;
            }
        }
    }
};

// Testa com uma frase composta por 2 ou mais palavras
TEST_F(Tester, Invertiveis) {
    testa(frases_ok, "VERDADEIRO");
}

TEST_F(Tester, NaoInvertiveis) {
    testa(frases_nao, "FALSO");
}

