#pragma once
#include <sstream>
#include <string>
#include "IConverter.h"
#include "Circle.h"
using namespace std;

class CircleUIConverter : public IConverter {
public:
    string convert(void* shape) {
        Circle* circle = (Circle*)shape;

        stringstream builder;
        builder << circle->className() << ": ";
        builder << "Radius=" << circle->r() << " => ";
        builder << "Perimeter=" << circle->perimeter() << ", ";
        builder << "Area=" << circle->area();

        string result = builder.str();
        return result;
    }
};