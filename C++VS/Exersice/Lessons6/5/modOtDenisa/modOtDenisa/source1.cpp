#include<iostream>
#include<conio.h>

using namespace std;
//нахождение мода среди чисел массива
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 7;
	int A[size];
	int moda[size];
	int n = 0;
	

	cout << "Введите элементы массива \n";
	for(int i = 0; i < size; i++)
	{
		cout << i << "й :";
		while(!(cin >> A[i]))
		{
			cin.clear();
			while(cin.get() != '\n');
		
			cout << "Введите значение для " << i << " элемента: ";
		}
	}
	
	for(int i(0); i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(A[j] == A[i])
			{
				n++;
				moda[i] = n;
			}
		}
		n = 0;
	}

	cout << endl;
	
	int Max = moda[0];
	for(int i(0); i < size; i++)
	{
		cout << "Moda[" << i << "] = " << moda[i] << endl;
		if (moda[i] > Max)
		{
			Max = moda[i];
			n = i;
		}
	}

	cout << "Мода: " << A[n] << endl;

	_getch();
	return 0;
}