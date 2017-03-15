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
	~figure();
};

