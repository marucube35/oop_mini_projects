#include "Circle.h"

Circle::Circle() {
    _r = 0;
}

Circle::Circle(double r) {
    _r = r;
}

double Circle::perimeter() {
    double result = PI * (2 * _r);
    return result;
}

double Circle::area() {
    double result = PI * _r * _r;
    return result;
}

void* Circle::randomGenerate() {
    IShape* result = new Circle(
        IntegerGenerator::instance()->next(1, 100)
    );
    
    return (void*) result;
}


string Circle::toString() {
    stringstream builder;
    
    builder << "Circle r = " << _r;
    
    string result = builder.str();
    return result;
}