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
	
	int p;
	unsigned long long power = 1;

	cout << "¬ведите степень цифры 2: ";
	cin >> p;
	for(int i = 0; i <= p; i++)
	{
		for(int j = 0; j < i; j++)
			power *= 2;
		
		cout <<	"2^" << i << " = " << power << endl;
		power = 1;
	}	
	
	_getch();
	return 0;
}