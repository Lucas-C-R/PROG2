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

/* Casos:
Formulário com parâmetros que aparecem uma vez por linha
Formulário com parâmetros que aparecem mais de uma vez por linha
Parâmetros não informados: resultado deve mostrá-los sem modificações
Parâmetros que não existem no formulário: devem ser ignorados
 */

vector<string> roda(const string & cmd) {
    Terminal term(cmd);

    auto res = term.leLinhas();
    return res;
}

string gera_argv(const map<string,string> & caso) {
  string args;

  for (auto & par: caso) {
      args += par.first + "=\"" + par.second + "\" ";
  }
  return args;
}

void verifica(int n, const map<string,string> & caso) {
    string arq = "cat ../data/res"+to_string(n)+".txt";
    string arqres = PROG;
    string args=gera_argv(caso);
    arqres += " ../data/arquivo"+to_string(n)+".txt " + args;

    auto v = roda(arq);
    auto res = roda(arqres);

    if (v != res) {
        auto e = v2str(v);
        auto r = v2str(res);
        FAIL() << "Args: " << args << endl
               << "Esperado: " << e << endl
               << "Obtido: " << r;
    }

}

TEST(TermTest, FormularioSimples) {
    map<string,string> caso = {
            {"nome", "Joaozinho Maneca"},
            {"nacionalidade", "brasileira"},
            {"rg", "8.898.091-7"},
            {"data", "10/10/2020"}
    };
    verifica(1, caso);
}

TEST(TermTest, FormularioMultiplosPorLinha) {
    map<string,string> caso = {
            {"pais", "Cocanha"},
            {"pessoa", "Lars Silva Smith"},
            {"idade", "27"},
            {"anos", "7"}
    };
    verifica(2, caso);
}

TEST(TermTest, ParametrosAusentes) {
    map<string,string> caso = {
            {"name", "Alan Turing"},
            {"country", "England"},
            {"affiliation", "HUT 8"},
    };
    verifica(3, caso);
}

TEST(TermTest, ParametrosExcesso) {
    map<string,string> caso = {
            {"nome", "Joaozinho Maneca"},
            {"nacionalidade", "brasileira"},
            {"rg", "8.898.091-7"},
            {"data", "10/10/2020"},
            {"montante", "100.000,00"},
            {"ativos", "ações"}
    };
    verifica(1, caso);
}

