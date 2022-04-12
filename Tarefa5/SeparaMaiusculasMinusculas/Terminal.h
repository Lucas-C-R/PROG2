/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Terminal.h
 * Author: msobral
 *
 * Created on 11 de Fevereiro de 2019, 16:07
 */

#ifndef TERMINAL_H
#define TERMINAL_H
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

void strip(string & s);
vector<string> split(const string & s, const string & delim=" \r\n\t");
vector<string> arqlines(const string & path, bool do_strip=true);

string to_string(const string & s);

template <typename T> string v2str(const vector<T> & v, char delim=' ') {
    string r;

    for (auto & x: v) r += to_string(x) + delim;
    if (! r.empty()) r.pop_back();

    return r;
}

const long Timeout = 5; // 5 segundos

class Terminal {
 public:
  Terminal(const string & cmd);

  ~Terminal();

  void set_timeout(const unsigned long & tout) { timeout = tout;}
  int escreva(const string & data);

  // lê até N bytes de cada vez (default: 1024 bytes)
  string leia();
  string leia(int N, char delim=0);

  // lê todo o conteúdo
  string leiaTudo();

  // lê todas as linhas
  vector<string> leLinhas();

  // lê todas as palavras
  vector<string> lePalavras();

  string leLinha();
  string lePalavra();
  
private:
  int master;
  pid_t pid;
  long timeout;
  
  char ** gera_argv(const string & cmd);
};


#endif /* TERMINAL_H */

