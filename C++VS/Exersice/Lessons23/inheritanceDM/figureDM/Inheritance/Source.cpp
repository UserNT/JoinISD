#include<iostream>
#include<conio.h>
#include<fstream>
#include"figure.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	figure f;

	cin >> f;
	
	Circle c(f);

	cout << c.Radius();

	Rectangle g(f);

	cout << endl << g.Area() << endl;

	_getch();
	return 0;
}