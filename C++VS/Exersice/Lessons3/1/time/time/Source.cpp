//��������� ������ � ���� ������ � �������
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

	cout << "\'(((((((����������� �������)))))))\'\n\n";
	cout << "������� ����� � �: ";
	cin >> seconds;

	minutes	= seconds/60;
	hours	= minutes/60;

	cout << seconds << "c == " << hours << "� - " << minutes%60 << "��� - " << seconds%60 << "c.\n";
	
	getch();
	return 0;
}