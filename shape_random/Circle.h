#pragma once
#include <sstream>
using namespace std;

#include "IShape.h"
#include "IRandomGenerator.h"
#include "IntegerGenerator.h"

class Circle : public IShape, public IRandomGenerator {
private:
    double _r;
public:
    inline static const double PI = 3.14;
public:
    Circle();
    Circle(double r);
    double perimeter();
    double area();
    void* randomGenerate();
    string toString();
};