#pragma once
#include <sstream>
#include <cmath>

#include "IShape.h"
#include "IRandomGenerator.h"
#include "IntegerGenerator.h"

class Triangle: public IShape, public IRandomGenerator {
private:
    double _a;
    double _b;
    double _c;
public:
    Triangle();
    Triangle(double a, double b, double c);
    string toString();
public:
    double perimeter();
    double area();  
public:
    void* randomGenerate();
};

