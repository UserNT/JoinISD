#include<iostream>
#include<conio.h>
#include"Rational_fractions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Rational_fractions a(1, 3);
	Rational_fractions b(1, 7);
	
	
	cout << "b++ = " << +b << "; " << "a + b = " << a + b << "; " << "a * b = " << a * b << ";" << endl;
	-b;
	cout << "b-- = " << -b << "; " << "a - b = " << a - b << "; " << "a / b = " << a / b << ";" << endl;

	_getch();
	return 0;
}