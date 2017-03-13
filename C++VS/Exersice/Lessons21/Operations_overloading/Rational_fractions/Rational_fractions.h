#pragma once
#include<iostream>
class Rational_fractions
{
private:
	int numerator;
	int denominator;
	bool negative;
	int NOD(int a, int b);
	/*int LCM(int a, int b) вариант от Дениса
	{
		return a*b / NOD(a, b);
	}*/
	void Reduction();
	void is_negative();
public:
	Rational_fractions();
	Rational_fractions(int a, int b);
	Rational_fractions operator+();
	Rational_fractions operator+(Rational_fractions& b);
	Rational_fractions operator-();
	Rational_fractions operator-(Rational_fractions& b);
	Rational_fractions operator*(Rational_fractions& b);
	Rational_fractions operator/(Rational_fractions& b);
	friend std::ostream& operator<<(std::ostream& os, const Rational_fractions& b);	
	
	~Rational_fractions();
};

