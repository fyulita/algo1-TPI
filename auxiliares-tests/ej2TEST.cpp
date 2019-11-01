#include "gtest/gtest.h"
#include "../auxiliares.h"

TEST(pixelValidoEncendidoTest, promedioDecimalEnAdy4_2) {
    imagen A = {{1, 1, 1}, {1, 0, 0}, {0, 0, 1}};
    pixel p = {1, 1};
    EXPECT_FALSE(pixelValidoEncendido(p, A));
}

TEST(existeCaminoTest, promedioDecimalEnAdy4_2) {
    imagen A = {{1, 1, 1}, {1, 0, 0}, {0, 0, 1}};
    pixel p = {1, 1};
    pixel q = {0, 0};
    EXPECT_FALSE(existeCamino(A, p, q, 4));
}