//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <prglib.h>
#include "pathname.h"
#include "Terminal.h"
#include "gtest/gtest.h"

using std::string;
using std::to_string;

class TestePath: public ::testing::Test {
protected:
    const int N = 12;
    const string partes[12] = {"usr", "home", "lib", "share", "aluno", "docs", "tmp", "bin", "local", "etc", "default", "soft"};

    string gen_part(bool extenso) {
        string s;
        if (extenso) {
            if ((rand() % 128) < 64) {
                if ((rand() % 16) < 8) s = ".";
                else s = "..";
            } else s= partes[rand() % N];
        } else s = partes[rand() % N];
        return s;
    }

    string gen_path(bool extenso) {
        string p = "/";
        int n = 3 + (rand() % 4)  ;

        while (n-- > 0) {
            p += gen_part(extenso) + "/";
        }
        p += gen_part(extenso);
        return p;
    }

    string meu_reduz(const string & path) {
        string cmd = "python3 -c \"import os; print(os.path.normpath(\'" + path+"\'))\"";
        Terminal term(cmd);

        string res = term.leLinha();
        strip(res);

        return res;

    }

    virtual void SetUp() {
        srand(clock());
    }

};

/*::testing::AssertionResult AssertSubstitui(const char* texto_expr,
                                               const char* sub_expr,
                                               const char* outra_expr,
                                               const char* correto_expr,
                                               const string & texto,
                                               const string & sub,
                                               const string & outra,
                                               const string & correto) {
    string res = substitui(texto, sub, outra);
    if (res == correto) return ::testing::AssertionSuccess();

    return ::testing::AssertionFailure() << "texto=" << texto << ", " << sub_expr << "=" << sub << ", " << outra_expr << "=" << outra << ": "
                                         << " resultado deveria ser: " << correto
                                         << ", mas sua função retornou: " << res;
}
*/

TEST_F(TestePath, Vazio) {
    try {
        string r = reduz_caminho("");

        if (! r.empty()) {
            FAIL() << "caminho vazio não pode ser reduzido, mas sua função retornou: \"" << r << "\"";
        }
    } catch (...) {
        FAIL() << "ocorreu uma exceção: caminho=\"\"";
    }
}

TEST_F(TestePath, Simples) {
    string r = gen_path(false);
    try {
        string s = reduz_caminho(r);
        if (r != s) {
            FAIL() << "Caminho: " << r << " não pode ser reduzido, mas sua função retornou: \""<< s << "\"";
        }
    } catch (...) {
        FAIL() << "ocorreu uma exceção: caminho=" << r;
    }
}

TEST_F(TestePath, Extenso) {
    for (int n=10; n > 0; n--) {
        string r = gen_path(true);
        try {
            string s = reduz_caminho(r);
            string x = meu_reduz(r);
            if (x != s) {
                FAIL() << "Caminho \""+r+"\" deve ser reduzido para: \"" + x << "\" , mas sua função retornou: \""  << s << "\"";
                return;
            }
        } catch (...) {
            FAIL() << "ocorreu uma exceção: caminho=" << r;
            return;
        }
    }
}
