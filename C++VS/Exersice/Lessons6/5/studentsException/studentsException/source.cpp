#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;

//��������� ������ � ������� �� ����������� ����������� ����������
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 3;
	float evaluation[size];
	bool status[size];
	
	cout << "������� ������ �������� (1-5)\n";
	for (int i = 0; i < size; i++)
	{
		cout << i << "� :";
		
		while (!(cin >> evaluation[i]))
		{
			cout << "�� ����� ������!\n";
			cin.clear();
			while (cin.get() != '\n');			
			cout << i << "� :";
			
		}
		while ((evaluation[i] < 0) || (evaluation[i] > 5))
		{
			cout << "������ ������ ���� �� 1 �� 5!\n";
			cout << i << "� :";
			cin >> evaluation[i];
		}			
		status[i] = false;
	}

	for (int i = 0; i < size; i++)
		if (evaluation[i] < 2.5)
			status[i] = true;
	
	cout << "���������� ��������: \n";

	for (int i = 0; i < size; i++)
		if (status[i])
			cout << "�" << i << " � ������� ������ = " << evaluation[i] << endl;

	_getch();
	return 0;
}