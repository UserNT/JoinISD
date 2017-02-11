#include<iostream>
#include<conio.h>

using std::cout;
using std::cin;
using std::endl;
//поиск определенного элемента
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 10;
	int A[size];
	int summa = 0;
	int search;
	bool success = false;

	cout << "Введите " << size << " чисел: \n";
	for (int i = 0; i < size; i++)
	{	
		cout << i+1 << "й элемент = "; 
		cin >> A[i];
	}

	cout << "Введите искомый элемент: ";
	cin >> search;

	for (int i = 0; i < size; i++)
	{	
		if (A[i] == search)
		{
			cout << "Число находится в " << i << "ой ячейке\n";
			success = true;
			/*getch();
			return 0;*/
		}

		if (!success && i == (size - 1)) 
		{
			cout << "В данном массиве нет этого числа!\n";
			getch();
			return -1;
		}
	
	}
	_getch();
	return 0;
}