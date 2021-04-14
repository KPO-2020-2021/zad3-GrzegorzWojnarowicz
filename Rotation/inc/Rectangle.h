#include "Matrix2x2.h"

#ifndef ROTATION_RECTANGLE_H
#define ROTATION_RECTANGLE_H

class Rectangle{
private:
    Vector2D vector1;
    Vector2D vector2;
    Vector2D vector3;
    Vector2D vector4;

public:
    Rectangle();                                                                           //constructor that makes default Rectangle, which vertices are 0,0; 1,0; 1,1; 0,1;
    Rectangle(Vector2D _vector1, Vector2D _vector2, Vector2D _vector3, Vector2D _vector4); //constructor desingned to test Rotate()
    Rectangle(Vector2D vec1, Vector2D vec2);                                               //constructor that checks if its Rectangle 
    Rectangle(double _x1, double _y1, double _x2, double _y2);                             //constructor that checks if its Rectangle
    friend bool operator== (const Rectangle &rectangle1, const Rectangle &rectangle2);     //comparises every vector in Rectangles with precision to THRESHOLD
    Vector2D &operator[] (int index);                                                      //allows to get vector with given index (so you can get x or y of this vector using rectangle[indexOfVector][indexOfDouble])
    friend std::ostream &operator<<(std::ostream &ost, const Rectangle &r1);               //prints data on std::ostream
    friend std::ofstream &operator<<(std::ofstream &ofst, const Rectangle &r1);            //prints data in file
    Rectangle Rotate(Matrix2x2 matrix);
};

#endif // ROTATION_RECTANGLE_H
