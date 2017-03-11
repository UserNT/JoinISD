#include<iostream>
#include<conio.h>
#include<cmath>
#include<cctype>

using namespace std;

struct Time
{
	int hours;
	int minutes;
	int seconds;
};

void ShowTime(Time &t)
{
	cout << "Время = " << t.hours << ":" << t.minutes << ":" << t.seconds << endl;
}

void SetTime(Time &t)
{
	cout << "Введите время чч мм сс: ";
	cin >> t.hours >> t.minutes >> t.seconds;

	while (t.hours < 0 || t.minutes < 0 || t.seconds < 0 || t.minutes > 60 || t.seconds > 60)
	{				
		
		if (t.hours < int(0) || t.minutes < int(0) || t.seconds < int(0))
		{
			cout << "Вы ввели отрицательное число!\n";
		}
		if (t.minutes > 59 || t.seconds > 59)
			cout << "Минуты и секунды должны быть меньше 60!\n";
		cout << "Введите время чч мм сс: ";
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

	cout << "Вы ввели: \n\n";
	cout << "a : ";
	ShowTime(a);
	cout << "b : ";
	ShowTime(b);

	c = AddTime(a, b);
	cout << endl;
	cout << "Сумма: ";
	ShowTime(c);

	_getch();
	return 0;
}