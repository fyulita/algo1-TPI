//
//
#include <cstdlib>
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;


/* Primer Ejercicio */
bool esMatriz(const imagen& img) {
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

bool vacia(const imagen& img) {
    bool resp = img.size() == 1 and img[0].size() == 0;
    return resp;
}

bool esBinaria(const imagen& img) {
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
    if(p[0] < A.size() && p[0] >= 0 && p[1] >= 0 && p[1] < A[0].size() && A[p[0]][p[1]] == 1){
        return true;
    }
    return false;
}