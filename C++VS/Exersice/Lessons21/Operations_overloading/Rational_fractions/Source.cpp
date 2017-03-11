#include<iostream>
#include<conio.h>
#include"Rational_fractions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Rational_fractions a(-2, 4);
	Rational_fractions b(3, 7);
	Rational_fractions c;
	
	c = a + b;

	cout << c;

	_getch();
	return 0;
}