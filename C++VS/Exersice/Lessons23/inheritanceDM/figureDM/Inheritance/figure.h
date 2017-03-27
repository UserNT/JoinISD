#pragma once
//#include<valarray>
#include<iostream>

struct Point
{
	double x;
	double y;
};

class figure
{
private:
	Point* Coordinates;
	int n;
public:
	figure()
	{
		Coordinates = NULL;
		n = 0;
	}

	figure(Point* xy, int size)
	{
		Coordinates = new Point[size];
		n = size;
		for (int i(0); i < n; i++)
			Coordinates[i] = xy[i];
	}

	figure(figure& f)// конструктор копирования
	{
		Coordinates = new Point[f.n];
		n = f.n;
		for (int i(0); i < n; i++)
			Coordinates[i] = f.Coordinates[i];
	}

	friend std::ostream& operator << (std::ostream os, figure& f)
	{
		for (int i(0); i < f.n; i++)
		{
			os << f.Coordinates[i].x << " ";
			os << f.Coordinates[i].y;
			os << std::endl;
		}
		return os;
	}

	friend std::istream& operator >> (std::istream& is, figure& f)
	{
		std::cout << "Введите кол-во точек в фигуре: \n";
		is >> f.n;
		f.Coordinates = new Point[f.n];
		for (int i(0); i < f.n; i++)
		{
			std::cout << "" << i + 1 << " point:\n";
			std::cout << "x: ";
			is >> f.Coordinates[i].x;
			std::cout << "y: ";
			is >> f.Coordinates[i].y;
		}
		return is;
	}

	double distance(int i1, int i2)
	{
		double x1, y1, x2, y2;
		x1 = Coordinates[i1].x;
		y1 = Coordinates[i1].y;
		x2 = Coordinates[i2].x;
		y2 = Coordinates[i2].y;

		return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
	}

	Point& operator[](int i)//перегрузка индексации
	{
		return Coordinates[i];
	}
	~figure()
	{
		delete[] Coordinates;
	}
};



class Circle : public figure
{
private:
	double radius;
public:
	Circle(Point& p, double rad) : figure(&p, 1), radius(rad) {}
	Circle(figure& f) : figure(f)
	{
		radius = f.distance(0, 1);
	}
	Circle() : figure(), radius(0){}

	double Area()
	{
		return pow(radius, 2);
	}
	double Radius()
	{
		return radius;
	}
};

class Rectangle : public figure
{
private:
	double a;
	double b;
public:
	Rectangle(figure& f) : figure(f)
	{
		a = f.distance(0, 1);
		b = f.distance(1, 2);
	}
	Rectangle() : figure(), a(0), b(0){}
	double Area()
	{
		return a*b;
	}
};