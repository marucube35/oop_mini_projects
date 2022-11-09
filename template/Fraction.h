#pragma once
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Fraction
{
private:
	int _numerator;
	int _denominator;

public:
	void setNumerator(int numerator) { _numerator = numerator; }
	void setDenominator(int denominator) { _denominator = denominator; }
	int Numerator() { return _numerator; }
	int Denominator() { return _denominator; }

public:
	Fraction();
	Fraction(int num, int den);
	Fraction(const Fraction& other);
	Fraction operator=(const Fraction& other);
	~Fraction() {}

public:
	bool operator<(const Fraction& other);
	bool operator>(const Fraction& other);
	friend ostream& operator<<(ostream& os, const Fraction& other);

};

