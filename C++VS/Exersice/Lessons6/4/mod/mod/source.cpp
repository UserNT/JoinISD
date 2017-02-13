#include<iostream>
#include<conio.h>

using namespace std;
//нахождение мода среди чисел массива
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 7;
	int A[size];
	int Mod;
	int temp;
	int count = 1;
	int tcount = 1;
	int tMod = 0;

	cout << "¬ведите элементы массива \n";
	for(int i = 0; i < size; i++)
	{
		cout << i << "й :";
		if(!(cin >> A[i]))
		{
			cout << "¬ведено неправильное значение!\n";
			_getch();
			return -1;
		}
	}
	//сортируем массив по возростанию
	for(int i = size -1; i > 0; i--)
		for(int j = 0; j < i; j++)
		{	
			if(A[j] > A[j + 1])
			{	
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}		
		}	
	

	for(int i = 0; i < size - 1; i++)
	{
		if (A[i] == A[i+1])
		{
			tcount++;
			tMod = A[i];
		}
		else if(count < tcount)
		     {	
				 count = tcount;
				 Mod = tMod;			
		     }						
	}
	if (count == 1)
		cout << "„исла не повтор€ютс€!";
	else
		cout << "ћод = " << Mod << endl;

	_getch();
	return 0;
}