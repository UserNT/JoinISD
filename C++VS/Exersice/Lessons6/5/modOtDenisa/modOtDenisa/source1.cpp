#include<iostream>
#include<conio.h>

using namespace std;
//���������� ���� ����� ����� �������
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 7;
	int A[size];
	int moda[size];
	int n = 0;
	

	cout << "������� �������� ������� \n";
	for(int i = 0; i < size; i++)
	{
		cout << i << "� :";
		while(!(cin >> A[i]))
		{
			cin.clear();
			while(cin.get() != '\n');
		
			cout << "������� �������� ��� " << i << " ��������: ";
		}
	}
	
	for(int i(0); i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(A[j] == A[i])
			{
				n++;
				moda[i] = n;
			}
		}
		n = 0;
	}

	cout << endl;
	
	int Max = moda[0];
	for(int i(0); i < size; i++)
	{
		cout << "Moda[" << i << "] = " << moda[i] << endl;
		if (moda[i] > Max)
		{
			Max = moda[i];
			n = i;
		}
	}

	cout << "����: " << A[n] << endl;

	_getch();
	return 0;
}