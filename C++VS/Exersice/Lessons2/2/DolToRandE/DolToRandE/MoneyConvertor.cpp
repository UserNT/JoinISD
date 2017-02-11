#include<iostream>
#include<conio.h>

using std::endl;
using std::cout;
using std::cin;

int main()
{
	setlocale(LC_ALL,"Russian");
	
	double USD;
	double RUB;
	double EUR;

	cout << "\t\t\t--- онвертер валют---\n\n";
	cout << "¬ведите доллары: ";
	cin >> USD;

	RUB = 59.7835834*USD;
	EUR = 0.935514954*USD;
	cout << "Ёквивалент в рубл€х: " << RUB << endl;
	cout << "Ёквивалент в евро: " << EUR << endl;
	getch();
	return 0;
}