//������� ������� ����������� ���������
#include<iostream>
#include<conio.h>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	setlocale(LC_ALL,"Russian");
	
	float a,b,c,D,x1,x2;

	cout << "������� ������� ����������� \'�\': ";
	cin >> a;
	cout << "������� ����������� ��� \'b\': ";
	cin >> b;
	cout << "������� ��������� ���� \'c\': ";
	cin >> c;

	D = pow(b,2)-4*a*c;
	cout << "������������ D = " << D << endl;

	if(D > 0)
	{
		cout << "D > 0 - ��������� ����� ��� �����: \n";
		x1 = (-b+sqrt(D))/2*a;
		x2 = (-b-sqrt(D))/2*a;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}else if(D == 0)
			{
				cout << "D = 0 - ��������� ����� ���� ������: \n";
				x1 = x2 = -b/(2*a);
				cout << "x1 = x2 = " << x1 << endl;
			}
		  else
			  cout << "D < 0 - ������ �� ��������� �������������� ����� ���!\n";

	
	getch();
	return 0;
}