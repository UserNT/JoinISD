#include<iostream>
#include<conio.h>


using namespace std;
typedef unsigned long long ull;
ull CalcFactorial(int n)
{
	if (n == 0)
		return 1;
	return n * CalcFactorial(n - 1);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int f;

	cout << "¬ведите число дл€ подсчета факториала(n): ";
	
	cin >> f;
	
	cout << "n! = " << CalcFactorial(f);

	_getch();
	return 0;
}

