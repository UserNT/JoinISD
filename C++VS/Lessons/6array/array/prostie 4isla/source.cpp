#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");
	
	cout << "\t\t***������� �����***\n\n";
	
	const int size = 15;	

	cout << "������� 15 �����: \n";	
	int B[size];
	int k = 0;
	for(int i = 1; i <= size; i++)
	{
		for(int j = 1; j <= i; j++)
			if((i%j == 0) && j != 1 && j!= i)
			{
				break;
			}
	    B[k++] = i;

	}

	cout << "������� ����� �� "<< size << ": \n";
	for(int i = 0; i < size; i++)
		cout << B[i] << endl;

	getch();
	return 0;
}