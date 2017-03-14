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
	void AddBalance(ui);
	Account MAX(Account& b);
	void TakeMoney(ui take);
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

void Account::AddBalance(ui balance)
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

Account::~Account()
{
}

void    Account::TakeMoney(ui take)
{
	if (take <= Balance)
		Balance -= take;
}

class ExtraAccount : public Account
{
private:
	const int Over;
	double doubt;
public:
	ExtraAccount():doubt(0), Over(20000), Account()
	{
		
	};

	ExtraAccount(char* id, char* name, ui balance):doubt(0), Over(20000), Account(id, name, balance)
	{

	};

	bool TakeMoneyExtra(ui Sum)
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

	void AddMoney(ui Sum)
	{
		if (doubt == 0)
		{
			Account::AddBalance(Sum);
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

	friend ostream& operator<<(ostream& os, ExtraAccount& EA)
	{
		os << "Баланс: " << EA.getBalance() << endl;
		os << "Долг: " << EA.doubt << endl;
		return os;
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	ExtraAccount ex("2323", "Vitalij", 18000);

	cout << ex;

	ex.TakeMoneyExtra(10000);

	cout << ex;

	ex.TakeMoneyExtra(10000);

	cout << ex;

	ex.AddMoney(2000);

	cout << ex;

	ex.TakeMoneyExtra(1000);

	cout << ex;

	ex.AddMoney(300);
	cout << ex;

	_getch();
	return 0;
}