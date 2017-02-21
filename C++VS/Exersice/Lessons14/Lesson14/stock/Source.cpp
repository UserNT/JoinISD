#include<iostream>
#include<conio.h>

//сток
using namespace std;

struct A
{
	int data;
};

struct list
{
	A a;
	list* next;
};

void AddStack(list** first, A &b)
{
	list* t = new list;
	t->a = b;
	t->next = *first;
	*first = t;
}

void OutStack(list* first)
{
	while (first)
	{
		cout << first->a.data << " -> ";
		first = first->next;
	}
	cout << "NULL\n";

}



int main()
{

	setlocale(LC_ALL, "Russian");

	list* first = NULL;
	A a = { 1 };
	A b = { 2 };
	A c = { 3 };
	A d = { 4 };
	A e = { 5 };

	AddStack(&first, a);
	AddStack(&first, b);
	AddStack(&first, c);
	AddStack(&first, d);
	AddStack(&first, e);
	
	OutStack(first);

	_getch();
	return 0;
}