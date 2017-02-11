#include<iostream>
#include<conio.h>
//Функция для определения относительной и абсолютной погрешности
using namespace std;

void input(char* str, double& number)
{
	cout << "Введите " << str << ": ";
	cin >> number;
}

double module(double m)
{
	if (m < 0)
		return m*(-1);
	else return m;
}

double absolute_error(double average, double value)
{
	double result = value - average;
	return module(result);
}

double relative_error(double average, double value)
{
	return (absolute_error(average, value) / average) * 100;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	double average, result, value;

	input("среднее значение", average);
	input("текущее значение", value);

	result = absolute_error(average, value);
	cout << "Абсолютная погрешность = " << result << endl;
	result = relative_error(average, value);
	cout << "Относительная погрешность = " << result << " %" << endl;

	_getch();
	return 0;
}
