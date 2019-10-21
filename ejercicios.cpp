#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

// Ejercicio 1

bool esImagenValida(const imagen& img) {
    bool resp = ((not vacia(img)) and esMatriz(img)) and esBinaria(img);
    return resp;
}

// Ejercicio 2

bool sonPixelesConectados(const imagen &A, pixel p, pixel q, int k){
    if (p=q){
        return true;
    }
    int numPixelA = a.size() * a[0].size(), i = 0;
    sqPixel figura = <p>;
    sqPixel nuevaFigura = figura ;
    pixel tempArriba, tempAbajo, tempIzquierda, tempDerecha;
    pixel tempAbajoIzquierda, tempAbajoDerecha, tempArribaIzaquierda, tempArribaDerecha;
    while(numPixel > 0)
    {
        if(std::find(figura.begin(), figura.end(), q) != figura.end())
        {
            return true;
        }

        i = fiugra.size()-1;
        while (figura == nuevaFigura && i >= 0 )
        {
            if(k=8){
                tempArribaDerecha[1] = nuevaFigura[i][1] + 1;
                tempArribaDerecha[0] =nuevaFigura[i][0] + 1;
                if(pixelValidoEncendido(tempArribaDerecha, A) != true)
                {
                    tempArribaDerecha[1] =nuevaFigura[i][1] - 1;
                    tempArribaDerecha[0] =nuevaFigura[i][0] - 1;
                }
                if(not(std::find(nuevaFigura.begin(), nuevaFigura.end(), tempArribaDerecha) != nuevaFigura.end()))
                {
                    nuevaFigura.push_Back(tempArribaDerecha);
                }


                tempArribaIzquierda[1] = nuevaFigura[i][1] + 1;
                tempArribaIzquierda[0] =nuevaFigura[i][0] - 1;
                if(pixelValidoEncendido(tempArribaIzquierda, A) != true)
                {
                    tempArribaIzquierda[1] =nuevaFigura[i][1] - 1;
                    tempArribaIzquierda[0] =nuevaFigura[i][0] + 1;
                }
                if(not(std::find(nuevaFigura.begin(), nuevaFigura.end(), tempArribaIzquierda) != nuevaFigura.end()))
                {
                    nuevaFigura.push_Back(tempArribaIzquierda);
                }

                tempAbajoIzquierda[1] = nuevaFigura[i][1] - 1;
                tempAbajoIzquierda[0] =nuevaFigura[i][0] - 1;
                if(pixelValidoEncendido(tempArribaIzquierda, A) != true)
                {
                    tempAbajoIzquierda[1] =nuevaFigura[i][1] + 1;
                    tempAbajoIzquierda[0] =nuevaFigura[i][0] + 1;
                }
                if(not(std::find(nuevaFigura.begin(), nuevaFigura.end(), tempAbajoIzquierda) != nuevaFigura.end()))
                {
                    nuevaFigura.push_Back(tempAbajoIzquierda);
                }

                tempAbajoDerecha[1] = nuevaFigura[i][1] - 1;
                tempAbajoDerecha[0] =nuevaFigura[i][0] + 1;
                if(pixelValidoEncendido(tempAbajoDerecha, A) != true)
                {
                    tempAbajoDerecha[1] =nuevaFigura[i][1] + 1;
                    tempAbajoDerecha[0] =nuevaFigura[i][0] - 1;
                }
                if(not(std::find(nuevaFigura.begin(), nuevaFigura.end(), tempAbajoDerecha) != nuevaFigura.end()))
                {
                    nuevaFigura.push_Back(tempAbajoDerecha);
                }
            }


            tempArriba[1] = nuevaFigura[i][1] + 1;
            if(pixelValidoEncendido(tempArriba, A) != true)
            {
                tempArriba[1] =nuevaFigura[i][1] - 1;
            }

            tempAbajo[1] = nuevaFigura[i][1] - 1;
            if(pixelValidoEncendido(tempAbajo, A) != true)
            {
                tempAbajo[1] =nuevaFigura[i][1] + 1;
            }

            tempIzquierda[0] = nuevaFigura[i][0] - 1;
            if(pixelValidoEncendido(tempIzquierda, A) != true)
            {
                tempIzquierda[0] =nuevaFigura[i][0] + 1;
            }
            tempDerecha[0] = nuevaFigura[i][0] + 1;
            if(pixelValidoEncendido(tempDerecha, A) != true)
            {
                tempderecha[0] =nuevaFigura[i][0] - 1;
            }


            if(not(std::find(nuevaFigura.begin(), nuevaFigura.end(), tempArriba) != nuevaFigura.end()))
            {
                nuevaFigura.push_Back(tempArriba);
            }

            if(not(std::find(nuevaFigura.begin(), nuevaFigura.end(), tempAbajo) != nuevaFigura.end()))
            {
                nuevaFigura.push_Back(tempAbajo);
            }

            if(not(std::find(nuevaFigura.begin(), nuevaFigura.end(), tempDerecha) != nuevaFigura.end()))
            {
                nuevaFigura.push_Back(tempDerecha);
            }

            if(not(std::find(nuevaFigura.begin(), nuevaFigura.end(), tempIzquierda) != nuevaFigura.end()))
            {
                nuevaFigura.push_Back(tempIzquierda);
            }

            i--;
        }
        if(figura != nuevaFigura){
            return false;
        }
        figura = nuevaFigura;

        numPixel--;
    }
    return false;

}

/*
bool sonPixelesConectados(const imagen& img, const pixel& p, const pixel& q, int k) {
	bool resp;
    if (p == q) {
        resp = true;
    } else {
        resp = existeCamino(img, p, q, k);
    }
    return resp;
}
*/
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



