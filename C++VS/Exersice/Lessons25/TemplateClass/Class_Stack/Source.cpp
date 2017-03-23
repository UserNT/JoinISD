#include<iostream>
#include<conio.h>
#include"TemplateStack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	TemplateStack<int> a;
	TemplateStack<char> b;

	for (int i(97); i < 123; i++)
	{
		a.push(i);
		b.push((char)i);
	}

	for (int i(97); i < 123; i++)
		cout << b.pop() << " = " << a.pop() << endl;
	/*if (a.Is_Empty())
	{
		cout << "Clacc is empty!" << endl;
	}

	a.push(1.5);
	a.push(2.8);
	if (a.Is_Empty())
	{
		cout << "Clacc is empty!" << endl;
	}
	a.push(3);

	cout << a.pop() << endl;
	cout << a.pop() << endl;
	cout << a.pop() << endl;*/

	_getch();
	return 0;
}