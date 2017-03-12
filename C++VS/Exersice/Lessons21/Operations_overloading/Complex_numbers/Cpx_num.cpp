#include "Cpx_num.h"
#include<iostream>


Cpx_num::Cpx_num()
{
	Swich = Decart;
	x = 0.0;
	y = 0.0;
	Dec_to_polar();
}

Cpx_num::Cpx_num(double a, double b, complex svich)
{
	if (svich == Decart)
	{
		x = a;
		y = b;
		Swich = Decart;
		Dec_to_polar();
	}
	else
		if (svich == Polar)
		{
			angle = a;
			modul = b;
			Polar_to_dec();
			Swich = Polar;
		}
}

double Cpx_num::operator+()
{
	return modul;
}

bool Cpx_num::is_equal(const Cpx_num& a) const
{
	if (x == a.x && y == a.y)
		return true;
	else return false;
}

Cpx_num Cpx_num::operator+(const Cpx_num& a) const
{
	Cpx_num result;
	result.x = x + a.x;
	result.y = y + a.y;
	result.Dec_to_polar();
	return result;
}

Cpx_num Cpx_num::operator-(const Cpx_num& a) const
{
	Cpx_num result;
	result.x = x - a.x;
	result.y = y - a.y;
	result.Dec_to_polar();
	return result;
}

Cpx_num Cpx_num::operator*(const Cpx_num& a) const
{
	Cpx_num result;
	/*if (x == a.x && y == a.y*(-1))
	{
		result.x = x*x + y*y;		
		return result;
	}	*/	
	result.x = x * a.x - y * a.y;
	result.y = y * a.x + x * a.y;
	result.Dec_to_polar();
	return result;
}

Cpx_num Cpx_num::operator/(const Cpx_num& a) const
{
	Cpx_num result;
	result.x = (x * a.x + y * a.y)/(a.x * a.x + a.y * a.y);
	result.y = (y * a.x - x * a.y)/(a.x * a.x + a.y * a.y);
	result.Dec_to_polar();
	return result;
}

std::ostream& operator<<(std::ostream& os, const Cpx_num& c)
{
	if (c.Swich == Decart)
	{
		if (c.y < 0)
			os << c.x << " - " << c.y*(-1) << "i ";
		else
			os << c.x << " + " << c.y << "i ";
	}
	else if (c.Swich == Polar)
		{
			os << c.modul << "(cos" << c.angle * 180 / 3.14159265358979323846 << " + i sin" << c.angle * 180 / 3.14159265358979323846 << ")";
		}

	return os;
}

Cpx_num Cpx_num::operator=(const Cpx_num& a)
{
	x = a.x;
	y = a.y;
	return *this;
}

Cpx_num::~Cpx_num()
{
}
