//Конвертер секунд в часы минуты и секунды
#include<climits>
#include<iostream>
#include<conio.h>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	setlocale(LC_ALL,"Russian");
	int minutes;
	int hours;
	int seconds;

	cout << "\'(((((((Калькулятор времени)))))))\'\n\n";
	cout << "Введите время в с: ";
	cin >> seconds;

	minutes	= seconds/60;
	hours	= minutes/60;

	cout << seconds << "c == " << hours << "ч - " << minutes%60 << "мин - " << seconds%60 << "c.\n";
	
	getch();
	return 0;
}