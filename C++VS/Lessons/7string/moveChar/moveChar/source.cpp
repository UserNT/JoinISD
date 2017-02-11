#include<iostream>
#include<conio.h>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL,"Russian");	
	
	char str[100] = "";
	char c = '|', c1;
	int index = 0;

	do
	{
		
		c1 =(char)_getch();
		system("cls");
		if (c1 == 'd' || c1 == 'D')
		{
			for(int i(0); i <= index; i++)
				if(i != index)
					str[i] = ' ';
				else str[i] = c;
			str[index + 1] = '\0';
			index++;
		}

		if (c1 == 'a' || c1 == 'A')
		{
			for(int i(0); i < index; i++)
				if(i != index-1)
					str[i] = ' ';
				else str[i] = c;
			str[index] = '\0';
			index--;
		}
		cout << str;
	}while(c1 != 'q');

	
	
	_getch();
	return 0;
}