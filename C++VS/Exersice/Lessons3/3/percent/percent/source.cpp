//������� ���������� ������������ 1�� ����� �� 2��
#include<iostream>
#include<conio.h>
#include<climits>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	setlocale(LC_ALL, "Russian");

	float first;
	float second;
	float percent;

	cout << "������� ��� �����: ";
	cin >> first >> second;

	percent = (first/second)*100;

	cout << "������ ����� ���������� " << percent << " �� �������\n";
	
	getch();
	return 0;
}