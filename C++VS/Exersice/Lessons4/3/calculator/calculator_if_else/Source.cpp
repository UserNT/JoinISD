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
	
	cout << "Введите два числа и операцию которую необходимо выполнить : \n";
	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите второе число: ";
	cin >> b;
	cout << "Введите операцию: ";
	cin >> operation;

	if(operation == '+')
		result = a + b;
	else if(operation == '-')	
		     result = a - b;
		 else if(operation == '*')
			      result = a * b;
			  else if(operation == '/')
				       result = a / b;
			        else{
					     cout << "Вы ввели некорректную операцию!\n";
					     getch();
						 return -1;
					    }

		/*
		case '+': result = a+b; break;
		case '-': result = a-b; break;
		case '*': result = a*b; break;
		case '/': result = a/b; break;
		default : cout << "Вы ввели некорректную операцию!"; break;
		*/
	
	cout << endl;
	
	cout << "Результат = " << result << endl;

	getch();
	return 0;
}