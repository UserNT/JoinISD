#include<iostream>
#include<conio.h>
#include<cmath>


using namespace std;

const int N = 40;

struct Cars
{
	int year_of_issue;
	char manufacturer[N];
	int emblem;
};

void InputCar(Cars& c)
{
	cout << "Год выпуска: ";
	cin >> c.year_of_issue;
	cin.get();
	cout << "Страна производителя: ";
	cin.getline(c.manufacturer, N);
	cout << "Символ эмблемы в аски: ";
	cin >> c.emblem;
}

void Output(const Cars& c)
{
	//int ch = c.emblem;
	cout << "Год выпуска: " << c.year_of_issue << endl;
	cout << "Производитель: " << c.manufacturer << endl;
	cout << "Эмблема: " << char(c.emblem) << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int S = 1;

	Cars arr[S];

	cout << "Введите данные про машины которые находятся у Вас в автопарке: \n";
	for (int i(0); i < S; i++)
	{
		cout << "\t\t\t\t******* №-" << i+1 << "*******\n";
		InputCar(arr[i]);
	}

	cout << "У Вас в наличии: \n";

	for (int i(0); i < S; i++)
	{
		cout << "\t\t\t\t******* №-" << i+1 << "*******\n";
		Output(arr[i]);
	}

	_getch();
	return 0;
}