#include "gtest/gtest.h"
#include "../auxiliares.h"

double abs_err = 0.00001;

TEST(imagenApagadaTest, regionesDeUnPixel_EnAdy4_1) {
    imagen A = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    EXPECT_FALSE(imagenApagada(A));
}

TEST(imagenApagadaTest, regionesDeUnPixel_EnAdy4_2) {
    imagen A = {{0, 0, 0}, {0, 1, 0}, {1, 0, 1}};
    EXPECT_FALSE(imagenApagada(A));
}

TEST(imagenApagadaTest, regionesDeUnPixel_EnAdy4_3) {
    imagen A = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    EXPECT_FALSE(imagenApagada(A));
}

TEST(imagenApagadaTest, MatrizActivaEnAdy4_3) {
    imagen A = {{1}, {1}, {1}};
    EXPECT_FALSE(imagenApagada(A));
}

TEST(hacerRegionTest, regionesDeUnPixel_EnAdy4_1) {
    imagen A = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    pixel p = {0, 0};
    sqPixel esperado = {{0, 0}};
    EXPECT_EQ(hacerRegion(A, p, 4), esperado);
}

TEST(hacerRegionTest, regionEnteraEnAdy4_3) {
    imagen A = {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}};
    pixel p = {0, 0};
    sqPixel esperado = {{0, 0}, {1, 0}, {2, 0}};
    EXPECT_EQ(hacerRegion(A, p, 4), esperado);
}

TEST(hacerRegionTest, regionEnteraEnAdy8_3) {
    imagen A = {{1, 0, 0}, {0, 1, 0}, {1, 0, 0}};
    pixel p = {0, 0};
    sqPixel esperado = {{0, 0}, {1, 1}, {2, 0}};
    EXPECT_EQ(hacerRegion(A, p, 8), esperado);
}

TEST(regionesTest, regionesDeUnPixel_EnAdy4_1) {
    imagen A = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    vector<sqPixel> esperado = {{{0, 0}}, {{0, 2}}, {{1, 1}}, {{2, 0}}, {{2, 2}}};
    EXPECT_EQ(regiones(A, 4), esperado);
}

TEST(regionesTest, regionEnteraEnAdy8_3) {
    imagen A = {{1, 0, 0}, {0, 1, 0}, {1, 0, 0}};
    vector<sqPixel> esperado = {{{0, 0}, {1, 1}, {2, 0}}};
    EXPECT_EQ(regiones(A, 8), esperado);
}

TEST(regionesTest, promedioDecimalEnAdy4_2) {
    imagen A = {{1, 1, 1}, {1, 0, 0}, {0, 0, 1}};
    vector<sqPixel> esperado = {{{0, 0}, {0, 1}, {0, 2}, {1, 0}}, {{2, 2}}};
    EXPECT_EQ(regiones(A, 4), esperado);
}

TEST(promedioAreasTest, regionesDeUnPixel_EnAdy4_1) {
    imagen A = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    float esperado = 1;
    EXPECT_NEAR(promedioAreas(A, 4), esperado, abs_err);
}

TEST(contenidoSqPixelTest, secuenciaVacia_1) {
    vector<sqPixel> S = {{}};
    sqPixel p = {};
    EXPECT_TRUE(contenidoSqPixel(p, S));
}

TEST(contenidoSqPixelTest, secuenciaVacia_2) {
    vector<sqPixel> S = {{}, {{0, 0}}, {{0, 1}}};
    sqPixel p = {};
    EXPECT_TRUE(contenidoSqPixel(p, S));
}

TEST(contenidoSqPixelTest, secuenciaVacia_3) {
    vector<sqPixel> S = {};
    sqPixel p = {{0, 1}};
    EXPECT_FALSE(contenidoSqPixel(p, S));
}

TEST(contenidoSqPixelTest, dosSecuencias) {
    vector<sqPixel> S = {{{0, 0}, {0, 1}}, {{1, 0}, {15, 23}}};
    sqPixel p = {{0, 0}, {0, 1}};
    EXPECT_TRUE(contenidoSqPixel(p, S));
}
