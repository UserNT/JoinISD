#include<iostream>
#include<conio.h>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ios_base;


int main()
{
	setlocale(LC_ALL,"Russian");
	/*cout << "Enter a,b: ";
	cin >> a >> b;
	cout << "a = " << a << ", b = " << b << endl;
	cout << "a <= b: " << (a <= b) << endl;
	cout << "a >= b: " << (a >= b) << endl;
	cout << "a == b: " << (a == b) << endl;
	cout << "a != b: " << (a != b) << endl;
	cout << "a < b: " << (a < b) << endl;
	cout << "a > b: " << (a > b) << endl;
	*/
	/*double BMI;	
	cout << "Enter BMI: ";
	cin >> BMI;

	if(BMI <= 15)
		cout << "�� �����!!!!\n";
	else if(BMI <= 20)
			cout << "��� ����� �����������!\n";
		  else if (BMI <= 25)
			       cout << "� ��� ���������� ���!\n";
			   else cout << "����� ��� �����!!!\n";	
	
	*/
	/*
	bool a = false, b = true;
	cout.setf(ios_base::boolalpha);
	cout << "a = " << a << endl;
	cout << "!a = " << (!a) << endl;
	cout << "b = " << b << endl;
	cout << "!b = " << (!b) << endl;

	b = false;

	cout << a << " || " << b << " = " << (a||b) << endl;
	b = true;
	cout << a << " || " << b << " = " << (a||b) << endl;
	a = true; b = false; 
	cout << a << " || " << b << " = " << (a||b) << endl;
	b = true;
	cout << a << " || " << b << " = " << (a||b) << endl;
	
	b = false; a = false;

	cout << a << " && " << b << " = " << (a&&b) << endl;
	b = true;
	cout << a << " && " << b << " = " << (a&&b) << endl;
	a = true; b = false; 
	cout << a << " && " << b << " = " << (a&&b) << endl;
	b = true;
	cout << a << " && " << b << " = " << (a&&b) << endl;
	*/
	int Ruble;

	cout << "������� ���-�� ������: ";
	cin >> Ruble;

	cout << "� ��� " << Ruble << " ";
	
	if(Ruble < 0)
	{
		cout << "���� �������� �������������!";
		getch();
		return -1;
	}
	
	if((Ruble%100) >= 11 && (Ruble%100) <= 19)
		cout << "������!\n";
	else
		switch(Ruble%10)
		{		
			case 1: cout << "�����!\n";break;
			case 2:
			case 3:
			case 4: cout << "�����!\n";break;

			default: cout << "������!\n";

		}
	sqrt(16);
	getch();
	return 0;
}