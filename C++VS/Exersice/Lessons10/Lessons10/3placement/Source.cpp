#include<iostream>
#include<conio.h>

//������� ��� ����������� ������������� � ���������� �����������
using namespace std;

void input(char* str, int& number)
{
	cout << "������� " << str << ": ";	
	while (!(cin >> number))
	{
		
		cout << "�� ����� ������!\n";
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� " << str << ": ";		

	}
	while (number < int(0))
	{
		cout << "����� ������ ���� ����� ����!\n";
		cout << "������� " << str << ": ";
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

	input("��������� n", n);
	input("������������ k", k);
	while (k > n)
	{
		cout << "k ������ ���� ������ n!\n";
		input("������������ k", k);
	}
	cout << "���������� �� n ��������� �� k = " << placement(n, k);

	_getch();
	return 0;
}