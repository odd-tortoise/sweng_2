#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {8, 2, 3},
        {4, 5, 8}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {107, 120},
        {161, 178}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}


TEST(MatrixMultiplicationTest, TestMultiplyIdentity) {
    std::vector<std::vector<int>> A = {
        {99, 6, 12},
        {14, 99, 16},
        {17, 18, 11}
    };
    std::vector<std::vector<int>> B = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {99, 6, 12},
        {14, 99, 16},
        {17, 18, 11}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}


TEST(MatrixMultiplicationTest, TestMultipyZeros) {
    std::vector<std::vector<int>> A = {
        {1, 1, 1},
        {5, 5, 5},
        {1, 0, 1}
    };
    std::vector<std::vector<int>> B = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}


TEST(MatrixMultiplicationTest, TestNegativeNumbers) {
    std::vector<std::vector<int>> A = {
        {-1, 2, 3},
        {4, -5, -6}
    };
    std::vector<std::vector<int>> B = {
        {7, -8},
        {-9, 1000000},
        {-11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {-58, 2000044},
        {139, -5000104}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}



TEST(MatrixMultiplicationTest, TestMultiplyTranspose) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> B = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {14, 32, 50},
        {32, 77, 122},
        {50, 122, 194}
    };
        ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}









int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
