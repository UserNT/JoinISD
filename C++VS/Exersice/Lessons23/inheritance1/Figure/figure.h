#pragma once
#include<fstream>

using namespace std;

struct point
{
	double x;
	double y;
};

class figure
{
private:
	point* points;
	double* sides;
	int Number_of_sides;

	double modul(double v);
	void Length_det();
public:
	figure();
	figure(int n);
	friend std::istream& operator >> (std::istream&, figure& f);
	friend std::ostream& operator << (std::ostream&, figure& f);
	
	double* getSides();

	double perimeter();

	~figure();
};

class square : public figure
{
private:	
	static int Number_sides;	
public:
	square();
	double Area()
	{
		return figure::getSides()[0] * figure::getSides()[1];
	}
	~square();
};

class circle : public figure
{
private:
	int Side;
public:
	circle(): figure(2)
	{
		
	}
	double getSide()
	{
		return getSides()[0];
	}
	~circle()
	{
	
	}
};


