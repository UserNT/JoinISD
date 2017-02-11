//Подсчет возможных покупок
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

	cout << "\t\t$$$$Покупательская возможность$$$$\n\n";
	cout << "Введите стоимость товара и кол-во рублей которые есть у Вас: ";
	cin >> costOf >> money;
	
	number = money/costOf;
	
	cout << "\nНа свои деньги вы можете купить " << number << " таких товаров\n";
	getch();
	return 0;
}