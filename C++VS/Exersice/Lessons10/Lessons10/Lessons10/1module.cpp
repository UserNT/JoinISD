#include<iostream>
#include<conio.h>

using namespace std;
//������� ������ �����
void input(int& n)
{
	cout << "������� ����� ��� ����������� ������: ";
	while (!(cin >> n))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� ����� ��� ����������� ������: ";
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

	cout << "������ ����� " << n << " = " << module(n);
	_getch();
	return 0;
}