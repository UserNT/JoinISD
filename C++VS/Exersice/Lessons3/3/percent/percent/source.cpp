//Подсчет процентной составляющей 1го числа от 2го
#include<iostream>
#include<conio.h>
#include<climits>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	setlocale(LC_ALL, "Russian");

	float first;
	float second;
	float percent;

	cout << "Введите два числа: ";
	cin >> first >> second;

	percent = (first/second)*100;

	cout << "Первое число составляет " << percent << " от второго\n";
	
	getch();
	return 0;
}