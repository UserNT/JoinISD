#include<iostream>
#include<conio.h>

using namespace std;

//сортирует данные в массиве по возростанию пузырьковым алгоритмом
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 7;
	float evaluation[size];
	bool status[size];
	
	cout << "¬ведите оценку студента (1-5)\n";
	for(int i = 0; i < size; i++)
	{
		cout << i << "й :";
		if(!(cin >> evaluation[i]))
		{
			cout << "¬ведено неправильное значение!\n";
			_getch();
			return -1;
		}
		status[i] = false;
	}

	for(int i = 0; i < size; i++)
		if(evaluation[i] < 2.5)
			status[i] = true;
	
	cout << "ќтчисленны студенты: \n";

	for(int i = 0; i < size; i++)
		if(status[i])
			cout << "є" << i << " с средним баллом = " << evaluation[i] << endl;

	_getch();
	return 0;
}