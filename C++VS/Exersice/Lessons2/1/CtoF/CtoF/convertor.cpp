#include<conio.h>
#include<iostream>

using std::endl;
using std::cin;
using std::cout;

int main()
{
	setlocale(LC_ALL,"Russian");

	double TC;
	double TF;

	cout << "\t***��������� �� ������� �� ���������� � ������� �������***\n\n";	
	cout << "������� ����������� � �������� �������: ";
	cin >> TC;
	TF = TC*1.8 + 32;
	cout << "����������� �� ���������� = " << TF << endl;
	getch();
	return 0;
}