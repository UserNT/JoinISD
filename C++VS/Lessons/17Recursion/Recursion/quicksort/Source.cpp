#include<iostream>
#include<conio.h>
#include<time.h>
#include<random>

using namespace std;

template <typename T>
void QuickSort(T arr, int l, int r)
{
	int i, j;
	i = l;
	j = r;
	int middle = arr[(i + j) / 2];

	do
	{
		while (middle > arr[i]) i++;
		while (middle < arr[j]) j--;

		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	
	} while (i < j);

	if (i < r) QuickSort(arr, i, r);
	if (j > l) QuickSort(arr, l, j);

}

template<typename T>

void Bobble(T* arr, int Size)
{
	T temp;
	for (int i(Size - 1); i > 0; i--)
		for (int j(0); j < i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

int main()
{

	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	int n = 100000;
	int* arr = new int[n];

	for (int i(0); i < n; i++)
	{
		arr[i] = rand();
	}
		
	
	double t1 = clock();
	QuickSort(arr, 0, n - 1);
	double t2 = clock() - t1;

	cout << t2 / CLOCKS_PER_SEC << endl;

	double t3 = clock();
	Bobble(arr, n);
	double t4 = clock() - t1;

	cout << t4 / CLOCKS_PER_SEC;

	delete[] arr;
	_getch();
	return 0;
}