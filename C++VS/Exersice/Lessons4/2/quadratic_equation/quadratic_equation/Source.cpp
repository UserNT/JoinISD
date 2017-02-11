//Решение полного квадратного уравнения
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

	cout << "Введите старший коэффициент \'а\': ";
	cin >> a;
	cout << "Введите коэффициент при \'b\': ";
	cin >> b;
	cout << "Введите свободный член \'c\': ";
	cin >> c;

	D = pow(b,2)-4*a*c;
	cout << "Дискриминант D = " << D << endl;

	if(D > 0)
	{
		cout << "D > 0 - уравнение имеет два корня: \n";
		x1 = (-b+sqrt(D))/2*a;
		x2 = (-b-sqrt(D))/2*a;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}else if(D == 0)
			{
				cout << "D = 0 - уравнение имеет один корень: \n";
				x1 = x2 = -b/(2*a);
				cout << "x1 = x2 = " << x1 << endl;
			}
		  else
			  cout << "D < 0 - Корней на множестве действительных чисел нет!\n";

	
	getch();
	return 0;
}