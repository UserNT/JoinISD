//������� ��������� �������
#include<iostream>
#include<conio.h>
#include<climits>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	setlocale(LC_ALL, "Russian");

	int costOf;
	int money;
	int number;

	cout << "\t\t$$$$�������������� �����������$$$$\n\n";
	cout << "������� ��������� ������ � ���-�� ������ ������� ���� � ���: ";
	cin >> costOf >> money;
	
	number = money/costOf;
	
	cout << "\n�� ���� ������ �� ������ ������ " << number << " ����� �������\n";
	getch();
	return 0;
}