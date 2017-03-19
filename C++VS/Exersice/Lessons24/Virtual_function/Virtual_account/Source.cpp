#include<iostream>
#include<conio.h>

using namespace std;

typedef unsigned int ui;

class Account
{
private:
	char* ID;
	char* Name;
	ui Balance;
	ui Max;
public:
	
	Account(char* id = "#", char* name = "", ui balance = 0);
	void setID(char* id);
	char* getID();
	void setName(char* name);
	char* getName();
	void setBalance(ui balance);
	ui getBalance();
	virtual void AddMoney(ui);
	Account MAX(Account& b);
	virtual bool TakeMoney(ui take);
	virtual void show();
	friend istream& operator >> (istream& in, Account& A)
	{	
		char* I;
		char* N;
		ui Balance;
		cout << "ID: ";
		in >> I;
		cout << "���: ";
		in >> N;
		cout << "������: ";
		in >> Balance;
		A.setID(I);
		A.setName(N);
		A.setBalance(Balance);
		return in;
	}
	~Account();
};


Account::Account(char* id, char* name, ui balance)
{
	ID = id;
	Name = name;
	Balance = balance;
	Max = 99999;
}

void Account::setID(char* id)
{
	ID = id;
}

char* Account::getID()
{
	return ID;
}

void Account::setName(char* name)
{
	Name = name;
}

char* Account::getName()
{
	return Name;
}

ui Account::getBalance()
{
	return Balance;
}

void Account::setBalance(ui balance)
{
	if (balance < Max)
		Balance = balance;
	else Balance = 0;
}

void Account::AddMoney(ui balance)
{
	if ((balance + Balance) < Max)
		Balance += balance;
}


Account Account::MAX(Account& b)
{
	if (b.getBalance() > Balance)
		return b;
	else return *this;

}

void Account::show()
{
	cout << "ID: " << ID << endl;
	cout << "���: " << Name << endl;
	cout << "������:" << Balance << endl;	
	_getch();
}

Account::~Account()
{
}

bool    Account::TakeMoney(ui take)
{
	if (take <= Balance)
	{
		Balance -= take;
		return true;
	}
	else
		return false;
}

class ExtraAccount : public Account
{
private:
	const ui Over;
	double doubt;
public:
	ExtraAccount() :doubt(0), Over(20000), Account()
	{

	};

	ExtraAccount(char* id, char* name, ui balance) :doubt(0), Over(20000), Account(id, name, balance)
	{

	};

	virtual bool TakeMoney(ui Sum)
	{
		if (doubt > 0.0)
		{
			return false;
		}
		if (Sum < /*this->getBalance()*/ Account::getBalance())
		{
			Account::TakeMoney(Sum);
			return true;
		}
		if (Sum - Account::getBalance() <= Over)
		{
			doubt = Sum - Account::getBalance() + (Sum - Account::getBalance()) * 0.15;
			Account::setBalance(0);
			return true;
		}

		return false;
	}

	virtual void AddMoney(ui Sum)
	{
		if (doubt == 0)
		{
			Account::AddMoney(Sum);
			return;
		}
		else
		{
			if (Sum < doubt)
			{
				doubt -= Sum;
				return;
			}
			else
			{
				Account::setBalance(Sum - doubt);
				doubt = 0;
			}
		}
	}

	virtual void show()
	{
		cout << "ID: " << Account::getID() << endl;
		cout << "���: " << Account::getName() << endl;
		cout << "������:" << Account::getBalance() << endl;
		cout << "����: " << doubt << endl;
		_getch();
	}
	
};

void menu()
{
	cout << "\t�������� ���� �� �������� :\n";	
	cout << "1 - �������� ���� ��������;\n";
	cout << "2 - �������� ������ �� ���� ������������� �������;\n";
	cout << "3 - C���� ������ � ����� ������������� �������; \n";
	cout << "4 - ������� ���������� � �������;\n";
	cout << "q - �����;\n";
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	/*Account A("1234", "Vasja", 1000);
	ExtraAccount EA("5678", "Petja", 2000);
	Account* base = new Account[2];
	base = &A;
	base->TakeMoney(2000);
	base->show();
	base->AddMoney(3000);
	base->show();
	base++;
	base = &EA;
	base->TakeMoney(3000);
	base->show();*/
	cout << "\t\t=========================���� ������ �����===========================\n\n";
	
	int Size;
	char choice;
	int count = 0;
	int Number;
	ui Sum;

	cout << "������� ����������� �������� �����: ";
	cin >> Size;
	char name[20];
	char id[20];
	ui Bal;
	int typeAc;

	Account** database = new Account*[Size];
	

	menu();
	cin >> choice;
	while (choice != 'q')
	{
		switch (choice)
		{
		case '1': 
			int typeAc;
			
			for (int i(0); i < Size; i++)
			{
				cout << "�������� ��� ��������(1 - Account; 2 - ExtraAccount): ";
				cin >> typeAc;
				if (typeAc == 1)
				{					
					cout << "������� ID: ";
					cin >> id;					
					cout << "������� ���: ";
					cin >> name;					
					cout << "������� ������: ";
					cin >> Bal;

					 
					database[i] = new Account(id, name, Bal);					
					
					
				}
				else if (typeAc == 2)
				{
					cout << "������� ID: ";
					cin >> id;
					cout << "������� ���: ";
					cin >> name;
					cout << "������� ������: ";
					cin >> Bal;

					database[i] = new ExtraAccount(id, name, Bal);
				}
			}			
			break;

		case '2':
			cout << "������� ����� �������: ";
			cin >> Number;
			cout << "������� �����: ";
			cin >> Sum;			
			database[Number]->AddMoney(Sum);			
			break;

		case '3':
			cout << "������� ����� �������: ";
			cin >> Number;
			cout << "������� �����: ";
			cin >> Sum;			
			database[Number]->TakeMoney(Sum);			
			break;

		case '4':
			cout << "������� ����� �������: ";
			cin >> Number;			
			database[Number]->show();			
			break;
		}
		system("cls");
		menu();
		cin >> choice;
	}
	
	_getch();
	return 0;
}