#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int N = 80;
	char str[N];
	char temp;

	cout << "Enter string: ";
	cin.getline(str,N);

	for(int i(0); i < (strlen(str)/2); i++)
	{
		temp = str[i];
		str[i] = str[strlen(str)-(i+1)];
		str[strlen(str)-(i+1)] = temp;
	}
	cout << "Resultat: " << str;

	getch();
	return 0;
}