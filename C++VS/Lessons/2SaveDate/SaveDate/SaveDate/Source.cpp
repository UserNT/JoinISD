/*////////////////////////////////////
Author: Vitalij Kolodka           ////
Name: ’ранение данных в программе //// 
*/////////////////////////////////////

#include<iostream>
#include<conio.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int Size = 1024;
	int Gigabytes;//гигабайт;
	int Megabytes;//мегабайт;
	int Kbytes;//килобайт;
	unsigned long long bytes;//байт;

	cout << "¬ведите кол-во гигабайт: ";
	cin >> Gigabytes;
	
	Megabytes = Gigabytes * Size;
	Kbytes = Megabytes * Size;
	bytes = (long long)Kbytes * Size;

	cout << "Gigabytes =\t" << Gigabytes << endl;
	cout << "Megabytes =\t" << Megabytes << endl;
	cout << "Kbytes =\t" << Kbytes << endl;
	cout << "bytes =\t" << bytes << endl;

	getch();
	return 0;
}