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
		cout << "Вы дрыщь!!!!\n";
	else if(BMI <= 20)
			cout << "Вам нужно поправиться!\n";
		  else if (BMI <= 25)
			       cout << "У вас нормальный вес!\n";
			   else cout << "Отдай еду дрыщу!!!\n";	
	
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

	cout << "Введите кол-во рублей: ";
	cin >> Ruble;

	cout << "У вас " << Ruble << " ";
	
	if(Ruble < 0)
	{
		cout << "Ваше значение отрицательное!";
		getch();
		return -1;
	}
	
	if((Ruble%100) >= 11 && (Ruble%100) <= 19)
		cout << "Рублей!\n";
	else
		switch(Ruble%10)
		{		
			case 1: cout << "Рубль!\n";break;
			case 2:
			case 3:
			case 4: cout << "Рубля!\n";break;

			default: cout << "Рублей!\n";

		}
	sqrt(16);
	getch();
	return 0;
}