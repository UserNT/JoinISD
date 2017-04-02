#include<iostream>
#include<conio.h>
#include<ctime>

using namespace std;

void showArr(const int* arr, int r, int c)
{
	for (int i = 1; i <= r*c; i++)
	{
		if (arr[i-1] > 9)
			cout << arr[i-1] << ' ';
		else
			cout << "0" << arr[i-1] << ' ';		
		if (i%c == 0)
			cout << endl;
	}
}

void SortNumbers(int rows, int columns, int times)
{
	int Size = rows*columns;
	int* arr = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		arr[i] = i+1;
	}

	showArr(arr, rows, columns);

	cout << endl << endl;
	srand(time(0));
	for (int i = 0; i < times; i++)
		for (int j = 0; j < Size; j++)
			swap(arr[j], arr[rand() % Size]);

	showArr(arr, rows, columns);

	delete[] arr;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	SortNumbers(4, 13, 100);

	_getch();
	return 0;
}