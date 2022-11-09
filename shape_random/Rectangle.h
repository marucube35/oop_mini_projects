#pragma once
#include <sstream>

#include "IShape.h"
#include "IRandomGenerator.h"
#include "IntegerGenerator.h"

class Rectangle: public IShape, public IRandomGenerator {
private:
    double _a;
    double _b;
public:
    Rectangle();
    Rectangle(double a, double b);
    double perimeter();
    double area();  
    void* randomGenerate();
    string toString();
};