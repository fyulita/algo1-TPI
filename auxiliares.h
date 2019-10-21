//
// Created by leticia on 07/05/19.
//

#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esMatriz(const imagen& img);
bool vacia(const imagen& img);
bool esBinaria(const imagen& img);
bool existeCamino(const imagen& img, const pixel& p, const pixel& q, int k);

#endif //SOLUCION_AUXILIARES_H
