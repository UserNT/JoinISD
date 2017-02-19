#include<iostream>
#include<conio.h>
#include<cmath>


using namespace std;

const int N = 40;

struct Cars
{
	int year_of_issue;
	char manufacturer[N];
	int emblem;
};

void InputCar(Cars& c)
{
	cout << "��� �������: ";
	cin >> c.year_of_issue;
	cin.get();
	cout << "������ �������������: ";
	cin.getline(c.manufacturer, N);
	cout << "������ ������� � ����: ";
	cin >> c.emblem;
}

void Output(const Cars& c)
{
	//int ch = c.emblem;
	cout << "��� �������: " << c.year_of_issue << endl;
	cout << "�������������: " << c.manufacturer << endl;
	cout << "�������: " << char(c.emblem) << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int S = 1;

	Cars arr[S];

	cout << "������� ������ ��� ������ ������� ��������� � ��� � ���������: \n";
	for (int i(0); i < S; i++)
	{
		cout << "\t\t\t\t******* �-" << i+1 << "*******\n";
		InputCar(arr[i]);
	}

	cout << "� ��� � �������: \n";

	for (int i(0); i < S; i++)
	{
		cout << "\t\t\t\t******* �-" << i+1 << "*******\n";
		Output(arr[i]);
	}

	_getch();
	return 0;
}