#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esMatriz(const imagen &img);
bool vacia(const imagen &img);
bool esBinaria(const imagen &img);
bool pixelValidoEncendido(pixel p, imagen A);
bool existeCamino(const imagen &A, const pixel &p, const pixel &q, int k);
bool imagenApagada(const imagen &A);
bool contenidoSqPixel(const sqPixel &p, const vector<sqPixel> &S);
sqPixel hacerRegion(const imagen &A, const pixel &p, int k);
vector<sqPixel> regiones(const imagen &A, int k);
float promedioAreas(const imagen &A, int k);
sqPixel sonTodosLosDelContorno(const imagen &A, sqPixel &edges, int k);
void borrarImagen(imagen &A);
sqPixel pixelesActivadosDelElemEstrucCentrado(imagen &A, const imagen &B, const pixel &p);
void dilatacion(imagen &A, const imagen &B);
void erosion(imagen &A, const imagen &B);
int obtenerRegion(imagen &A, const pixel &semilla, int ite);

#endif //SOLUCION_AUXILIARES_H
