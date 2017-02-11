#include<conio.h>
#include<iostream>
#include<climits>

using std::cout;
using std::endl;
using std::cin;
using std::ios_base;

int main()
{
	setlocale(LC_ALL,"Russian");
	
	int		a = 12;		//4 bytes;
	char	c = 100;	//1 bytes;
	double	d = 10.0/3;	//8 bytes;
	float	e = 10.0/3;	//4 bytes;

	d = 123e4;//123*10^-1 = 12.3
	//cout.precision(20);
	cout.setf(ios_base::fixed , ios_base::floatfield);
	cout << d << endl;



	//a = static_cast<int>(c);

	cout << "a = " << a << " c = \'" << c << "\'\n";
	/*
	short		b;//2 bytes;
	long		c;//4 bytes;
	long long	d;//8 bytes;
	*/
	/*
	a = 23;
	c = 12;

	cout << "a = " << a << "b = " << b << endl;
	cout << "a + b = " << (a+b) << endl;
	cout << "a - b = " << (a-b) << endl;
	cout << "a * b = " << (a*b) << endl;
	cout << "a / b = " << (a/b) << endl;
	cout << "a % b = " << (a%b) << endl;//a%b = a - b*(a/b)
	*/
	getch();
	return 0;
}