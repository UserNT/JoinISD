#include<iostream>
#include<conio.h>
//������� ��� ����������� ������������� � ���������� �����������
using namespace std;

void input(char* str, double& number)
{
	cout << "������� " << str << ": ";
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

	input("������� ��������", average);
	input("������� ��������", value);

	result = absolute_error(average, value);
	cout << "���������� ����������� = " << result << endl;
	result = relative_error(average, value);
	cout << "������������� ����������� = " << result << " %" << endl;

	_getch();
	return 0;
}
