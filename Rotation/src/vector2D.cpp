#include "Vector2D.h"

Vector2D::Vector2D(){
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double _x, double _y){
    x = _x;
    y = _y;
}

bool operator==(const Vector2D &v1, const Vector2D &v2){
    if (abs(v1.x - v2.x) <= THRESHOLD && abs(v1.y - v2.y) <= THRESHOLD )
    {
        return true;
    }
    else{
        return false;
    }
}

const double &Vector2D::operator[] (int index)const{
    if (index == 0){
        return x;
    }else if( index == 1){
        return y;
    }else{
        throw std::invalid_argument("Index out of range (Vector)");
    }
}

std::ostream &operator<<(std::ostream &ost, const Vector2D &v1){
    ost << "[" << v1.x << "; " << v1.y << "]";
    return ost;
}

std::istream &operator>>(std::istream &ist, Vector2D &v1){

    char  sep, brackets;

    if(ist.peek() != '['){
        throw std::invalid_argument("unknown argument (missing opening bracket)");
    }
    ist >> brackets;

    if(ist.peek() == ';' || ist.peek() == ']'){
        throw std::invalid_argument("unknown argument (missing first value)");
    }

    ist >> v1.x;
    ist >> sep;
    if(ist.peek() == ']'){
        throw std::invalid_argument("unknown argument (missing second value)");
    }
    ist >> v1.y;
    if(ist.peek() != ']'){
        throw std::invalid_argument("unknown argument (missing closing bracket)");
    }
    ist >> brackets;

    return ist;
}

double Vector2D::operator* (const Vector2D &v1){
    return (v1.x * x + v1.y * y);
}

Vector2D Vector2D::operator* (const double &d1){
    Vector2D v1 = Vector2D(x,y);
    v1.x = d1 * x;
    v1.y = d1 * y;
    return (v1);
}


Vector2D Vector2D::operator+ (const Vector2D &v1){
    return Vector2D((x+v1.x), (y+v1.y));
}

Vector2D Vector2D::operator- (const Vector2D &v1){
    return Vector2D((x-v1.x), (y-v1.y));
}

std::ofstream &operator<<(std::ofstream &ofst, const Vector2D &v1){
    ofst << v1.x << " " << v1.y;
    return ofst;
}
