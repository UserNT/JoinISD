#include"Sort.h"

namespace S
{
	//template<typename T>
	void Bobble(double* A, int Size)
	{
		double temp;
		for (int i = Size - 1; i > 0; i--)
			for (int j = 0; j < i; j++)
			{
				if (A[j] > A[j + 1])
				{
					temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}

	}

	//template <typename T>
	void QuickSort(double* arr, int l, int r)
	{
		double temp;
		int i, j;
		i = l;
		j = r;
		int middle = arr[(i + j) / 2];

		do
		{
			while (middle > arr[i])
				i++;
			while (middle < arr[j])
				j--;

			if (i <= j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++;
				j--;
			}

		} while (i < j);

		if (i < r) QuickSort(arr, i, r);
		if (j > l) QuickSort(arr, l, j);

	}

}