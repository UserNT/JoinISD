#include<iostream>
#include<conio.h>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ios_base;

int main()
{
	setlocale(LC_ALL,"Russian");

	int n;

	cout << "Введите число строк звездочек: ";
	cin >> n;
	for(int i = 0; i <= n; i++)
	{	
		for(int j = 0; j < i; j++)
			cout <<(char)2;
		cout << endl;
	}
	
	_getch();
	return 0;
}