#pragma once
#include <sstream>
#include <string>
#include "IConverter.h"
#include "Rectangle.h"
using namespace std;


class RectangleUIConverter : public IConverter {
public:
    string convert(void* shape) {
        Rectangle* rectangle = (Rectangle*)shape;

        stringstream builder;
        builder << rectangle->className() << ": ";
        builder << "Width=" << rectangle->a() << " Height=" << rectangle->b() << " => ";
        builder << "Perimeter=" << rectangle->perimeter() << ", ";
        builder << "Area=" << rectangle->area();
        

        string result = builder.str();
        return result;
    }
};