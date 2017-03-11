#include "Rational_fractions.h"

int Rational_fractions::NOD(int a1, int b1)
{
	int r = 1, temp, a, b;
	a = a1 > 0 ? a1 : a1*(-1);
	b = b1 > 0 ? b1 : b1*(-1);
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

void Rational_fractions::Reduction()
{
	int nod = NOD(numerator, denominator);
	numerator /= nod;
	denominator /= nod;
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
	negative = false;
	Reduction();
}


Rational_fractions Rational_fractions::operator+()
{
	if (numerator && denominator)
		numerator++;
	Reduction();
	return *this;
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
	if(result.numerator != 0)
		result.Reduction();

	return result;
}
 
Rational_fractions Rational_fractions::operator-()
{
	if (numerator && denominator)
		numerator--;
	if(numerator != 0)
		Reduction();
	return *this;
}


Rational_fractions Rational_fractions::operator-(Rational_fractions& b)
{
	Rational_fractions result;
	if (denominator == b.denominator)
	{
		result.denominator = denominator;
		result.numerator = numerator - b.numerator;
	}
	else
	{
		result.denominator = denominator * b.denominator;
		result.numerator = numerator*b.denominator - b.numerator*denominator;
	}

	result.is_negative();
	if (result.numerator != 0)
		result.Reduction();

	return result;
}

Rational_fractions Rational_fractions::operator*(Rational_fractions& b)
{
	Rational_fractions result;
	result.numerator = numerator * b.numerator;
	result.denominator = denominator * b.denominator;

	result.is_negative();

	if (result.numerator != 0)
		result.Reduction();

	return result;
}

Rational_fractions Rational_fractions::operator/(Rational_fractions& b)
{
	Rational_fractions result;
	result.numerator = b.denominator;
	result.denominator = b.numerator;

	return (*this)*result;
}


std::ostream& operator<<(std::ostream& os, const Rational_fractions& b)
{
	
	int a, c;
	a = b.numerator;
	c = b.denominator;
	
	if (b.negative)
	{	
		if (a < 0) a*=(-1);
		if (c < 0) c*=(-1);

		os << "-";
	}
	if (a != 0)
		if (a == 1 && c == 1)
			os << 1;
		else
			os << a << "/" << c;
	else
		os << 0;
	return os;
}

Rational_fractions::~Rational_fractions()
{
}
