#include<iostream>
#include<conio.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL,"Russian");	
	
	const int size = 10;
	int A[size];
	int summa=0;

	cout << "������� " << size << " ����� ��� �����: \n";
	for(int i = 0; i < size; i++)
	{	
		cout << i+1 <<"� ������� = "; 
		cin >> A[i];
		summa+=A[i];
	}

		
	cout << "����� = " << summa << endl;
	_getch();
	return 0;
}