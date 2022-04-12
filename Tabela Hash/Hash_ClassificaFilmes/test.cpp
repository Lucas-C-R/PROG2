//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>
#include <list>
#include <random>
#include <chrono>
#include <unordered_map>

#include "categoria.h"
#include "questao.h"
#include "gtest/gtest.h"

using namespace std;

const char SEP[] = ",.;:/|-&%$+=*?";
const char VOGAIS[] = "aeiouy";
const char CONS[] = "bcdfghjklmnpqrstvwxz";
const string pathname = "../filmes.txt";

template <typename T> void embaralha(vector<T> & l) {
    static bool _started = false;
    static std::default_random_engine generator;

    if (not _started) {
        auto t = std::chrono::high_resolution_clock::now();
        _started = true;
        generator.seed(std::chrono::high_resolution_clock::to_time_t(t));
    }
    shuffle(l.begin(), l.end(), generator);
}

class TesteQuestao: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }

    void carrega(unordered_map<string,Categoria> & t1, int N, unordered_map<Categoria,int> & t2) {
        ifstream arq(pathname);
        if (not arq.is_open()) {
            FAIL() << "Arquivo " << pathname << " não pode ser aberto !";
            return;
        }
        vector<string> l;

        string s;
        while (getline(arq, s)) l.push_back(s);
        arq.close();

        embaralha(l);
        for (auto & s: l) {
            if (N-- == 0) break;
            int pos = s.find(';');
            if (pos != string::npos) {
                string k = s.substr(0, pos);
                auto v = to_cat(s.substr(pos+1));

                if (not t1.count(k)) {
                    t1.emplace(k, v);
                    try {
                        t2[v]++;
                    } catch (...) {
                        string err = "chave ";
                        err += v+" não existe em t2 !";
                        FAIL() << err;
                        return;
                    }
                }
            }
        }
    }

    void inicia_tab(unordered_map<Categoria,int> & t3) {
        t3.emplace(EXCELENTE, 0);
        t3.emplace(BOM, 0);
        t3.emplace(REGULAR, 0);
        t3.emplace(RUIM, 0);
    }

    template <typename T,typename K> list<T> lista_chaves(unordered_map<T,K> & tab) {
        list<T> v;

        for (auto &p: tab) {
            v.push_back(p.first);
        }
        v.sort();
        return v;
    }

    string lista_categorias(list<Categoria> & l) {
        string r;

        if (l.empty()) return r;
        for (auto & x: l) {
            switch (x) {
                case EXCELENTE:
                    r += "EXCELENTE,";
                    break;
                case BOM:
                    r += "BOM,";
                    break;
                case REGULAR:
                    r += "REGULAR,";
                    break;
                case RUIM:
                    r += "RUIM,";
                    break;
                default:
                    r += "ERRO!!!,";
                    break;
            }
        }
        r.pop_back();
        return r;
    }

    void compara_tab(unordered_map<string, Categoria> & t1, unordered_map<Categoria,int> & t3) {
        unordered_map<Categoria,int> t2;

        try {
            sumariza(t1, t2);
        } catch (...) {
            FAIL() << "disparou exceção ao sumarizar tabela de filmes";
            return;
        }
        auto l2 = lista_chaves(t2);
        auto l3 = lista_chaves(t3);

        if (l2 != l3) {
            string err = "Sumário dos filmes por categoria não tem exatamente as categorias (EXCELENTE, BOM, REGULAR, RUIM)";
            if (! l2.empty()) {
                err += "\nSua tabela tem estas chaves: "+lista_categorias(l2);
            } else {
                err += "\nSua tabela está VAZIA !";
            }
            FAIL() << err;
            return;
        }
        for (auto & p2: t2) {
            string ok;
            auto n3 = t3[p2.first];
            if (p2.second != n3) {
                string err = "Categoria ";
                err += p2.first+" tem contagem "+to_string(p2.second)+", mas correto é "+to_string(n3);
                if (ok.size() > 0) err += "\nDemais categorias com contagens corretas: "+ok;
                FAIL() << err;
                return;
            }
            ok += p2.first + ":" + to_string(p2.second)+" ";
        }
        return;
    }

    string mostra(const list<string> & l, char sep=' ') {
        if (l.empty()) return "";

        ostringstream out;

        for (auto & x: l) out << x << sep;
        string res = out.str();
        res.pop_back();
        return res;
    }

};

TEST_F(TesteQuestao, OK)
{
    for (int j=0; j < 4; j++) {
        unordered_map<string,Categoria> t1;
        unordered_map<Categoria,int> t3;

        inicia_tab(t3);
        carrega(t1, 200+(rand()%500), t3);

        compara_tab(t1, t3);
    }
}

TEST_F(TesteQuestao, Vazio)
{
    unordered_map<string,Categoria> t1;
    unordered_map<Categoria,int> t3;

    inicia_tab(t3);

    compara_tab(t1, t3);
}
