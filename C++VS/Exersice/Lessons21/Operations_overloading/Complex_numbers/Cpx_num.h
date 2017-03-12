#pragma once
#include<iostream>
#include<cmath>

enum complex{Decart, Polar};

class Cpx_num
{
private:
	double x;
	double y;
	double angle;
	double modul;
	void Dec_to_polar()
	{
		modul = sqrt(x*x + y*y);
		angle = atan2(x, y);
	}

	void Polar_to_dec()
	{
		x = modul * cos(angle) /** 180 / 3.14159265358979323846*/;
		y = modul * sin(angle) /** 180 / 3.14159265358979323846*/;
	}

	complex Swich;
public:
	Cpx_num();
	Cpx_num(double a, double b, complex svich = Decart);
	double operator+();
	bool is_equal(const Cpx_num& a) const;
	Cpx_num operator+(const Cpx_num& a) const;
	Cpx_num operator-(const Cpx_num& a) const;
	Cpx_num operator*(const Cpx_num& a) const;
	Cpx_num operator/(const Cpx_num& a) const;
	Cpx_num operator=(const Cpx_num& a);	
	friend std::ostream& operator<<(std::ostream& os, const Cpx_num& c);
	~Cpx_num();
};

