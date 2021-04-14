#include "gtest/gtest.h"
#include "Rectangle.h"

TEST(TestRectangle, testEmptyConstructor){
    Rectangle r1;
    EXPECT_EQ(r1, Rectangle(Vector2D(0,0), Vector2D(1,0), Vector2D(1,1), Vector2D(0,1)));
}

TEST(TestRectangle, testAdvancedVectorConstructor){
    Vector2D v1(3,4);
    Vector2D v2(5,6);
    Vector2D v3(5,4);
    Vector2D v4(3,6);
    Rectangle r1(v1, v2);
    EXPECT_EQ(r1, Rectangle(Vector2D(3,4), Vector2D(5,4), Vector2D(5,6), Vector2D(3,6)));
    Rectangle r6 (v3, v4);
    EXPECT_EQ(r6, Rectangle(Vector2D(3,4), Vector2D(5,4), Vector2D(5,6), Vector2D(3,6)));
    Rectangle r7(v2, v1);
    EXPECT_EQ(r7, Rectangle(Vector2D(3,4), Vector2D(5,4), Vector2D(5,6), Vector2D(3,6)));
    Rectangle r8(v4, v3);
    EXPECT_EQ(r8, Rectangle(Vector2D(3,4), Vector2D(5,4), Vector2D(5,6), Vector2D(3,6)));

    EXPECT_THROW(Rectangle r2(v1, v4), std::invalid_argument);
    EXPECT_THROW(Rectangle r3(v2, v3), std::invalid_argument);
    EXPECT_THROW(Rectangle r4(v1, v3), std::invalid_argument);
    EXPECT_THROW(Rectangle r5(v2, v4), std::invalid_argument);
    
}

TEST(TestRectangle, testAdvancedDoubleConstructor){
    Rectangle r1(3,4,5,6);
    EXPECT_EQ(r1, Rectangle(Vector2D(3,4), Vector2D(5,4), Vector2D(5,6), Vector2D(3,6)));
    Rectangle r6 (5,4,3,6);
    EXPECT_EQ(r6, Rectangle(Vector2D(3,4), Vector2D(5,4), Vector2D(5,6), Vector2D(3,6)));
    Rectangle r7(5,6,3,4);
    EXPECT_EQ(r7, Rectangle(Vector2D(3,4), Vector2D(5,4), Vector2D(5,6), Vector2D(3,6)));
    Rectangle r8(3,6,5,4);
    EXPECT_EQ(r8, Rectangle(Vector2D(3,4), Vector2D(5,4), Vector2D(5,6), Vector2D(3,6)));

    EXPECT_THROW(Rectangle r2(3,4,3,6), std::invalid_argument);
    EXPECT_THROW(Rectangle r3(5,6,5,4), std::invalid_argument);
    EXPECT_THROW(Rectangle r4(3,4,5,4), std::invalid_argument);
    EXPECT_THROW(Rectangle r5(5,6,3,6), std::invalid_argument);
    
}

TEST(TestRectangle, testVectorConstructor){
    Vector2D v1(3,4);
    Vector2D v2(5,6);
    Vector2D v3(3,4);
    Vector2D v4(5,6);
    Rectangle r1(v1, v2, v3, v4);
    EXPECT_EQ(r1, Rectangle(Vector2D(3,4), Vector2D(5,6), Vector2D(3,4), Vector2D(5,6)));
}


TEST(TestRectangle, testCompare){
    Rectangle r1(Vector2D(3,4), Vector2D(5,6), Vector2D(3,4), Vector2D(5,6));
    Rectangle r2(Vector2D(3,4), Vector2D(5,6), Vector2D(3,4), Vector2D(5,6));
    EXPECT_TRUE (r1 == r2);
}


TEST(TestRectangle, testOperatorIndex){
    Rectangle r1(Vector2D(3,4), Vector2D(5,6), Vector2D(7,8), Vector2D(9,0));
    EXPECT_EQ (r1[0], Vector2D(3,4));

    EXPECT_EQ (r1[1], Vector2D(5,6));

    EXPECT_EQ (r1[2], Vector2D(7,8));

    EXPECT_EQ (r1[3], Vector2D(9,0));

    EXPECT_THROW (Vector2D v5 = r1[4], std::invalid_argument);
}

TEST(TestRectangle, testPrint){
    Vector2D v1(3,4);
    Vector2D v2(5,6);
    Rectangle r1(v1, v2);
    std::stringstream sts;
    sts << r1;
    EXPECT_EQ ("[3; 4], [5; 4], [5; 6], [3; 6]", sts.str());   
}

TEST(TestRectangle, testRotate){
    Vector2D v1(0,0);
    Vector2D v2(1,1);
    Vector2D v3(-1,1);
    double sinn, coss;
    double angle = 90;
    sinn = sin(angle*M_PI/180);
    coss = cos(angle*M_PI/180);

    Matrix2x2 m2(Vector2D(coss,-sinn), Vector2D(sinn,coss));
    Rectangle r1(v1, v2);

    EXPECT_EQ (r1.Rotate(m2), Rectangle(Vector2D(0,0), Vector2D(0,1), Vector2D(-1,1), Vector2D(-1,0)));
}