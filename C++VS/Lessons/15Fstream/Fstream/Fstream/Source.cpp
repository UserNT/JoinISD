#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstring>

using namespace std;

struct stack
{
	int a;
	stack* next;
};

void push(stack** first, int a)
{
	stack* n = new stack;
	n->a = a;
	n->next = *first;
	*first = n;
}

void OutStack(stack* first)
{
	while (first)
	{
		cout << first->a << " -> ";
		first = first->next;
	}
	cout << "NULL\n";

}

int pop(stack** top)
{
	int temp = (*top)->a;
	stack* t = *top;
	*top = (*top)->next;
	delete t;

	return temp;
}

void Print(ostream &os)
{
	os << "Hello world!";
}

int main()
{
	setlocale(LC_ALL, "Russian");

	ofstream fout("Text.txt");

	Print(cout);
	Print(fout);


	/*
	ifstream fin;
	fin.open("Text.txt");

	if (!fin.is_open())
	{
		cout << "Такого файла не существует!";
		return -1;
	}
	
	stack* first = NULL;
	int a;
	int count = 0;
	while (!fin.eof())
	{
		fin >> a;
		push(&first, a);
		count++;
	}	
	
	for (int i(0); i < count; i++)
	{
		cout << pop(&first) << endl;
	}
	*/

	_getch();
	return 0;
}