#include "Matrix2x2.h"

Matrix2x2::Matrix2x2(){
    vector1 = Vector2D();
    vector2 = Vector2D();
}

Matrix2x2::Matrix2x2(Vector2D _vector1, Vector2D _vector2){
    vector1 = _vector1;
    vector2 = _vector2;
}

Matrix2x2::Matrix2x2(double _x1, double _y1, double _x2, double _y2){
    vector1 = Vector2D(_x1, _y1);
    vector2 = Vector2D(_x2, _y2);
}

bool operator== (const Matrix2x2 &matrix1, const Matrix2x2 &matrix2){
    if (matrix1.vector1 == matrix2.vector1 && matrix1.vector2 == matrix2.vector2){
        return true;
    }else{
        return false;
    }   
}

const Vector2D &Matrix2x2::operator[] (int index)const{
    if (index == 0){
        return vector1;
    }else if (index == 1){
        return vector2;
    }else{
        throw std::invalid_argument("Index out of range (Matrix)");
    }   
}

Vector2D Matrix2x2::operator* (const Vector2D &v1){
    return Vector2D((vector1 * v1), (vector2 * v1));
}