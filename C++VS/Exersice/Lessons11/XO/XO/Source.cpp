#include<iostream>
#include<conio.h>
#include<random>
#include<time.h>

using namespace std;

char name1[30];
char name2[30];
char table[3][3];
bool step;
int c = 0;

void instruction()
{
	cout << "\t\t*** �������� ������ ***\n\n";
	cout << "�������:\n";
	cout << "������ 2 ������ �� ���� 3�3\n";
	cout << "��������� ��� ��� �������� ���������� ����������\n";
	cout << "��� ����:\n\n";
	int l = 0;

	for (int i(0); i < 3; i++)
	{
		for (int j(0); j < 3; j++)
		{
			cout << "| " << l + 1 << ' ';
			table[i][j] = char(49 + l);
			l++;
		}
		cout << '|';
		cout << endl;
	}

	cout << "\n��� ���� ������� ����� ������ ����\n";
	cout << "��� ������ ���� ������� �������: ";
	_getch();
}

bool input()
{
	for (int i(0); i < 3; i++)
	{
		for (int j(0); j < 3; j++)
		{
			cout << "| " << table[i][j] << ' ';
		}
		cout << '|';
		cout << endl;
	}

	cout << endl;
	if (step)
		cout << "����� " << name1 << " : ";
	else cout << "����� " << name2 << " : ";

	int n;
	cin >> n;

	c++;

	if (n < 1 || n > 9)
		return false;
	int i, j;

	if (n % 3 == 0)
	{
		i = n / 3 - 1;
		j = 2;
	}
	else
	{
		j = n % 3 - 1;
		i = n / 3;
	}
	if (table[i][j] == '0' || table[i][j] == 'x')
		return false;

	if (step)
	{
		table[i][j] = 'x';
		step = false;
	}
	else { table[i][j] = '0'; step = true; }
	return true;
}

bool win()
{
	for (int i(0); i < 3; i++)
		if ((table[i][0] == table[i][1]) && (table[i][0] == table[i][2]))
			return true;
		else if ((table[0][i] == table[1][i]) && (table[0][i] == table[2][i]))
			return true;
		else if ((table[0][0] == table[1][1]) && (table[1][1] == table[2][2]) || (table[0][2] == table[1][1]) && (table[1][1] == table[2][0]))
			return true;
	if (c == 9)
	{
		c++;
		return true;
	}
	return false;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	instruction();
	system("cls");

	cout << "������� ��� 1 ������: ";
	cin.getline(name1, 30);
	cout << "������� ��� 2 ������: ";
	cin.getline(name2, 30);

	srand(time(NULL));
	if (rand() & 1)
		step = true;
	else step = false;

	while (!win())
	{
		system("cls");
		if (!input())
		{
			cout << "�� ����� �������� ������ ���������!";
			_getch();
		}
	}
	system("cls");
	if (step && (c < 10))
		cout << "������� " << name2 << endl;
	else if (!step && (c < 10))
		cout << "������� " << name1 << endl;
	else if (c == 10)
		cout << "�����!\n";
	_getch();
	return 0;
}