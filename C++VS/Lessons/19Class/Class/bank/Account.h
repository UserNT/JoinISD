#pragma once

namespace Programm
{
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
		~Account();
	};

}