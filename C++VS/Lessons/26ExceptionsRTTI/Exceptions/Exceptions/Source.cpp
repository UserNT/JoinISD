#include<iostream>
#include<conio.h>
#include"StackTL.h"
#include<stdexcept>

using namespace std;

struct My
{
	int arr[1000];
};

int main()
{
	setlocale(LC_ALL, "Russian");

	TemplateStack<int> a;
	TemplateStack<char> b;

	/*for (int i(97); i < 123; i++)
	{
		a.push(i);
		b.push((char)i);
	}
	int i = 0;
	try
	{
		while (i < 30)
		{
			cout << a.pop() << " = " << b.pop() << endl;
			i++;
		}
	}
	catch (TemplateStack<int>::bad_Stack a)
	{
		a.what();
	}
	catch (TemplateStack<char>::bad_Stack a)
	{
		a.what();
	}*/
	try 
	{
		My* myarray = new My[200000];
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
	}
	/*catch (const char* message)
	{
		cout << "Error: " << message;
	}
	catch (int i)
	{
		cout << "Error wrong index in Stack Pop: " << i << endl;
	}
	catch (...)
	{
		cout << "Все остальное!";
	}*/
	
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