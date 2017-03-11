#include "Rational_fractions.h"

int Rational_fractions::NOD(int a, int b)
{
	int r = 1, temp;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	while (r != 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

void Rational_fractions::is_negative()
{
	if ((denominator < 0 && numerator > 0) || (denominator > 0 && numerator < 0))
		negative = true;
	if (denominator < 0 && numerator < 0)
	{
		denominator *= -1;
		numerator *= -1;
		negative = false;
	}
}

Rational_fractions::Rational_fractions()
{
	numerator = 0;
	denominator = 0;
	negative = false;
}

Rational_fractions::Rational_fractions(int a, int b)
{
	numerator = a;
	denominator = b;
	Reduction();
}


void Rational_fractions::operator+()
{
	if (numerator && denominator)
		numerator++;
	Reduction();
}

Rational_fractions Rational_fractions::operator+(Rational_fractions& b)
{
	Rational_fractions result;
	if (denominator == b.denominator)
	{
		result.denominator = denominator;
		result.numerator = numerator + b.numerator;		
	}	
	else
	{
		result.denominator = denominator * b.denominator;
		result.numerator = numerator*b.denominator + b.numerator*denominator;		
	}

	result.is_negative();

	return result;
}

Rational_fractions Rational_fractions::operator-(Rational_fractions& b)
{
	Rational_fractions result;
	if (denominator == b.denominator)
	{
		result.denominator = denominator;
		result.numerator = numerator + b.numerator;
	}
	else
	{
		result.denominator = denominator * b.denominator;
		result.numerator = numerator*b.denominator - b.numerator*denominator;
	}

	result.is_negative();

	return result;
}

void Rational_fractions::Reduction()
{
	int nod = NOD(numerator, denominator);
	numerator /= nod;
	denominator /= nod;
}

std::ostream& operator<<(std::ostream& os, const Rational_fractions& b)
{
	
	int a, c;
	
	if (b.negative)
	{
		a = b.numerator;
		c = b.denominator;

		if (a < 0) a*(-1);
		if (c < 0) c*(-1);

		os << "-";
	}
	os << a << "/" << c << std::endl;
	return os;
}

Rational_fractions::~Rational_fractions()
{
}
