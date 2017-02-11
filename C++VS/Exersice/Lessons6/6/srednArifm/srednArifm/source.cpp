#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 7;
	int A[size];
	float summ = 0;
	float average;

	cout << "¬ведите элементы массива \n";
	for(int i = 0; i < size; i++)
	{
		cout << i << "й :";
		if(!(cin >> A[i]))
		{
			cout << "¬ведено неправильное значение!\n";
			getch();
			return -1;
		}
		summ += A[i];
	}
	average = summ / size;

	cout << "—реднее арифметическое данного набора цифр = " << average;


	getch();
	return 0;
}