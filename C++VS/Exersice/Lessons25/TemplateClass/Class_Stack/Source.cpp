#include<iostream>
#include<conio.h>
#include"TemplateStack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	TemplateStack<double> a;

	a.push(1.5);
	a.push(2.8);
	a.push(3);

	cout << a.pop() << endl;
	cout << a.pop() << endl;
	cout << a.pop() << endl;

	_getch();
	return 0;
}