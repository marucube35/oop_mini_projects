#pragma once

class TriangleDataConverter : public IConverter
{
public:
	string convert(void* shape)
	{
		Triangle* triangle = (Triangle*)shape;
		stringstream builder;

		builder << triangle->className() << ": ";
		builder << "a=" << triangle->a() << ", b=" << triangle->b() << ", c=" << triangle->c();

		return builder.str();
	}
};