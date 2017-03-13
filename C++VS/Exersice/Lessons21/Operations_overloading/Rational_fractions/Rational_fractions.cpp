#include "Rational_fractions.h"

int Rational_fractions::NOD(int a, int b)
{
	int r = 1, temp, a, b;
	a = a > 0 ? a : a*(-1);
	b = b > 0 ? b : b*(-1);
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
	numerator = 1;
	denominator = 1;
	negative = false;
}

Rational_fractions::Rational_fractions(int a, int b)
{
	if (b != 0)
	{
		numerator = a;
		denominator = b;
		negative = false;
		Reduction();
	}
	else
	{
		std::cout << "Знаменатель равен нулю! Заменяю на единичную дробь!";
		Rational_fractions();
	}

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

//Rational_fractions Rational_fractions::operator+(Rational_fractions& b) вариант от Дениса
//{
//	Rational_fractions result;
//	if (denominator == b.denominator)
//	{
//		result.denominator = denominator;
//		result.numerator = numerator + b.numerator;
//	}
//	else
//	{
//		int lcm = LCM(denominator, b.denominator);
//		int x = lcm / denominator;
//		int y = lcm / b.denominator;
//		result.denominator = lcm;
//		result.numerator = numerator * x + b.numerator * y;
//	}
//
//	result.is_negative();
//	if (result.numerator != 0)
//		result.Reduction();
//
//	return result;
//}
 
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

bool Rational_fractions::operator==(Rational_fractions& b)
{
	if (numerator == b.numerator && b.denominator == denominator)
		return true;
	else return false;
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
