#include "Vector2D.h"

#ifndef ROTATION_MATRIX2X2_H
#define ROTATION_MATRIX2X2_H

class Matrix2x2 {
    private:
    Vector2D vector1;
    Vector2D vector2;

    public:
    Matrix2x2();                                                                    //creates matrix((0,0), (0,0))
    Matrix2x2(Vector2D _vector1, Vector2D _vector2);                                //creates matrix(vector1, vector2)
    Matrix2x2(double _x1, double _x2, double _y1, double _y2);                      //creates matrix((x1,y1), (x2,y2))
    friend bool operator== (const Matrix2x2 &matrix1, const Matrix2x2 &matrix2);    //allows to compare two matrixes
    const Vector2D &operator[] (int index)const;                                    //allows to get vector of given index, which allows to get x or y of this vector by using matrix[indexOfVector][indexOfDouble]
    Vector2D operator* (const Vector2D &v1);                                        //allows to multiplicate matrix by vector
};  

#endif // ROTATION_MATRIX2X2_H