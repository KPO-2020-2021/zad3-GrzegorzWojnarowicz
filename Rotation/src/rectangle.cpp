#include "Rectangle.h"

Rectangle::Rectangle(){
    vector1 = Vector2D(0,0);
    vector2 = Vector2D(1,0);
    vector3 = Vector2D(1,1);
    vector4 = Vector2D(0,1);
}

Rectangle::Rectangle(Vector2D _vector1, Vector2D _vector2, Vector2D _vector3, Vector2D _vector4){
    vector1 = _vector1;
    vector2 = _vector2;
    vector3 = _vector3;
    vector4 = _vector4;
}

Rectangle::Rectangle(Vector2D vec1, Vector2D vec2){

    if(vec1[0] != vec2[0] && vec1[1] != vec2[1]){
        if(vec1[0] < vec2[0]){
            if(vec1[1] < vec2[1]){
                vector1 = vec1;
                vector2 = Vector2D(vec2[0], vec1[1]);
                vector3 = vec2;
                vector4 = Vector2D(vec1[0], vec2[1]);
            }else{
                vector1 = Vector2D(vec1[0], vec2[1]);
                vector2 = vec2;
                vector3 = Vector2D(vec2[0], vec1[1]);
                vector4 = vec1;
            }
        }else{
            if(vec1[1] < vec2[1]){
                vector1 = Vector2D(vec2[0], vec1[1]);
                vector2 = vec1;
                vector3 = Vector2D(vec1[0], vec2[1]);
                vector4 = vec2;
            }else{
                vector1 = vec2;
                vector2 = Vector2D(vec1[0], vec2[1]);
                vector3 = vec1;
                vector4 = Vector2D(vec2[0], vec1[1]);
            }
        }
    }else
    {
        throw std::invalid_argument("The given vertices are not opposing (Vectors)");
    }
    
}

Rectangle::Rectangle(double _x1, double _y1, double _x2, double _y2){

    if(_x1 != _x2 && _y1 != _y2){
        if(_x1 < _x2){
            if(_y1 < _y2){
                vector1 = Vector2D(_x1, _y1);
                vector2 = Vector2D(_x2, _y1);
                vector3 = Vector2D(_x2, _y2);
                vector4 = Vector2D(_x1, _y2);
            }else{
                vector1 = Vector2D(_x1, _y2);
                vector2 = Vector2D(_x2, _y2);
                vector3 = Vector2D(_x2, _y1);
                vector4 = Vector2D(_x1, _y1);
            }
        }else{
            if(_y1 < _y2){
                vector1 = Vector2D(_x2, _y1);
                vector2 = Vector2D(_x1, _y1);
                vector3 = Vector2D(_x1, _y2);
                vector4 = Vector2D(_x2, _y2);
            }else{
                vector1 = Vector2D(_x2, _y2);
                vector2 = Vector2D(_x1, _y2);
                vector3 = Vector2D(_x1, _y1);
                vector4 = Vector2D(_x2, _y1);
            }
        }
    }else
    {
        throw std::invalid_argument("The given vertices are not opposing (Double)");
    }
}

bool operator== (const Rectangle &rectangle1, const Rectangle &rectangle2){
    if ((rectangle1.vector1 == rectangle2.vector1) && (rectangle1.vector2 == rectangle2.vector2) 
    && (rectangle1.vector3 == rectangle2.vector3) && (rectangle1.vector4 == rectangle2.vector4)){
        return true;
    }else{
        return false;
    }   
}

Vector2D &Rectangle::operator[] (int index){
    if (index == 0){
        return vector1;
    }else if (index == 1){
        return vector2;
    }else if (index == 2){
        return vector3;
    }else if (index == 3){
        return vector4;
    }else{
        throw std::invalid_argument("Index out of range");
    }   
}

std::ostream &operator<<(std::ostream &ost, const Rectangle &r1){
    ost << r1.vector1 << ", " << r1.vector2 << ", " << r1.vector3 << ", " << r1.vector4;
    return ost;
}

std::ofstream &operator<<(std::ofstream &ofst, const Rectangle &r1){
    ofst << r1.vector1 << std::endl;
    ofst << r1.vector2 << std::endl;
    ofst << r1.vector3 << std::endl;
    ofst << r1.vector4 << std::endl;
    ofst << r1.vector1 << std::endl;
    return ofst;
}

Rectangle Rectangle::Rotate(Matrix2x2 matrix){
    this->vector1 = matrix * vector1;
    this->vector2 = matrix * vector2;
    this->vector3 = matrix * vector3;
    this->vector4 = matrix * vector4;

    return *this;
}