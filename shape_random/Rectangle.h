#pragma once
#include "IShape.h"

class Rectangle: public IShape {
private:
    double _a;
    double _b;
public:
    double a() { return _a; }
    double b() { return _b; }
public:
    Rectangle() {};
    Rectangle(int a, int b);
    string toString() ;
    IShape* generate(int, int);
    string className() { return "Rectangle"; }
    float area();
    float perimeter();
};