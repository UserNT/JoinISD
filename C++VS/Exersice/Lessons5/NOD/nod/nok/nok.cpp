#include<iostream>
#include<conio.h>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ios_base;
//Нахождение нод через НОД
int main()
{
	setlocale(LC_ALL,"Russian");
	
	
	int r = 1,a,b,temp;
	cout << "Введите числа a и b для определения НОK: ";
	cin >> a >> b;

	if(a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	temp = a*b;
	while(r != 0)
	{		
		r = a%b;
		a = b;
		b = r;
	}

	cout << "НОK для чисел а и b = " << temp/a;
	
	_getch();
	return 0;
}