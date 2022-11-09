#include "Triangle.h"

Triangle::Triangle()
{
    _a = 0;
    _b = 0;
    _c = 0;
}

Triangle::Triangle(double a, double b, double c)
{
    _a = a;
    _b = b;
    _c = c;
}

string Triangle::toString()
{
    stringstream builder;

    builder << "Triangle a = " << _a << ", b = " << _b << ", c = " << _c;

    return builder.str();
}

double Triangle::perimeter()
{
    double result = _a + _b + _c;
    return result;
}

double Triangle::area()
{
    double p = perimeter() / 2.0;
    double result = sqrt(p * (p - _a) * (p - _b) * (p - _c));
    return result;
}

void* Triangle::randomGenerate()
{
    IShape* result = new Triangle(
        IntegerGenerator::instance()->next(0, 100),
        IntegerGenerator::instance()->next(0, 100),
        IntegerGenerator::instance()->next(0, 100)
    );

    return (void*) result;
}
