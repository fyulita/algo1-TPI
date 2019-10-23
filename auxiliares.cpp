#include <cstdlib>
#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

using namespace std;

/* Primer Ejercicio */
bool esMatriz(const imagen &img) {
    bool resp = true;
    for (int i = 0; i < img.size() - 1; i++) {
        int len = img[i].size();
        if (len == 0) {
            resp = false;
        } else {
            for (int j = i + 1; j < img.size(); j++) {
                if (img[j].size() != len) {
                    resp = false;
                }
            }
        }
    }
    return resp;
}

bool vacia(const imagen &img) {
    bool resp = img.size() == 1 and img[0].size() == 0;
    return resp;
}

bool esBinaria(const imagen &img) {
    bool resp = true;
    for (int i = 0; i < img.size(); i++) {
        for (int j = 0; j < img[i].size(); j++) {
            if ((img[i][j] != 0) and (img[i][j] != 1)) {
                resp = false;
            }
        }
    }
    return resp;
}


/* Segundo Ejercicio */

bool pixelValidoEncendido(pixel p, imagen A){
    if(p.size() != 2){
        return false;
    }
    return p[0] < A.size() && p[0] >= 0 && p[1] >= 0 && p[1] < A[0].size() && A[p[0]][p[1]] == 1;
}

bool perteneceALista(pixel p, sqPixel sq){
    int i= sq.size()-1;
    bool resp = false;
    while(i >= 0 ){
        if (sq[i] == p)
            resp = true;
        i--;
    }
    return resp;
}

bool existeCamino(const imagen &A, const pixel &p, const pixel &q, int k) {
    bool resp;
    int numPixelA = A.size() * A[0].size(), i = 0;
    sqPixel figura(0) ;
    figura.push_back(p);
    sqPixel nuevaFigura;
    nuevaFigura.push_back(p);
    pixel tempArriba=p, tempAbajo=p, tempIzquierda=p, tempDerecha=p;
    pixel tempAbajoIzquierda=p, tempAbajoDerecha=p, tempArribaIzquierda=p, tempArribaDerecha=p;
    while(numPixelA > 0)
    {
        i = figura.size()-1;
        while (figura == nuevaFigura && i >= 0 )
        {
            if(k==8){
                tempArribaDerecha[1] = nuevaFigura[i][1] + 1;
                tempArribaDerecha[0] =nuevaFigura[i][0] + 1;
                if(not(perteneceALista(tempArribaDerecha, nuevaFigura)) && pixelValidoEncendido(tempArribaDerecha, A)){
                    nuevaFigura.push_back(tempArribaDerecha);
                }

                tempArribaIzquierda[1] = nuevaFigura[i][1] + 1;
                tempArribaIzquierda[0] =nuevaFigura[i][0] - 1;
                if(not(perteneceALista(tempArribaIzquierda,nuevaFigura)) && pixelValidoEncendido(tempArribaIzquierda, A))
                {
                    nuevaFigura.push_back(tempArribaIzquierda);
                }

                tempAbajoIzquierda[1] = nuevaFigura[i][1] - 1;
                tempAbajoIzquierda[0] =nuevaFigura[i][0] - 1;
                if(not(perteneceALista(tempAbajoIzquierda, nuevaFigura)) && pixelValidoEncendido(tempAbajoIzquierda, A))
                {
                    nuevaFigura.push_back(tempAbajoIzquierda);
                }

                tempAbajoDerecha[1] = nuevaFigura[i][1] - 1;
                tempAbajoDerecha[0] =nuevaFigura[i][0] + 1;
                if(not(perteneceALista(tempAbajoDerecha, nuevaFigura)) && pixelValidoEncendido(tempAbajoDerecha, A))
                {
                    nuevaFigura.push_back(tempAbajoDerecha);
                }
            }
            tempArriba[0] = nuevaFigura[i][0];
            tempArriba[1] = nuevaFigura[i][1] + 1;

            tempAbajo[0] = nuevaFigura[i][0];
            tempAbajo[1] = nuevaFigura[i][1] - 1;

            tempIzquierda[1] = nuevaFigura[i][1];
            tempIzquierda[0] = nuevaFigura[i][0] - 1;

            tempDerecha[1] = nuevaFigura[i][1];
            tempDerecha[0] = nuevaFigura[i][0] + 1;

            if(not(perteneceALista(tempArriba, nuevaFigura)) && pixelValidoEncendido(tempArriba, A))
            {
                nuevaFigura.push_back(tempArriba);
            }

            if(not(perteneceALista(tempAbajo, nuevaFigura)) && pixelValidoEncendido(tempAbajo, A))
            {
                nuevaFigura.push_back(tempAbajo);
            }

            if(not(perteneceALista(tempDerecha, nuevaFigura)) && pixelValidoEncendido(tempDerecha, A))
            {
                nuevaFigura.push_back(tempDerecha);
            }

            if(not(perteneceALista(tempIzquierda, nuevaFigura)) && pixelValidoEncendido(tempIzquierda, A))
            {
                nuevaFigura.push_back(tempIzquierda);
            }

            i--;
        }

        figura = nuevaFigura;

        numPixelA--;
    }
    if(perteneceALista(q,figura))
    {
        resp = true;
    }

    return resp;
}

/* Tercer Ejercicio */

bool imagenApagada(const imagen &A) {
    bool resp = true;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] != 0) {
                resp = false;
            }
        }
    }
    return resp;
}

bool contenidoSqPixel(const sqPixel &p, const vector<sqPixel> &S) {
    bool resp = false;
    for (int i = 0; i < S.size(); i++){
        if (S[i] == p) {
            resp = true;
        }
    }
    return resp;
}

sqPixel hacerRegion(const imagen &A, const pixel &p, int k) {
    sqPixel resp;
    pixel q(2);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            q[0] = i;
            q[1] = j;
            if (existeCamino(A, p, q, k) or p == q) {
                resp.push_back(q);
            }
        }
    }
    return resp;
}

vector<sqPixel> regiones(const imagen &A, int k) {
    vector<sqPixel> resp;
    pixel p(2);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            p[0] = i;
            p[1] = j;
            if (pixelValidoEncendido(p, A) and not contenidoSqPixel(hacerRegion(A, p, k), resp)) {
                resp.push_back(hacerRegion(A, p, k));
            }
        }
    }
    return resp;
}

float promedioAreas(const imagen &A, int k) {
    float prom = 0;
    for (int i = 0; i < regiones(A, k).size(); i++) {
        float tamanoRegion = (float)regiones(A, k)[i].size();
        float regionesTotales = (float)regiones(A, k).size();
        prom = prom + (tamanoRegion / regionesTotales);
    }
    return prom;
}
/*Cuarto ejercicio*/

bool tocaConBackgroundOBorde(pixel p, imagen A, int k){
    bool resp = false;
    pixel arriba=p, abajo=p, izquierda=p, derecha=p;
    arriba[1] += 1;
    abajo[1] -= 1;
    derecha[0] += 1;
    izquierda[0] -= 1;
    if(not pixelValidoEncendido(abajo, A) || not pixelValidoEncendido(arriba, A) || not pixelValidoEncendido(derecha, A) || not pixelValidoEncendido(izquierda, A)){
        resp = true;
    }
    if(k==8 && resp != true) {
        pixel abajoIzquierda = p, abajoDerecha = p, arribaIzquierda = p, arribaDerecha = p;
        abajoIzquierda[0] -= 1;
        abajoIzquierda[1] -= 1;
        abajoDerecha[0] += 1;
        abajoDerecha[1] -= 1;
        arribaIzquierda[0] -= 1;
        arribaIzquierda[1] += 1;
        arribaDerecha[0] += 1;
        arribaDerecha[1] += 1;
        if(not pixelValidoEncendido(abajoDerecha, A) || not pixelValidoEncendido(arribaDerecha, A) || not pixelValidoEncendido(abajoIzquierda, A) || not pixelValidoEncendido(arribaIzquierda, A)){
            resp = true;
        }
    }

    return resp;
}


sqPixel sonTodosLosDelContorno(const imagen &A, sqPixel &edges, int k)
{
    int i = 0,j = 0;

    while(i <= A.size() -1){
        j = 0;
        while(j <= A[0].size() - 1){
            if(A[i][j] == 1 && (tocaConBackgroundOBorde({i,j}, A, k) )){
                edges.push_back({i,j});
            }
            j++;
        }
        i++;
    }
    return edges;
}