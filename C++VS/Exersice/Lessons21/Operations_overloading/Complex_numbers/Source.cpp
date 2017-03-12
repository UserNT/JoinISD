#include<iostream>
#include<conio.h>
#include"Cpx_num.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Cpx_num a(-3, -3.5);
	Cpx_num b(-2.5, -3.4);
	Cpx_num result(1,2, Polar);

	result = a - b;
	cout << "a - b = " << result << endl;
	result = a + b;
	cout << "a + b = " << result << endl;
	result = a * b;
	cout << "a * b = " << result << endl;
	result = a / b;
	cout << "a / b = " << result << endl;

	_getch();
	return 0;
}