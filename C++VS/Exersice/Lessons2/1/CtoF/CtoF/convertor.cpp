#include<conio.h>
#include<iostream>

using std::endl;
using std::cin;
using std::cout;

int main()
{
	setlocale(LC_ALL,"Russian");

	double TC;
	double TF;

	cout << "\t***Конвертор из грдусов по Фарингейту в градусы Цельсия***\n\n";	
	cout << "Введите температуру в градусах Цельсия: ";
	cin >> TC;
	TF = TC*1.8 + 32;
	cout << "Темперетура по фарингейту = " << TF << endl;
	getch();
	return 0;
}