#include<iostream>
#include<conio.h>

using namespace std;
//сортирует данные в массиве по возростанию пузырьковым алгоритмом
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 7;
	int A[size];
	int temp;

	cout << "Введите элементы массива \n";
	for(int i = 0; i < size; i++)
	{
		cout << i << "й :";
		if(!(cin >> A[i]))
		{
			cout << "Введено неправильное значение!\n";
			getch();
			return -1;
		}
	}
	// сортировка массива по возростанию	
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
	
	cout << "В результате получили массив: \n";
	for(int i = 0; i < size; i++)
		cout << "A[" << i << "] = " << A[i] << endl;

	getch();
	return 0;
}