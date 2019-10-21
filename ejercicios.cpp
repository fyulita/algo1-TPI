#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

// Ejercicio 1

bool esImagenValida(const imagen& img) {
    bool resp = ((not vacia(img)) and esMatriz(img)) and esBinaria(img);
    return resp;
}

// Ejercicio 2

bool sonPixelesConectados(const imagen& img, const pixel& p, const pixel& q, int k) {
	bool resp;
    if (p == q) {
        resp = true;
    } else {
        resp = existeCamino(img, p, q, k);
    }
    return resp;
}

// Ejercicio 3

float devolverPromedioAreas(const imagen &A, int k){
	float prom = -1.0;
	// TODO --> cuerpo de funcion
    return prom;
}

// Ejercicio 4

sqPixel calcularContorno(const imagen &A, int k){
    sqPixel edges = {{}};
	// TODO --> cuerpo de funcion
    return edges;
}

// Ejercicio 5

void cerrarForma(imagen &A, const imagen &B){
	// TODO --> cuerpo de funcion
	return;
}

// Ejercicio 6

int obtenerRegionConectada(imagen &A, const pixel &semilla) {
	int ite = 0;
	// TODO --> cuerpo de funcion
	return ite;
}



