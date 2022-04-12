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
#include "questao.h"
#include "gtest/gtest.h"

using namespace std;

const string hexdigits = "0123456789abcdef";

class TesteQuestao: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }

    string gen_word() {
        string w;

        do {
            int n=1 + (rand() % 4);

            w.clear();
            while (n-- > 0) {
                w += hexdigits[rand() % hexdigits.size()];
            }
        } while (w == "0");

        return w;
    }

    string v2str(vector<string> & v) {
        string r;

        for (auto & s: v) r += s + ':';
        if (! r.empty()) r.pop_back();

        return r;
    }

    // n: qtde de trechos com zeros
    string gen_ipv6() {
        vector<string> ip;
        for (int j=0; j < 8; j++) ip.push_back(gen_word());

        return v2str(ip);
    }

    string gen_ipv6(int n, string & addr) {
        vector<string> ip1, ip2;
        int pos = rand() % (8-n);
        vector<string> zeros(n, "0");
        for (int j=0; j < pos; j++) ip1.push_back(gen_word());
        for (int j=pos+n; j < 8; j++) ip2.push_back(gen_word());

        string t1 = v2str(ip1);
        string t2 = v2str(ip2);

        addr = t1+"::"+t2;
        if (pos > 0) return t1+':'+v2str(zeros)+':'+t2;
        else return v2str(zeros)+':'+t2;
    }
};

TEST_F(TesteQuestao, Compacto)
{
    for (int i=0; i < 10; i++) {
        try {
            string ip, expip;

            ip = gen_ipv6(1+(rand() % 7), expip);
            string rip = compacta_ipv6(ip);
            if (expip != rip) {
                FAIL() << "IP compacto: " << ip
                       << ", esperado=" << expip
                       << ", obtido=" << rip;
                return;
            }
        } catch (...) {
            FAIL() << "ocorreu uma exceção";
        }
    }
}

TEST_F(TesteQuestao, Minimo)
{
    try {
        string expip="::", ip = "0:0:0:0:0:0:0:0";

        string rip = compacta_ipv6(ip);
        if (expip != rip) {
            FAIL() << "IP compacto: " << ip
                   << ", esperado=" << expip
                   << ", obtido=" << rip;
            return;
        }
    } catch (...) {
        FAIL() << "ocorreu uma exceção";
    }
}

TEST_F(TesteQuestao, Expandido) {
    for (int i=0; i < 10; i++) {
        try {
            string ip;

            ip = gen_ipv6();
            string rip = compacta_ipv6(ip);
            if (ip != rip) {
                FAIL() << "IP: " << ip
                       << ", esperado=" << ip
                       << ", obtido=" << rip;
                return;
            }
        } catch (...) {
            FAIL() << "ocorreu uma exceção";
        }
    }
}

