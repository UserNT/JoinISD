#include<iostream>
#include<conio.h>

using namespace std;

//��������� ������ � ������� �� ����������� ����������� ����������
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 7;
	float evaluation[size];
	bool status[size];
	
	cout << "������� ������ �������� (1-5)\n";
	for(int i = 0; i < size; i++)
	{
		cout << i << "� :";
		if(!(cin >> evaluation[i]))
		{
			cout << "������� ������������ ��������!\n";
			_getch();
			return -1;
		}
		status[i] = false;
	}

	for(int i = 0; i < size; i++)
		if(evaluation[i] < 2.5)
			status[i] = true;
	
	cout << "���������� ��������: \n";

	for(int i = 0; i < size; i++)
		if(status[i])
			cout << "�" << i << " � ������� ������ = " << evaluation[i] << endl;

	_getch();
	return 0;
}