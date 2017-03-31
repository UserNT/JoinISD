#include<iostream>
#include<conio.h>

using std::cout;
using std::endl;
using std::cin;
void PrintLineChar(int Length, char ch)
{
	for (int i = 0; i < Length; i++)
	{
		cout << ch << ' ';
	}
}

void PrintSquare(int Size, char ch)
{
	cout << "\t\t\t\t\t";PrintLineChar(Size, ch);
	cout << endl;
	for (int i = 0; i < Size - 2; i++)
	{
		cout << "\t\t\t\t\t";cout << ch;
		for (int i = 0; i < 2*Size - 3; i++)
			cout << ' ';
		cout << ch << endl;
	}
	cout << "\t\t\t\t\t";PrintLineChar(Size, ch);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	cout << "\t\t\t---------------------КВАДРАТ-------------------------\n\n";
	
	int Size;
	char ch;
	
	cout << "Введите символ и длину стороны квадрата: ";
	cin >> ch >> Size;
	
	PrintSquare(Size, ch);
	

	_getch();
	return 0;
}