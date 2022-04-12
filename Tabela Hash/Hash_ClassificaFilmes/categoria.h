//
// Created by sobral on 04/02/2021.
//

#ifndef PROG_CATEGORIA_H
#define PROG_CATEGORIA_H

#include <string>

using std::string;

enum Categoria {EXCELENTE, BOM, REGULAR, RUIM};

Categoria to_cat(const string & s);

namespace std {
    template <> struct hash<Categoria> {
        size_t operator()(const Categoria & c) const {
            return (long)c;
        }
    };
}

#endif //PROG_CATEGORIA_H
