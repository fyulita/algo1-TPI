#include <cstdlib>
#include "definiciones.h"
#include "auxiliares.h"

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

bool existeCamino(const imagen &A, const pixel &p, const pixel &q, int k) {
    bool resp;

    return resp;
}

/* Tercer Ejercicio */

bool imagenApagada(const imagen &A) {
    bool resp = true;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (j != 0) {
                resp = false;
            }
        }
    }
    return resp;
}

float promedioAreas(const imagen &A, int k) {
    int prom = 0;
    for (int i = 0; i < regiones(A, k).size(); i++) {
        prom = prom + (regiones(A, k)[i].size() / regiones(A, k).size());
    }
    return prom;
}

vector<sqPixel> regiones(const imagen &A, int k) {
    vector<sqPixel> resp;
    pixel p(2);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            p[0] = i;
            p[1] = j;
            if (activado(A, p) and not contenidoSqPixel(hacerRegion(A, p, k), resp)) {
                resp.push_back(hacerRegion(A, p));
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
        for (int j = 0; j < A[i].size(), j++) {
            q[0] = i;
            q[1] = j;
            if (estanConectados(A, p, q, k)) {
                resp.push_back(q);
            }
        }
    }
    return resp;
}

bool activado(const imagen &A, const pixel &p) {
    bool resp = A[p[0]][p[1]] == 1;
    return resp;
}
