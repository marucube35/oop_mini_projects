#include "Rectangle.h"


Rectangle::Rectangle() {
    _a = 0;
    _b = 0;
}

Rectangle::Rectangle(double a, double b) {
    _a = a;
    _b = b;
}
    
double Rectangle::perimeter() {
    double result = (_a + _b ) * 2;  
    return result;
}


double Rectangle::area() {
    double result = _a * _b;
    return result;
} 

void* Rectangle::randomGenerate() {
    IShape* result = new Rectangle(
        IntegerGenerator::instance()->next(1, 100),   
        IntegerGenerator::instance()->next(1, 100)
    );
    return (void*) result;
}

string Rectangle::toString() {
    stringstream builder;
    
    builder << "Rectangle a = " << _a << ", b = " << _b;
    
    string result = builder.str();
    return result;
}