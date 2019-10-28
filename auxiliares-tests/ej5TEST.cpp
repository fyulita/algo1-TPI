#include "gtest/gtest.h"
#include "../auxiliares.h"

TEST(dilatacionTest, tapandooHuecosDeUnPixel) {
    imagen A = {
            {0, 0, 0, 0, 1, 0},
            {0, 1, 1, 0, 0, 1},
            {0, 1, 0, 1, 0, 1},
            {0, 0, 1, 1, 0, 0},
            {0, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {1, 1, 0, 0, 0, 1},
    };
    imagen B = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
    };
    imagen esperada = {
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 0},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
    };

    dilatacion(A,B);

    EXPECT_EQ(esperada, A);
}

TEST(dilatacionTest, cierreConCruz) {
    imagen A = {
            {0, 0, 0, 0, 1, 0},
            {0, 1, 0, 0, 0, 1},
            {0, 1, 0, 1, 0, 1},
            {0, 0, 1, 1, 0, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 1},
    };
    imagen B = {
            {0, 1, 0},
            {1, 1, 1},
            {0, 1, 0},
    };
    imagen esperada = {
            { 0, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1 },
            { 0, 1, 1, 1, 1, 1 },
            { 0, 0, 1, 1, 1, 0 },
            { 1, 1, 0, 1, 0, 1 },
            { 1, 1, 1, 0, 1, 1 },
    };

    dilatacion(A,B);

    EXPECT_EQ(esperada, A);
}

TEST(dilatacionTest, ejemploEnunciadoTPE) {
    imagen A = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    imagen B = {
            {0, 1, 0},
            {1, 1, 1},
            {0, 1, 0},
    };
    imagen esperada = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    dilatacion(A,B);

    EXPECT_EQ(esperada, A);
}

TEST(erosionTest, tapandooHuecosDeUnPixel) {
    imagen A = {
            {0, 0, 0, 0, 1, 0},
            {0, 1, 1, 0, 0, 1},
            {0, 1, 0, 1, 0, 1},
            {0, 0, 1, 1, 0, 0},
            {0, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {1, 1, 0, 0, 0, 1},
    };
    imagen B = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
    };
    imagen esperada = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
    };

    erosion(A,B);

    EXPECT_EQ(esperada, A);
}

TEST(erosionTest, cierreConCruz) {
    imagen A = {
            {0, 0, 0, 0, 1, 0},
            {0, 1, 0, 0, 0, 1},
            {0, 1, 0, 1, 0, 1},
            {0, 0, 1, 1, 0, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 1},
    };
    imagen B = {
            {0, 1, 0},
            {1, 1, 1},
            {0, 1, 0},
    };
    imagen esperada = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
    };

    erosion(A,B);

    EXPECT_EQ(esperada, A);
}

TEST(erosionTest, ejemploEnunciadoTPE) {
    imagen A = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    imagen B = {
            {0, 1, 0},
            {1, 1, 1},
            {0, 1, 0},
    };
    imagen esperada = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    erosion(A,B);

    EXPECT_EQ(esperada, A);
}

TEST(borrarImagenTest, imagenVacia) {
    imagen A = {};
    imagen esperada = {};
    borrarImagen(A);
    EXPECT_EQ(A, esperada);
}

TEST(borrarImagenTest, imagenBorrada) {
    imagen A = {{0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}};
    imagen esperada = {{0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0}};
    borrarImagen(A);
    EXPECT_EQ(A, esperada);
}

TEST(borrarImagenTest, ejemploEnunciadoTPE) {
    imagen A = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    imagen esperada = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    borrarImagen(A);
    EXPECT_EQ(esperada, A);
}

TEST(pixelesActivadosDelElemEstrucCentradoTest, cuadradoCentrado) {
    /* Lo unico que importa de A para esta funcion es su dimension */
    imagen A = {{0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0}};
    imagen B = {{1, 1, 1},
                {1, 1, 1},
                {1, 1, 1}};
    pixel p = {2, 3};
    sqPixel esperado = {{1, 2}, {1, 3}, {1, 4},
                        {2, 2}, {2, 3}, {2, 4},
                        {3, 2}, {3, 3}, {3, 4}};
    EXPECT_EQ(pixelesActivadosDelElemEstrucCentrado(A, B, p), esperado);
}

TEST(pixelesActivadosDelElemEstrucCentradoTest, cuadradoBordeando) {
    /* Lo unico que importa de A para esta funcion es su dimension */
    imagen A = {{0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0}};
    imagen B = {{1, 1, 1},
                {1, 1, 1},
                {1, 1, 1}};
    pixel p = {0, 0};
    sqPixel esperado = {{0, 0}, {0, 1},
                        {1, 0}, {1, 1}};
    EXPECT_EQ(pixelesActivadosDelElemEstrucCentrado(A, B, p), esperado);
}

TEST(pixelesActivadosDelElemEstrucCentradoTest, cruzCentrada) {
    /* Lo unico que importa de A para esta funcion es su dimension */
    imagen A = {{0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0}};
    imagen B = {{0, 1, 0},
                {1, 1, 1},
                {0, 1, 0}};
    pixel p = {2, 3};
    sqPixel esperado = {        {1, 3},
                        {2, 2}, {2, 3}, {2, 4},
                                {3, 3}};
    EXPECT_EQ(pixelesActivadosDelElemEstrucCentrado(A, B, p), esperado);
}

TEST(pixelesActivadosDelElemEstrucCentradoTest, equisCentrada) {
    /* Lo unico que importa de A para esta funcion es su dimension */
    imagen A = {{0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0}};
    imagen B = {{1, 0, 1},
                {1, 1, 1},
                {1, 0, 1}};
    pixel p = {2, 3};
    sqPixel esperado = {{1, 2}        , {1, 4},
                        {2, 2}, {2, 3}, {2, 4},
                        {3, 2}        , {3, 4}};
    EXPECT_EQ(pixelesActivadosDelElemEstrucCentrado(A, B, p), esperado);
}
