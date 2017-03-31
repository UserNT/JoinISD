#include<iostream>
#include<conio.h>

using namespace std;

template<typename T>

void ChangeAB(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int A = 10;
	int B = 20;
	ChangeAB(A, B);
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;

	double X = 5.10;
	double Y = 11.9;
	ChangeAB(X, Y);
	cout << "X = " << X << endl;
	cout << "Y = " << Y << endl;

	_getch();
	return 0;
}