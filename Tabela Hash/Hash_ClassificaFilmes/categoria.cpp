//
// Created by sobral on 04/02/2021.
//

#include "categoria.h"

Categoria to_cat(const string & s) {
    if (s == "EXCELENTE") return EXCELENTE;
    if (s == "BOM") return BOM;
    if (s == "REGULAR") return REGULAR;
    if (s == "RUIM") return RUIM;
    throw -1;
}