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

	cout << "������� �������� ������� \n";
	for(int i = 0; i < size; i++)
	{
		cout << i << "� :";
		if(!(cin >> A[i]))
		{
			cout << "������� ������������ ��������!\n";
			getch();
			return -1;
		}
		summ += A[i];
	}
	average = summ / size;

	cout << "������� �������������� ������� ������ ���� = " << average;


	getch();
	return 0;
}