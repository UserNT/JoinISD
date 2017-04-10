#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "D:\Проекты C++ VS\Repos\C++VS\ExamC++\CaesarDll\CaesarDll.h"

using namespace std;

int main()
{

	setlocale(LC_ALL, "Russian");


	char messeg[] = "Hello World";
	char* temp = encrypt(messeg, 50);
	cout << temp << endl;
	char* temp1 = decrypt(temp, 50);
	cout << temp1;

	delete[] temp, temp1;

	//cout << int('А') << endl;
	//cout << int('Я') << endl << endl;
	//cout << int('а') << endl;
	//cout << int('я') << endl << endl;
	///*cout << int('А'-1) << endl;
	//cout << int('а'-1);*/

	_getch();
	return 0;
}