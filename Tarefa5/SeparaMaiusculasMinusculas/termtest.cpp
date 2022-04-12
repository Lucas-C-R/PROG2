//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./Prog"


class Tester : public ::testing::Test {

protected:
    virtual void SetUp() {
//        srand(clock());
    }

    void le_arq(const string & path, string & data) {
        ifstream arq(path);
        char buf[4096];
        while (arq.read(buf, 4096)) data.append(buf, arq.gcount());
    }

    void roda(int n) {
        string inp = " ../data/texto" + to_string(n) + ".txt";
        string nome = "../data/res" + to_string(n) + ".txt";
        string cmd = PROG + inp;
        Terminal term(cmd);

        auto res = term.leLinhas();
        auto data = arqlines(nome);

        if (res != data) {
            string out = "../data/out" + to_string(n) + ".txt";

            ofstream outp(out);
            for (auto & l: data) outp << l << endl;
            FAIL() << "Ao separar: " << inp << endl
                   << "... resultado deveria ser o mesmo contido em " << nome << endl
                   << " ... mas seu programa gerou o resultado contido em: " << out << endl;
        }
    }

};

// Testa com uma frase composta por 2 ou mais palavras
TEST_F(Tester, Textos) {
    for (int j=1; j < 10; j++) roda(j);
}
