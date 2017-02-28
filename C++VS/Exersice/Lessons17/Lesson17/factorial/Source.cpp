#include<iostream>
#include<conio.h>

using namespace std;

long long Factorial(int n)
{
	if (n == 1)
		return 1;
	return n*Factorial(n - 1);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	cout << "Введите число для определения факториала: ";
	cin >> n;

	cout << endl;

	cout << n << "! = " << Factorial(n);

	_getch();
	return 0;
}