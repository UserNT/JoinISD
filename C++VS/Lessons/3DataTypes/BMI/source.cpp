#include<iostream>
#include<conio.h>

using std::endl;
using std::cin;
using std::cout;

int main()
{
	setlocale(LC_ALL ,"Russian");

	float weight;
	float height;
	double BMI;

	cout << "\t\t\t\t$$$������� BMI$$$\n\n";
	cout << "������� ���� ��� � ��: ";
	cin >> weight;
	cout << "������� ���� ���� � ������: ";
	cin >> height;

	BMI = weight/(height*height);

	cout << "��� BMI: " << BMI << endl;

	getch();
	return 0;
}