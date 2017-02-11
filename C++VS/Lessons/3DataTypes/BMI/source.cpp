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

	cout << "\t\t\t\t$$$Подсчет BMI$$$\n\n";
	cout << "Введите свой вес в кг: ";
	cin >> weight;
	cout << "Введите свой рост в метрах: ";
	cin >> height;

	BMI = weight/(height*height);

	cout << "Ваш BMI: " << BMI << endl;

	getch();
	return 0;
}