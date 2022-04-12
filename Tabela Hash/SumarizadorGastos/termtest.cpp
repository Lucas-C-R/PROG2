//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <map>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./Prog"

struct Caso {
    string nome;
    int mes;
    string result;
};

string roda(const string & cmd, const Caso & caso) {
    Terminal term(cmd);

    term.escreva(caso.nome + "\n");
    term.escreva(to_string(caso.mes)+"\n");
    auto res = term.leiaTudo();
    strip(res);
    return res;
}

void verifica(const Caso & caso) {
    string arq = PROG;

    auto v = roda(arq, caso);

    if (v != caso.result) {
        FAIL() << "Cliente: " << caso.nome << ", mes: " << caso.mes << endl
               << "Esperado: " << caso.result << endl
               << "Obtido: " << v;
    }
}

TEST(TermTest, MesInvalido) {
    Caso caso = {"Seu Maneca", 28, "mês inválido"};
    verifica(caso);
}

TEST(TermTest, SemGastos) {
    Caso caso = {"Sponge Bob", 7, "sem compras no mes 7"};
    verifica(caso);
}

TEST(TermTest, OK) {
    const vector<Caso> casos = {{"Dona Bilica", 3, "Total: 452.85"},
                                {"Seu Maneca", 10, "Total: 724.85"},
                                {"Juquinha", 8, "Total: 161.20"}};

    for (auto & caso: casos) verifica(caso);
}
