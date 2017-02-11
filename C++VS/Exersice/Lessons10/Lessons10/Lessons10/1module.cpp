#include<iostream>
#include<conio.h>

using namespace std;
//Подсчет модуля числа
void input(int& n)
{
	cout << "Введите число для определения модуля: ";
	while (!(cin >> n))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите число для определения модуля: ";
	}


}

int module(int n)
{
	if (n < 0)
		return n*(-1);
	else return n;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	input(n);

	cout << "Модуль числа " << n << " = " << module(n);
	_getch();
	return 0;
}