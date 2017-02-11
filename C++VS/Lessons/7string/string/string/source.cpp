#include<iostream>
#include<conio.h>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL,"Russian");
	/*
	//char str[] = {'H','e','l','l','o'};//79- символов и нулевой байт

	//cout << "str: \"" << str << "\"\n";	
	char str1[80],str2[80];
	//cout << strlen(str) << endl;

	cout << "Enter string1: ";
	cin.getline(str1,80);
	cout << "Enter string2: ";
	cin.getline(str2,80);

	system("cls");
	cout << "str1: \"" << str1 << "\"\n";
	cout << "str2: \"" << str2 << "\"\n\n";

	strcat(str2,str1);

	cout << "str2: \"" << str2 << "\"\n";
	*/
	
	char str[100] = "";
	char c = '1', c1;
	int index = 0;

	do
	{
		c1 =(char)_getch();
		if (c1 == 'd' || c1 == 'D')
		{
			for(int i(0); i <= index; i++)
				if(i != index)
					str[i] = ' ';
				else str[i] = c;
			str[index + 1] = '\0';
			index++;
		}

		cout << str;
	}while(c1 != 'q');
	
	_getch();
	return 0;
}