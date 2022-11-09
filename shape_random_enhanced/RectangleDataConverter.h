#pragma once

class RectangleDataConverter : public IConverter
{
public:
	string convert(void* shape)
	{
		Rectangle* rectangle = (Rectangle*)shape;
		stringstream builder;

		builder << rectangle->className() << ": ";
		builder << "Width=" << rectangle->a() << " Height=" << rectangle->b();

		return builder.str();
	}
};