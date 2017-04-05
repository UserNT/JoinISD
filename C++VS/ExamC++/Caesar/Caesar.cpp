#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include"CaesarDll.h"

using namespace std;

int main()
{

	setlocale(LC_ALL, "Russian");


	char messeg[] = "¿¡¬√ ‡·‚„ ABCD abcd";
	char* temp = encrypt(messeg, 1);
	cout << temp << endl;
	char* temp1 = decrypt(temp, 1);
	cout << temp1;

	delete[] temp, temp1;

	/*cout << int('¿') << endl;
	cout << int('ﬂ') << endl << endl;
	cout << int('‡') << endl;
	cout << int('ˇ') << endl << endl;
	cout << int('¿'-1) << endl;
	cout << int('‡'-1);*/

	_getch();
	return 0;
}