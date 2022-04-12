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

const vector<pair<string,string>> dialogo1 = {
        {">", "Mario Correa"}, {"0", ""},
        {">", "Joaquim Silva"},
                {"1", ""}, {">", "Dona Bilica"}, {"2", ""},
                {">", "?"}, {"Mario Correa", ""}, {">", "Mariazinha"},
                {"2", ""}, {">", "?"}, {"Joaquim Silva", ""},
                {">", "?"}, {"Dona Bilica", ""}, {">", "?"},
                {"Mariazinha", ""}, {">", "sair"}};

const vector<pair<string,string>> dialogo2 = {
        {">", "Manuel das Praias"}, {"0", ""},
        {">", "?"}, {"Manuel das Praias", ""},
        {">", "?"}, {"", ""},
        {">", "sair"}
};

const vector<pair<string,string>> dialogo3 = {
        {">", "Manuel da Noquinha"}, {"0", ""},
        {">", "Juarez Tavora"}, {"1", ""},
        {">", "Nininha da Dona Maria"}, {"2", ""},
        {">", "Zezito"}, {"3", ""},
        {">", "?"}, {"Manuel da Noquinha", ""},
        {">", "?"}, {"Juarez Tavora", ""},
        {">", "?"}, {"Nininha da Dona Maria", ""},
        {">", "?"}, {"Zezito", ""},
        {">", "sair"}
};

bool roda2(const vector<pair<string,string>> & dialogo, vector<string> & res) {
    Terminal term(PROG);
    term.set_timeout(1);
    bool ok = true;

    for (auto & p: dialogo) {
        auto rx = term.leia(1024, '\n');
        strip(rx);
        if (rx != p.first) ok = false;
        if (! p.second.empty()) {
            term.escreva(p.second+'\n');
        }
        res.push_back(rx+p.second);
    }

    return ok;
}

string to_string(const vector<pair<string,string>> & v) {
    string r;

    for (auto & p: v) {
        r += p.first + p.second + '\n';
    }

    return r;
}

void verifica(const vector<pair<string,string>> & dialogo) {
    vector<string> res;

    if (!roda2(dialogo, res)) {
        FAIL() << "Obtido: " << v2str(res,'\n') << endl
               << "Esperado: " << to_string(dialogo) << endl;
    }

}

TEST(TermTest, Intercalado) {
    verifica(dialogo1);
}

TEST(TermTest, Simples) {
    verifica(dialogo2);
}

TEST(TermTest, PediuMaisDoQueTinha) {
    verifica(dialogo3);
}

