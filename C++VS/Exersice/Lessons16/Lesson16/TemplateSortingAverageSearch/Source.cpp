#include<iostream>
#include<conio.h>

using namespace std;

const int Size = 10;

void menu()
{
	cout << "Выберете одно из действий: \n\n";
	cout << "1 - Ввести элементы массива\n";
	cout << "2 - Отсортировать массив по возростанию\n";
	cout << "3 - Найти среднее арифметическое\n";
	cout << "4 - Поиск значения в массиве\n";
	cout << "5 - Вывод массива\n";
	cout << "6 - Выход\n";
}

template<typename T>

void Bobble(T* arr, int Size)
{
	T temp;
	for(int i(Size - 1); i > 0 ; i--)
		for(int j(0); j < i; j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

template<typename T>

int Search(const T* arr, int Size, T sought_for)
{
	
	bool success = false;
	for (int i = 0; i < Size; i++)
	{
		if (arr[i] == sought_for)
			return i;			
		
		if (!success && i == (Size - 1))
			return -1;

	}

}

template<typename T>

T average(const T* arr, int Size)
{
	T Sum = 0;
	for (int i(0); i < Size; i++)
		Sum += arr[i];
	return Sum / ((T)Size);
}

template<typename T>

void EnterArr(T* arr, int Size)
{
	for (int i(0); i < Size; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
}

template<typename T>

void OutputArr(T* arr, int Size)
{
	for (int i(0); i < Size; i++)
		cout << " arr[" << i << "] = " << arr[i];	
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	double arr[Size];
	bool entered = false;
	char ch;	

	do 
	{
		menu();
		cin >> ch;
		switch (ch)
		{
		case '1': EnterArr(arr, Size); entered = true; break;

		case '2': if (entered) Bobble(arr, Size); break;

		case '3': if (entered)
				    {
						cout << "Среднее арифметическое равно = " << average(arr, Size); _getch();
					} 
				  break;

		case '4': if (entered)
					{
						int index;
						double sought_for;
						
						cout << "Введите искомое значение: ";
						cin >> sought_for;						
						index = Search(arr, Size, sought_for);
						if (index != -1)
							cout << "Искомый элемент находится в " << index << " й ячейке.\n";
						else
							cout << "Искомый элемент не найден!/n";
						_getch();
					}
				  break;
		case '5': if (entered)
					{
						cout << "Массив содержит: \n";
						OutputArr(arr, Size);
						_getch();
					}
				  break;

		}
		system("cls");
	} while (ch != '6');
	

	_getch();
	return 0;
}