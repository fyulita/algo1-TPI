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

TEST(regionesTest, regionesDeUnPixel_EnAdy4_1) {
    imagen A = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    vector<sqPixel> esperado = {{{0, 0}}, {{0, 2}}, {{1, 1}}, {{2, 0}}, {{2, 2}}};
    EXPECT_EQ(regiones(A, 4), esperado);
}

TEST(promedioAreasTest, regionesDeUnPixel_EnAdy4_1) {
    imagen A = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    float esperado = 1;
    EXPECT_NEAR(promedioAreas(A, 4), esperado, abs_err);
}
