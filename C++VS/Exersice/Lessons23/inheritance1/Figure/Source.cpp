#include<iostream>
#include<fstream>
#include<conio.h>
#include"figure.h"

using namespace std;
int square::Number_sides = 4;

int main()
{
	setlocale(LC_ALL, "Russian");

	circle c;
	circle a;
	cin >> c;

	ofstream os;
	os.open("Figure.txt");

	os << c;

	os.close();
	
	ifstream in;
	in.open("Figure.txt");

	in >> a;

	in.close();

	cout << endl;
	cout << a << endl;
	cout << "Радиус = " << a.getSide();

	_getch();
	return 0;
}