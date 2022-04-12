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

TEST(TermTest, Invalido) {
    auto res = roda("dados.txt");
    string resp;
    try {
        resp = res[0];
        strip(resp);
    } catch(...) {
        FAIL() << "Seu programa deve apresentar a mensagem \"arquivo invalido\", mas ele nada apresentou na tela";
    }
    ASSERT_EQ("arquivo invalido", resp);
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
    reverse(v.begin(), v.end());
    return v;
}

TEST(TermTest, Normal) {
    auto res = roda("palavras.txt");
    auto inv = leArq("palavras.txt");
    auto resp = v2str(res);
    strip(resp);
    auto rev = v2str(inv);

    ASSERT_EQ(rev, resp);
}

TEST(TermTest, Simples) {
    auto res = roda("pessoas.txt");
    auto inv = res;
    reverse(inv.begin(), inv.end());
    auto resp = v2str(res);
    auto rev = v2str(inv);

    ASSERT_EQ(rev, resp);
}

TEST(TermTest, Vazio) {
        auto res = roda("");
        if (res.size() > 0) FAIL() << " se arquivo for vazio, nada deve ser mostrado na tela, mas seu programa apresentou: " << v2str(res);
}
