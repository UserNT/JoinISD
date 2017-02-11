#include<iostream>
#include<conio.h>
#include<cmath>

using namespace std;

void input(char* str, double& degris)
{

	cout << "¬ведите " << str << ": ";
	while (!(cin >> degris))
	{
		cout << "¬веден символ!";
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬ведите " << str << ": ";
	}
	while (degris >= 360 || degris <= 0)
	{
		cout << "¬ведено неправильное число градусов!";
		cout << "¬ведите " << str << ": ";
		cin >> degris;
	}
}

double factorial(int n)
{
	double result = 1;
	for (int i(1); i <= n; i++)
		result *= i;
	return result;
}

double sin_05(double degris)
{
	double result = 0;
	int power;
	double numerator;
	for (int k(0); k < 2; k++)
	{
		power = 1 + 2 * k;
		numerator = pow(-1, k) * pow(degris, power);
		result += numerator / factorial(power);
	}
	return sqrt(result);
}


int main()
{
	setlocale(LC_ALL, "Russian");

	double degris;

	input("число градусов", degris);

	cout << " вадратный корень из sin(" << degris << ") = " << sin_05(degris);

	_getch();
	return 0;
}