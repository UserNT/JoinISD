#include<iostream>
#include<conio.h>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ios_base;
//���������� ��� �� ��������� �������
int main()
{
	setlocale(LC_ALL,"Russian");
	
	
	int r = 1,a,b,temp;
	cout << "������� ����� a � b ��� ����������� ���: ";
	cin >> a >> b;

	if(a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	while(r != 0)
	{
		//q = a/b;
		r = a%b;
		a = b;
		b = r;
	}

	cout << "��� ��� ����� � � b = " << a;
	
	_getch();
	return 0;
}