#include "figure.h"
#include<iostream>
#include<cmath>


figure::figure()
{
	points = NULL;
	sides = NULL;
	Number_of_sides = 0;
}

figure::figure(int n)
{
	Number_of_sides = n;
	points = new point[n];
	sides = new double[n];
}

double figure::modul(double v)
{
	return v < 0 ? v*(-1) : v;
}

void figure::Length_det()
{
	double dx, dy;
	if (Number_of_sides == 2)
	{
		dx = modul(points[1].x - points[0].x);
		dy = modul(points[1].y - points[0].y);
		sides[0] = sqrt(dx*dx + dy*dy);
		return;
	}
	for (int i(0); i < Number_of_sides; i++)
	{
		if (i < (Number_of_sides - 1))
		{
			dx = modul(points[i + 1].x - points[i].x);
			dy = modul(points[i + 1].y - points[i].y);
			sides[i] = sqrt(dx*dx + dy*dy);
		}
		else
		{
			dx = modul(points[0].x - points[i].x);
			dy = modul(points[0].y - points[i].y);
			sides[i] = sqrt(dx*dx + dy*dy);
		}

	}
}

std::istream& operator>> (std::istream& in, figure& f)
{
	if (f.Number_of_sides == 2)
	{
		in >> f.points[0].x >> f.points[0].y;
		in >> f.points[1].x >> f.points[1].y;
		f.Length_det();
		return in;
	}
	for (int i(0); i < f.Number_of_sides;  i++)
		in >> f.points[i].x >> f.points[i].y;
	f.Length_det();
	return in;
}

std::ostream& operator << (std::ostream& os, figure& f)
{
	for (int i(0); i < f.Number_of_sides; i++)
	{
		os << f.points[i].x << ' ' << f.points[i].y << endl;
	}
	return os;
}

double* figure::getSides()
{
	return sides;
}

double figure::perimeter()
{
	double perim = 0;
	for (int i(0); i < Number_of_sides; i++)
		perim += sides[i];
	return perim;
}

figure::~figure()
{
	delete[] points;
	delete[] sides;
}



square::square(): figure(Number_sides)
{
	
}

square::~square(){}

