#include<iostream>
#include<conio.h>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	setlocale(LC_ALL,"Russian");

	float a,b,result;
	char operation;

	cout << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << "Калькулятор" << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << endl << endl;
	
	cout << "Введите два числа и операцию которую необходимо выполнить: ";	
	cin >> a >> operation >> b;	
	switch(operation)
	{
		case '+': result = a+b; break;
		case '-': result = a-b; break;
		case '*': result = a*b; break;
		case '/': result = a/b; break;
		default : cout << "Вы ввели некорректную операцию!";
				  getch();
				  return -1;
				  break;
	}
	
	cout << endl;
	
	cout << "Результат = " << result << endl;

	getch();
	return 0;
}