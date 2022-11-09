#pragma once
#include <sstream>
#include <string>
#include "IConverter.h"
#include "Triangle.h"
using namespace std;

class TriangleUIConverter : public IConverter {
public:
    string convert(void* shape) {
        Triangle* triangle = (Triangle*)shape;

        stringstream builder;
        builder << triangle->className() << ": ";
        builder << "a=" << triangle->a() << ", b=" << triangle->b() << ", c=" << triangle->c() << " => ";
        builder << "Perimeter=" << triangle->perimeter() << ", ";
        builder << "Area=" << triangle->area();

        string result = builder.str();
        return result;
    }
};