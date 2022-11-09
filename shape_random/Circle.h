#pragma once
#include "IShape.h"

class Circle: public IShape {
private:
    double _r;
public:
    double r() { return _r; }
public:
    Circle() {}
    Circle(double r);
    string toString() ;
    IShape* generate(int, int);
    string className() { return "Circle"; }
	float area();
	float perimeter();
};