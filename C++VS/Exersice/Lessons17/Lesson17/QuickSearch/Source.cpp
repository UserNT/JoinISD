#include<iostream>
#include<conio.h>

using namespace std;

long long Size = 40000000;

template<typename T>

void QuickSearch(T* arr, long long l, long long r, long long n)
{
	if (arr[0] > n || n > arr[r-1])
	{
		cout << "Искомый элемент не найден!\n";
		_getch();
		return;
	}
	
	long long i = (l + r) / 2;
		
	long long middle = arr[i];
	if (middle == n)
	{
		cout << "Искомый элемент найден в " << i << "й позиции\n";
		_getch();
		return;
	}
	if (middle > n)
		QuickSearch(arr, l, i, n);
	if (middle < n)
		QuickSearch(arr, i, r, n);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	long long* arr = new long long[Size];

	for (long long i(0); i < Size; i++)
		arr[i] = i;


	QuickSearch(arr, 0, Size-1, 30000001);

	
	delete[] arr;
	_getch();
	return 0;
}