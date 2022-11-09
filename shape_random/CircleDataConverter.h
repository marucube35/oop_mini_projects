#pragma once
#include <sstream>
#include <string>
#include "IConverter.h"
#include "Circle.h"
using namespace std;

class CircleDataConverter : public IConverter
{
public:
	string convert(void* shape)
	{
		Circle* circle = (Circle*)shape;
		stringstream builder;
		
		builder << circle->className() << ": ";
		builder << "Radius=" << circle->r();
		
		return builder.str();
	}
};