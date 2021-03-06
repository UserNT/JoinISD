#pragma once
#include<iostream>
#include<cmath>


typedef unsigned int ui;

class time
{
private:
	ui seconds;
	ui minutes;
	ui hours;
public:
	time();
	time(ui);
	time(ui,ui,ui);

	time operator+(const time&) const;

	friend std::ostream& operator<<(std::ostream& os, const time& t1);

	~time();
};

enum vec { Decart, Polar };

class Vector
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
	void polar_to_dec()
	{
		x = cos(angle) * modul;
		y = sin(angle) * modul;
	}

	vec Mode;
public:
	Vector()
	{
		Mode = Decart;
		x = 0;
		y = 0;
		Dec_to_polar();
	}
	Vector(double a, double b, vec mode = Decart)
	{
		if (mode == Decart)
		{
			Mode = mode;
			x = a;
			y = b;
			Dec_to_polar();
		}
		if (mode == Polar)
		{
			Mode = mode;
			modul = a;
			angle = b;
			polar_to_dec();
		}
	}

	double operator+()const
	{
		return modul;
	}

	Vector operator+(const Vector& v)const
	{
		Vector result;
		result.x = x + v.x;
		result.y = y + v.y;
		result.Dec_to_polar();
		return result;
	}

	Vector operator-()const
	{
		return Vector(-x, -y, Decart);
	}

	Vector operator*(double A) const
	{
		return Vector(x*A, y*A);
	}

	friend Vector operator*(double A, const Vector& v1)
	{
		return v1*A;
	}

	friend std::ostream& operator<<(std::ostream& os, Vector& v1)
	{
		if (v1.Mode == Decart)
			os << "X: " << v1.x << ", Y: " << v1.y;
		else os << "Module: " << v1.modul << ", angle: " << v1.angle*(180 / 3.14159265358979323846);
		return os;
	}

	void ChangeMode(vec mode)
	{
		Mode = mode;
	}
};

