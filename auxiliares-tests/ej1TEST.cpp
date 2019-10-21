#include "gtest/gtest.h"
#include "../auxiliares.h"

TEST(vacia, ImagenVacia) {
    imagen img = {{}};
    EXPECT_TRUE(vacia(img));
}

TEST(vacia, ImagenNoVacia) {
    imagen img = {{0}};
    EXPECT_FALSE(vacia(img));
}

TEST(esMatriz, ImagenCuadrada) {
    imagen img = {{0, 1, 0},
                  {1, 1, 1},
                  {0, 1, 0}};
    EXPECT_TRUE(esMatriz(img));
}

TEST(esMatriz, ImagenVertical) {
    imagen img = {{1},
                  {1},
                  {1}};
    EXPECT_TRUE(esMatriz(img));
}

TEST(esMatriz, ImagenHorizontal) {
    imagen img = {{1, 2, 3, 4, 5}};
    EXPECT_TRUE(esMatriz(img));
}

TEST(esMatriz, Escalera) {
    imagen img = {{0},
                  {1, 2},
                  {3, 4, 5}};
    EXPECT_FALSE(esMatriz(img));
}

TEST(esMatriz, Cero) {
    imagen img = {{0}};
    EXPECT_TRUE(esMatriz(img));
}

TEST(esBinaria, Cero) {
    imagen img = {{0}};
    EXPECT_TRUE(esBinaria(img));
}
