#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");
	/*
	const int N = 10;
	int A[N];
	
	for(int i = 0; i < N; i++)
	{
		A[i] = i+1;
		cout << " A[" << i << "] = " << A[i] << endl;
	}
	*/
	//cout << sizeof(A) << endl;
	int A[10];

	cout << "Заполнение массива:\n";

	for(int i = 0; i < 10; i++)
	{
		cout << "Введите значение " << i << " элемента массива: ";
		while(!(cin >> A[i]))
		{
			cin.clear();
			while(cin.get() != '\n');
			cout << "Введите значение " << i << " элемента массива: ";

		}

	}
	system("cls");
	cout << "Исходный массив:\n";
	for(int i = 0; i < 10; i++)
		cout << "A[" << i << "] = " << A[i] << endl;
		
	int MAX = A[0];
	int MIN = A[0];

	for(int i = 1; i < 10; i++)
	{	
		if(MAX < A[i])
			MAX = A[i];
		if(MIN > A[i])
			MIN = A[i];
	}
		cout << "MAX: " << MAX << endl;
		cout << "MIN: " << MIN << endl;

	getch();
	return 0;
}