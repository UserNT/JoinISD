#include<iostream>
#include<conio.h>

using std::cout;
using std::cin;
using std::endl;
//����� ������������� ��������
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 10;
	int A[size];
	int summa = 0;
	int search;
	bool success = false;

	cout << "������� " << size << " �����: \n";
	for (int i = 0; i < size; i++)
	{	
		cout << i+1 << "� ������� = "; 
		cin >> A[i];
	}

	cout << "������� ������� �������: ";
	cin >> search;

	for (int i = 0; i < size; i++)
	{	
		if (A[i] == search)
		{
			cout << "����� ��������� � " << i << "�� ������\n";
			success = true;
			/*getch();
			return 0;*/
		}

		if (!success && i == (size - 1)) 
		{
			cout << "� ������ ������� ��� ����� �����!\n";
			getch();
			return -1;
		}
	
	}
	_getch();
	return 0;
}