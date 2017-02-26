#include<iostream>
#include<conio.h>

using namespace std;

template<typename T1, typename T2>

void Swap(T1 &a, T2 &b)
{
	T1 temp = a;
	a = b;
	b = temp;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double a;
	int b;

	cout << "Введите два значения, которые необходимо поменять местами: ";
	cin >> a >> b;
	cout << "a = " << a << " b = " << b << endl << endl;

	Swap(a, b);

	cout << "После замены получили: \n";
	cout << "a = " << a << " b = " << b << endl;

	_getch();
	return 0;
}