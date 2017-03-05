#include "Account.h"

namespace Programm
{		
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
}