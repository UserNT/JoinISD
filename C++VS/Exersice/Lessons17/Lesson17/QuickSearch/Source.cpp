#include<iostream>
#include<conio.h>

using namespace std;

long long Size = 4000000;

template<typename T>

void QuickSearch(T* arr, long long l, long long r, long long n)
{
	if (arr[l] > n || n > arr[r-1])
	{
		cout << "������� ������� �� ������!\n";
		_getch();
		return;
	}
	
	long long i = (l + r) / 2;
		
	long long middle = arr[i];
	if (middle == n)
	{
		cout << "������� ������� ������ � " << i << "� �������\n";
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
		arr[i] = i*2;


	QuickSearch(arr, 0, Size-1, 2000000);

	
	delete[] arr;
	_getch();
	return 0;
}