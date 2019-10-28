#include "gtest/gtest.h"
#include "../auxiliares.h"

TEST(vaciaTest, ImagenVacia) {
    imagen img = {{}};
    EXPECT_TRUE(vacia(img));
}

TEST(vaciaTest, ImagenNoVacia) {
    imagen img = {{0}};
    EXPECT_FALSE(vacia(img));
}

TEST(esMatrizTest, ImagenCuadrada) {
    imagen img = {{0, 1, 0},
                  {1, 1, 1},
                  {0, 1, 0}};
    EXPECT_TRUE(esMatriz(img));
}

TEST(esMatrizTest, ImagenVertical) {
    imagen img = {{1},
                  {1},
                  {1}};
    EXPECT_TRUE(esMatriz(img));
}

TEST(esMatrizTest, ImagenHorizontal) {
    imagen img = {{1, 2, 3, 4, 5}};
    EXPECT_TRUE(esMatriz(img));
}

TEST(esMatrizTest, Escalera) {
    imagen img = {{0},
                  {1, 2},
                  {3, 4, 5}};
    EXPECT_FALSE(esMatriz(img));
}

TEST(esMatrizTest, Cero) {
    imagen img = {{0}};
    EXPECT_TRUE(esMatriz(img));
}

TEST(esBinariaTest, Cero) {
    imagen img = {{0}};
    EXPECT_TRUE(esBinaria(img));
}

TEST(esBinariaTest, UnoCero) {
    imagen img = {{1, 0},
                  {0, 1}};
    EXPECT_TRUE(esBinaria(img));
}

TEST(esBinariaTest, Dos) {
    imagen img = {{2}};
    EXPECT_FALSE(esBinaria(img));
}
