#include "gtest/gtest.h"
#include "Matrix2x2.h"

TEST(TestMatrix, testEmptyConstructor){
    Matrix2x2 m1;
    EXPECT_EQ(m1, Matrix2x2(Vector2D(0,0), Vector2D(0,0)));
}

TEST(TestMatrix, testVectorConstructor){
    Vector2D v1(3,4);
    Vector2D v2(5,6);
    Matrix2x2 m1(v1, v2);
    EXPECT_EQ(m1, Matrix2x2(Vector2D(3,4), Vector2D(5,6)));
}

TEST(TestMatrix, testDoubleConstructor){
    Matrix2x2 m1(3,4,5,6);
    EXPECT_EQ(m1, Matrix2x2(Vector2D(3,4), Vector2D(5,6)));
}

TEST(TestMatrix, testCompare){
    Matrix2x2 m1(Vector2D(3,4), Vector2D(5,6));
    Matrix2x2 m2(Vector2D(3,4), Vector2D(5,6));
    EXPECT_TRUE (m1 == m2);
}

TEST(TestMatrix, testOperatorIndex){
    Matrix2x2 m1(Vector2D(3,4), Vector2D(5,6));

    EXPECT_EQ (m1[0], Vector2D(3,4));

    EXPECT_EQ (m1[1], Vector2D(5,6));

    EXPECT_EQ (m1[0][0], 3);

    EXPECT_EQ (m1[1][1], 6);

    EXPECT_EQ (m1[0][1], 4);

    EXPECT_EQ (m1[1][0], 5);

    EXPECT_THROW (Vector2D v3 = m1[2], std::invalid_argument);

}

TEST(TestMatrix, testMultiplication){
    Vector2D v1(2,3);
    Matrix2x2 m1(Vector2D(1,1), Vector2D(2,2));
    EXPECT_EQ (m1*v1, Vector2D(5,10));   

    double sinn, coss;
    double angle = 15;
    sinn = sin(angle*M_PI/180);
    coss = cos(angle*M_PI/180);

    Vector2D v2(2,2);
    Matrix2x2 m2(Vector2D(coss,-sinn), Vector2D(sinn,coss));
    EXPECT_EQ (m2*v2, Vector2D(1.41421, 2.44949)); 
}