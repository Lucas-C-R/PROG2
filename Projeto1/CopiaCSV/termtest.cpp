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

const string csv = "../data/casos_sc.csv";

vector<string> roda(const string & cmd) {
    Terminal term(cmd);

    auto res = term.leLinhas();
    return res;
}

void verifica(const vector<int> & caso) {
    string cols = v2str(caso, '_');
    string cmd = PROG;
    cmd += " " + csv + " " + v2str(caso);
    string arq = "cat ";
    arq += " ../data/cols_"+cols+".txt";;

    auto res = roda(cmd);
    auto v = roda(arq);

    if (v.size() != res.size()) {
        FAIL() << "Caso: " << v2str(caso)<< ": resultado deve ter "
               << v.size() << " linhas, mas seu programa gerou "
               << res.size() << " linhas";
    }
    if (v != res) {

        FAIL() << "Caso " << v2str(caso) << ": esperado: " << v2str(v, '\n') << endl
               << "Obtido: " << v2str(res,'\n');
    }

}

TEST(TermTest, UmaColuna) {
    vector<int> v = {9};
    verifica(v);
}

TEST(TermTest, DuasColunas) {
    vector<int> v = {0,17};
    verifica(v);
}

TEST(TermTest, TresColunasDesordenadas) {
    vector<int> v = {4,8,0};
    verifica(v);
}

TEST(TermTest, QuatroColunasDesordenadas) {
    vector<int> v = {12, 8, 4,0};
    verifica(v);
}

TEST(TermTest, CincoColunas) {
    vector<int> v = {1,3,4,8,12};
    verifica(v);
}
