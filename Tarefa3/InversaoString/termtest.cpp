//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./InversaoString"

string roda(const string & dado) {
    Terminal term(PROG);

    term.escreva(dado+'\n');
    auto res = term.leLinha();
    strip(res);
    return res;
}

TEST(TermTest, Normal) {
    string palavras[] = {"banana", "morango", "laranja","sapoti", "siriguela","melancia"};
    for (auto & dado: palavras) {
        string res = roda(dado);
        string rev = dado;
        reverse(rev.begin(), rev.end());

        EXPECT_EQ(rev, res);
    }
}

TEST(TermTest, Simples) {
    string palavras[] = {"a","B","c","d","f","G","g","K","z"};
    for (auto & dado: palavras) {
        string res = roda(dado);

        EXPECT_EQ(dado, res);
    }
}

TEST(TermTest, Vazio) {
        string res = roda("");

        EXPECT_EQ("", res);

}
