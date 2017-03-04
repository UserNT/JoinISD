#include<iostream>
#include<conio.h>
#include"Sort.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n = 6;
	double* arr = new double[n];

	cout << "¬ведите " << n << " значений: \n";
	for (int i(0); i < n; i++)
	{
		cout << "arr[" << i + 1 << "] = ";
		cin >> arr[i];
	}

	S::QuickSort(arr, 0, n - 1);

	for (int i(0); i < n; i++)
		cout << "arr[" << i + 1 << "] = " << arr[i] << " ";


	_getch();
	return 0;
}