/*//////////////////////////
Author: Vitalij Kolodka ////
Name: output console    //// 
*///////////////////////////
#include<conio.h>
#include<iostream>
//using namespace std;
//директива пространства имен объ€вл€ем cout в глобальной области
using std::cout;
using std::endl;

//с данной функции происходит вход в программу
int main()
{
	//оператор вывода в поток
	cout << "Hello World" << endl;	
	cout << "Name: \tVitalij\n";
	cout << "Sur: \tKolodka\n";
	getch();
	//успешное завершение программы
	return 0;
}