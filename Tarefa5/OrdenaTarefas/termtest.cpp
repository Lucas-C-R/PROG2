//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Terminal.h"
#include "gtest/gtest.h"

using namespace std;

#define PROG "./Prog"

vector<string> roda(const string & path) {
    string cmd = PROG;
    cmd += " ../data/"+path;
    Terminal term(cmd);

    auto res1 = term.leLinhas();
    for (auto & s: res1) strip(s);
    return res1;
}

string v2str(vector<string> & v) {
    string r;

    for (auto s: v) {
        strip(s);
        r += s+'\n';
    }
    strip(r);
    return r;
}

vector<string> leArq(const string & path) {
    string p;
    p += "../data/"+path;

    ifstream arq(p);
    string w;
    vector<string> v;

    while (getline(arq, w)) {
        strip(w);
        v.push_back(w);
    }
    return v;
}

TEST(TermTest, Normal) {
    for (int j=1; j < 11; j++) {
        string arq, result;
        arq = "dados"+to_string(j)+".txt";
        result = "res"+to_string(j)+".txt";
        auto res = roda(arq);
        auto inv = leArq(result);
        if (res != inv) {
            FAIL() << "Resultado esperado: " << v2str(inv) << endl << "Resultado obtido: " << v2str(res);
        }
    }
}

TEST(TermTest, Simples) {
    for (int j=1; j < 7; j++) {
        string arq, arq2 = "../data/dados11.txt";
        arq = "dados" + to_string(1+(rand()%10)) + ".txt";
        auto inv = leArq(arq);
        string resp = inv[rand() % inv.size()];
        inv.clear();
        inv.push_back(resp);
        ofstream out(arq2);
        out << resp << endl;
        out.close();

        auto res = roda(arq2);
        if (res != inv) {
            FAIL() << "Resultado esperado: " << v2str(inv) << endl << "Resultado obtido: " << v2str(res);
        }
    }
}

TEST(TermTest, Vazio) {
        auto res = roda("dados12.txt");
        if (res.size() > 0) FAIL() << " se arquivo for vazio, nada deve ser mostrado na tela, mas seu programa apresentou: " << v2str(res);
}
