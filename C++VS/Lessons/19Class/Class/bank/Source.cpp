#include<iostream>
#include<conio.h>
#include"Account.h"

using namespace std;
using Programm::Account;

int main()
{
	setlocale(LC_ALL, "Russian");

	Account a;
	Account b;

	a.setBalance(2000);
	a.setID("#12343");
	a.setName("Vitalij");

	b.setBalance(1000);
	b.setID("#345");
	b.setName("Vasja");

	a.AddBalance(500);

	cout << "ID: " << a.getID() << endl;
	cout << "Name: " << a.getName() << endl;
	cout << "Balance: " << a.getBalance() << endl;

	cout << "Баланс больше у " << (a.MAX(b)).getName();

	_getch();
	return 0;
}