#include<iostream>
#include<conio.h>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	setlocale(LC_ALL,"Russian");

	int Ruble;

	cout << "������� ���-�� ������: ";
	cin >> Ruble;

	cout << "� ��� " << Ruble << " ";
	if(Ruble < 0)
	{
		cout << "�� ����� ������������� ��������\n";
		getch();
		return -1;
	}
	if((Ruble%100) > 10 && (Ruble%100) < 20)
		cout << "������!\n";
	else if((Ruble%10) > 1 && (Ruble%10) < 5)
		     cout << "�����!\n";
		 else if((Ruble%10) == 1)
				  cout << "�����!\n";
			  else 
				  cout << "������!\n";
	getch();
	return 0;
}