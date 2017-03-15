#include<iostream>
#include<conio.h>
#include"figure.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	figure f(3);

	cin >> f;

	cout << f;

	_getch();
	return 0;
}