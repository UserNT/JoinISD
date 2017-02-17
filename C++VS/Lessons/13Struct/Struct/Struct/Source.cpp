#include<iostream>
#include<conio.h>
#include<cmath>

using namespace std;

struct Cartesian
{
	double x;
	double y;
};

struct Polar
{
	double r;
	double angle;
};

Polar converCARtoPolar(Cartesian &C)
{
	Polar result;
	result.r = sqrt(pow(C.x, 2) + pow(C.y, 2));
	result.angle = atan2(C.x, C.y);
	return result;
}

void showPolar(const Polar &p)
{
	const double AnglP = 180 / 3.14;
	
	cout << "Distance = " << p.r << endl;
	cout << "Angle = " << p.angle * AnglP << " grad" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Cartesian a;
	Polar b;

	a.x = 10;
	a.y = 10;
	
	b = converCARtoPolar(a);

	showPolar(b);

	_getch();
	return 0;
}