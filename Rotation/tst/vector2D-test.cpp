#include "gtest/gtest.h"
#include "Vector2D.h"
#include <iostream>

TEST(TestVector, testEmptyConstructor){
    Vector2D v1;
    EXPECT_EQ(v1, Vector2D(0, 0));
}

TEST(TestVector, testConstructor){
    Vector2D v1(2,4);
    EXPECT_EQ(v1, Vector2D(2, 4));
}

TEST(TestVector, testCompare){
    Vector2D v1(2,4);
    Vector2D v2(2,4);
    EXPECT_TRUE (v1 == v2);
}

TEST(TestVector, testCompareWithThreshold){
    Vector2D v1(2,4);
    Vector2D v2(2.0000001,4.0000009);
    EXPECT_TRUE (v1 == v2);
}

TEST(TestVector, testOperatorIndex){
    Vector2D v1(2,4);
    double x = v1[0];
    EXPECT_EQ (x, 2);

    double y = v1[1];
    EXPECT_EQ (y, 4);

    EXPECT_THROW (double z = v1[2], std::invalid_argument);
}

TEST(TestVector, testPrint){
    Vector2D v1(2,3);
    std::stringstream sts;
    sts << v1;
    EXPECT_EQ ("[2; 3]", sts.str());   
}

TEST(TestVector, testGetVector){
    std::stringstream ist;
    Vector2D v1;
    ist << "[4; 5]"; 
    ist >> v1;
    EXPECT_EQ (v1, Vector2D(4, 5));
    ist = std::stringstream();

    ist << "4; 6]";
    EXPECT_THROW(ist >> v1, std::invalid_argument);
    ist = std::stringstream();

    ist << "[]";
    EXPECT_THROW(ist >> v1, std::invalid_argument);
    ist = std::stringstream();

    ist << "[; 4]";
    EXPECT_THROW(ist >> v1, std::invalid_argument);

    ist = std::stringstream();

    ist << "[4; ]";
    EXPECT_THROW(ist >> v1, std::invalid_argument);
    ist = std::stringstream();

    ist << "[4; 6";
    EXPECT_THROW(ist >> v1, std::invalid_argument);
    
}

TEST(TestVector, testMultiplication){
    Vector2D v1(2,3);
    Vector2D v2(1,1);
    EXPECT_EQ (v1*v2, 5);   
}

TEST(TestVector, testAddVectors){
    Vector2D v1(12,14);
    Vector2D v2(5,8);
    EXPECT_EQ(v1+v2, Vector2D(17,22));
}

TEST(TestVector, testSubtractVectors){
    Vector2D v1(12,14);
    Vector2D v2(5,8);
    EXPECT_EQ(v1-v2, Vector2D(7,6));
}