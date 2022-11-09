#pragma once
#include <string>
using namespace std;

class IShape { // interface ==> contract
public:
    virtual double perimeter() = 0; // pure virtual
    virtual double area() = 0;      // pure virtual
    virtual string toString() = 0;
};