#include <cmath>
#include <iostream>
#include <fstream>


#ifndef ROTATION_VECTOR2D_H
#define ROTATION_VECTOR2D_H

#define THRESHOLD 0.000001

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D();                                                                     //default constructor (vector [0,0])
    Vector2D(double _x, double _y);                                                 //constructor that creates(vector [x,y])

    friend bool operator== (const Vector2D &v1, const Vector2D &v2);                //compares two vectors with precision to THRESHOLD
    const double &operator[] (int index)const;                                      //allows to get x or y from vector using vector[]
    friend std::ostream &operator<<(std::ostream &ost, const Vector2D &v1);         //allows to print vector on std::ostream 
    friend std::istream &operator>>(std::istream &ist, Vector2D &v1);               //allows to get vector from std::istream 
    double operator* (const Vector2D &v1);                                          //allows to multiplicate two vectors (scalar multiplication)
    Vector2D operator+ (const Vector2D &v1);                                        //allows to add two vectors
    Vector2D operator- (const Vector2D &v1);                                        //allows to subtract two vectors
    friend std::ofstream &operator<<(std::ofstream &ofst, const Vector2D &v1);      //allows to print vector in file
};

#endif // ROTATION_VECTOR2D_H
