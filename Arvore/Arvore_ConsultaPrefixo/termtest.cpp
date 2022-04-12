//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include "Terminal.h"
#include "gtest/gtest.h"

using namespace std;

#define PROG "./Prog"
const string DADOS = "../dados.txt";

void le_tudo(const string & name, vector<string> & v) {
    ifstream arq(name);
    string w;
    while (arq >> w) v.push_back(w);
    sort(v.begin(), v.end());
}

vector<string> palavra_por_prefixo(const vector<string> & v, const string & prefixo) {
    bool achou=false;
    vector<string> res;

    for (auto & w: v) {
        bool ok = (w.find(prefixo) == 0);

        if (achou) {
            if (! ok) break;
            res.push_back(w);
        } else if (ok) {
            achou = true;
            res.push_back(w);
        }
    }

    return res;
}

string sorteia_prefixo(const vector<string> & v) {
    string w;

    while (w.size() < 5) w = v[rand() % v.size()];
    return w.substr(0,w.size()-2);
}

void roda(const unordered_map<string,vector<string>> & tab) {
    string cmd = PROG;
    Terminal term(cmd);
    term.set_timeout(1);

    auto res = term.leia(32, '\n');
    for (auto & par: tab) {
        if (res != ">") {
            FAIL() << "Deve ser apresentado o prompt \">\"antes de ler um nome." << endl
                   << " Seu programa apresentou isto: " << res << endl;
        }
        term.escreva(par.first+'\n');
        vector<string> r;
        auto maxsize = max<int>(par.second.size()+1,100);
        while (r.size() < maxsize) {
            res = term.leia(32,'\n');
            strip(res);
            if (res == ">") break;
            r.push_back(res);
        }
        if (r != par.second) {
            if (par.second.empty()) {
                FAIL() << "Nenhuma palavra tem o prefixo " << par.first <<", então nenhuma palavra deveria ser mostrada."
                       << endl << "Palavras mostradas: " << v2str(r, ",") << endl;
            } else {
                FAIL() << "Palavras esperadas: " << v2str(par.second, ",")
                       << endl << "Palavras obtidas: " << v2str(r, ",") << endl;
            }
        }                                                                                                                                                                                    string name;
    }
    if (res != ">") {
        FAIL() << "Deve ser apresentado o prompt \">\"antes de ler um nome." << endl
               << " Seu programa apresentou isto: " << res << endl;
    }
    term.escreva("\n");
    auto fim = term.leia(32, '\n');
    if (not fim.empty()) {
        FAIL() << "Seu programa deve terminar ao ler uma linha vazia !" << endl;
    }
}

//bool operator!=(const vector<Result> & v1, const vector<Result> & v2) {
//    unordered_set<Result,Result::R_Hash> set;
//
//    for (auto & r: v2) set.insert(r);
//    for (auto & r: v1) {
//        if (! set.count(r)) return true;
//    }
//
//    return false;
//}

TEST(TermTest, SomenteUma) {
    unordered_map<string,vector<string>> tab;
    vector<string> palavras;
    le_tudo(DADOS, palavras);
    string w = sorteia_prefixo(palavras);
    tab[w] = palavra_por_prefixo(palavras, w);
    roda(tab);
}

TEST(TermTest, Algumas) {
    vector<string> palavras;
    le_tudo(DADOS, palavras);
    int num = 2 + (rand() % 2);
    while (num-- > 0) {
        unordered_map<string,vector<string>> tab;
        string w = sorteia_prefixo(palavras);
        tab[w] = palavra_por_prefixo(palavras, w);
        roda(tab);
    }
}

TEST(TermTest, Nada) {
    unordered_map<string,vector<string>> tab;
    string w = "axfeg";
    tab[w];
    roda(tab);
}

