#include<iostream>
#include<conio.h>
#include<cmath>
#include<cctype>

using namespace std;
const int MaxMinutesOrSeconds = 59;
const int MaxHours = 23;

struct Time
{
	int hours;
	int minutes;
	int seconds;
};

void ShowTime(Time &t)
{
	cout << "����� = " << t.hours << ":" << t.minutes << ":" << t.seconds << endl;
}

void SetTime(Time &t)
{
	cout << "������� ����� �� �� ��: ";
	cin >> t.hours >> t.minutes >> t.seconds;

	while (t.hours < 0 || t.minutes < 0 || t.seconds < 0 ||
		   t.hours > MaxHours || t.minutes > MaxMinutesOrSeconds || t.seconds > MaxMinutesOrSeconds)
	{
		if (t.hours < int(0) || t.minutes < int(0) || t.seconds < int(0))
		{
			cout << "�� ����� ������������� �����!\n";
		}
		
		if (t.minutes > MaxMinutesOrSeconds || t.seconds > MaxMinutesOrSeconds)
			cout << "������ � ������� ������ ���� ������ " << MaxMinutesOrSeconds + 1 << "!\n";

		if (t.hours > MaxHours)
			cout << "���� ������ ���� ������ " << MaxHours + 1 << "!\n";

		cout << "������� ����� �� �� ��: ";
		cin >> t.hours >> t.minutes >> t.seconds;
	}
}


Time AddTime(const Time &a, const Time &b)
{
	Time c;
	unsigned int temp;
	temp = a.seconds + b.seconds;
	c.seconds = temp % 60;
	temp = a.minutes + b.minutes + temp / 60;
	c.minutes = temp % 60;
	c.hours = a.hours + b.hours + temp / 60;
	return c;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Time a;
	Time b;
	Time c;
	
	SetTime(a);
	SetTime(b);

	cout << "�� �����: \n\n";
	cout << "a : ";
	ShowTime(a);
	cout << "b : ";
	ShowTime(b);

	c = AddTime(a, b);
	cout << endl;
	cout << "�����: ";
	ShowTime(c);

	_getch();
	return 0;
}