#include<iostream>
#include<conio.h>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	setlocale(LC_ALL,"Russian");

	int Ruble;

	cout << "Введите кол-во рублей: ";
	cin >> Ruble;

	cout << "У Вас " << Ruble << " ";
	if(Ruble < 0)
	{
		cout << "Вы введи отрицательное значение\n";
		getch();
		return -1;
	}
	if((Ruble%100) > 10 && (Ruble%100) < 20)
		cout << "Рублей!\n";
	else if((Ruble%10) > 1 && (Ruble%10) < 5)
		     cout << "Рубля!\n";
		 else if((Ruble%10) == 1)
				  cout << "Рубль!\n";
			  else 
				  cout << "Рублей!\n";
	getch();
	return 0;
}