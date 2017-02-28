#include<iostream>
#include<conio.h>

using namespace std;

//void Rec(int level)
//{
//	if (level == 0)
//		return;
//	cout << "Вызываем рекурсивную функцию с аргументом: " << level << endl;
//	Rec(level - 1);
//	cout << "Поднимаемся вверх по рекурсии со значением " << level << endl;
//}

void Rec(char* str, int l, int r, int level)
{
	if (level == 0)
		return;

	int middle = (l + r) / 2;
	str[middle] = '|';
	Rec(str, l, middle, level - 1);
	Rec(str, middle, r, level - 1);
}

int main()
{

	setlocale(LC_ALL, "Russian");

	/*Rec(6);*/
	char str[66];
	str[65] = '\0';

	int min, max;
	min = 0; max = 64;
	str[min] = str[max] = '|';

	for (int i(1); i < 64; i++)
		str[i] = ' ';
	cout << str << endl;

	for (int i(1); i <= 6; i++)
	{
		Rec(str, min, max, i);
		cout << str << endl;

		for (int i(1); i < 64; i++)
			str[i] = ' ';
	}

	_getch();
	return 0;
}