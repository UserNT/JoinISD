#include<iostream>
#include<conio.h>
#include<ctime>

using namespace std;

void PrintRandomNumbers(int Iter);


int main()
{
	setlocale(LC_ALL, "Russian");
	
	int i;

	char select = 'y';

	while (select != 'n')
	{
		cout << "Введите колличество генерируемых чисел(1-6): ";
		cin >> i;
		PrintRandomNumbers(i);
		cout << endl;
		cout << "Продолжить?(y/n): ";
		//cin.get();
		cin >> select;
	}

	_getch();
	return 0;
}

void PrintRandomNumbers(int Iter)
{
	srand( time(0) );

	for (int i = 0; i < Iter; i++)
	{
		cout << (rand() % 6) + 1 << ' ';
	}
}