#include "Fraction.h"

Fraction::Fraction()
{
	_numerator = 0;
	_denominator = 1;
}

Fraction::Fraction(int num, int den) {

	
	_numerator = num;
	_denominator = den;
	
	if (den == 0)
	{
		_numerator = 0;
		_denominator = 1;
		cout <<  "Denominator can not be zero!\n";
	}
}

Fraction::Fraction(const Fraction& other)
{
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;
}

Fraction Fraction::operator=(const Fraction& other)
{
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;
	return *this;
}

bool Fraction::operator<(const Fraction& other)
{
	int thisNum = this->_numerator * other._denominator;
	int otherNum = this->_denominator * other._numerator;
	return thisNum < otherNum;

}

bool Fraction::operator>(const Fraction& other)
{
	int thisNum = this->_numerator * other._denominator;
	int otherNum = this->_denominator * other._numerator;
	return thisNum > otherNum;
}

ostream& operator<<(ostream& os, const Fraction& fraction)
{
	os << fraction._numerator << "/" << fraction._denominator;
	return os;
}
