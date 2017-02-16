#include<iostream>
#include<conio.h>

//Функция для определения относительной и абсолютной погрешности
using namespace std;

void input(char* str, int& number)
{
	cout << "Введите " << str << ": ";	
	while (!(cin >> number))
	{
		
		cout << "Вы ввели символ!\n";
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите " << str << ": ";		

	}
	while (number < int(0))
	{
		cout << "Число должно быть болше нуля!\n";
		cout << "Введите " << str << ": ";
		cin >> number;
	}
	
}

double placement(int n, int k)
{
	double result = 1;
	for (int i = n - k + 1; i <= n; i++)
		result *= i;
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, k;

	input("множество n", n);
	input("подмножество k", k);
	while (k > n)
	{
		cout << "k должно быть меньше n!\n";
		input("подмножество k", k);
	}
	cout << "Размещение из n элементов по k = " << placement(n, k);

	_getch();
	return 0;
}