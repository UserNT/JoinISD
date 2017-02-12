#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;

//сортирует данные в массиве по возростанию пузырьковым алгоритмом
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 3;
	float evaluation[size];
	bool status[size];
	
	cout << "Введите оценку студента (1-5)\n";
	for (int i = 0; i < size; i++)
	{
		cout << i << "й :";
		
		while (!(cin >> evaluation[i]))
		{
			cout << "Вы ввели символ!\n";
			cin.clear();
			while (cin.get() != '\n');			
			cout << i << "й :";
			
		}
		while ((evaluation[i] < 0) || (evaluation[i] > 5))
		{
			cout << "Оценка должна быть от 1 до 5!\n";
			cout << i << "й :";
			cin >> evaluation[i];
		}			
		status[i] = false;
	}

	for (int i = 0; i < size; i++)
		if (evaluation[i] < 2.5)
			status[i] = true;
	
	cout << "Отчисленны студенты: \n";

	for (int i = 0; i < size; i++)
		if (status[i])
			cout << "№" << i << " с средним баллом = " << evaluation[i] << endl;

	_getch();
	return 0;
}