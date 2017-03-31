#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Numbers\t\t\tNumbers*Numbers\t\t\tNumbers*Numbers*Numbers\n";
	for (int i = 0; i < 11; i++)
	{
		cout << i << "\t\t\t" << i*i << "\t\t\t\t" << i*i*i << endl;
	}
	
	_getch();
	return 0;
}

