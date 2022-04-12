//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <list>
#include "questao.h"
#include "gtest/gtest.h"

using namespace std;

inline string to_string(const string & s) {
    return s;
}

class TesteOrdenada: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }

    float gen_float() {
        return (rand() % 100) + (rand() % 100)*1e-2;
    }

    template <typename T> string l2str(const list<T> & l, const string & sep=" ") {
        string r;

        if (! l.empty()) {
            auto it = l.begin();
            r = to_string(*it);
            for (it++; it != l.end(); it++) r += sep + to_string(*it);
        }
        return r;
    }

    list<float> gen_list(int n) {
        list<float> l;

        while (n-- > 0) l.push_back(gen_float());

        l.sort();

        return l;
    }
    template <typename T> void do_test(list<T> & l, list<T> & r, const T & x) {
        try {
            insere_ordenado(l, x);

            if (l != r) {
                FAIL() <<"Conteúdo inicial da lista: " << l2str(l) << endl
                       << "Tentou inserir: " << x << endl
                       << "Após inserção deveria estar assim: " << l2str(r) << endl
                       << "Mas estava assim: " << l2str(l);
            }
        } catch (...) {
            FAIL() <<"falha fatal ao chamar insere_ordenado";
        }
    }
};

TEST_F(TesteOrdenada, Vazia) {
    list<string> l, r = {"coisarada"};
    string x = "coisarada";

    do_test(l, r, x);
}

TEST_F(TesteOrdenada, Menor) {
    list<float> l = gen_list(7+(rand()%6));
    list<float> r = l;
    float x = l.front()-0.1;
    r.push_front(x);

    do_test(l, r, x);
}

TEST_F(TesteOrdenada, Maior)        {
    list<float> l = gen_list(7+(rand()%6));
    list<float> r = l;
    float x = l.back()+0.1;
    r.push_back(x);

    do_test(l, r, x);
}

TEST_F(TesteOrdenada, Meio) {
    list<float> l = gen_list(7+(rand()%6));
    list<float> r = l;
    float x = (l.front()+l.back())/2;
    r.push_front(x);
    r.sort();

    do_test(l, r, x);
}
