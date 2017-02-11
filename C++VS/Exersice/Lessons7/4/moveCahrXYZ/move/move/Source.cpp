#include<iostream>
#include<conio.h>
#include<cstring>
/*
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
*/
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int N = 1000;
	char str[N][N] = { { "" },{ "" } };
	char temp[N] = "";
	int index = 0;
	int indexY = 0;	
	char c = '|', c1;

	do
	{

		c1 = (char)_getch();
		system("cls");
		if (c1 == 'd' || c1 == 'D')
		{		
						
			for (int i(0); (i <= index) && (i < N); i++)
				if (i != index)
					str[indexY][i] = ' ';
				else str[indexY][i] = c;
				str[indexY][index + 1] = '\0';
				index++;
				strcpy_s(temp, str[indexY]);
		}

		if (c1 == 'a' || c1 == 'A')
		{
			
			for (int i(0); (i < index) && (i < N); i++)
				if (i != index - 1)
					str[indexY][i] = ' ';
				else str[indexY][i] = c;
				str[indexY][index] = '\0';
				index--;
				strcpy_s(temp, str[indexY]);
		}

		if (c1 == 's' || c1 == 'S')
		{
			indexY++;
			for (int i(0); (i <= indexY) && (i < N); i++)
				if (i != indexY)
				{
					strcpy_s(str[i], "\n\0");
				}
				else strcpy_s(str[i], temp);
				strcpy_s(temp, str[indexY]);
		}

		if (c1 == 'w' || c1 == 'W')
		{
			indexY--;
			for (int i(0); (i <= indexY) && (i < N); i++)
				if (i != indexY)
				{
					
					strcpy_s(str[i], "\n\0");
				}
				else strcpy_s(str[i], temp);
				strcpy_s(temp, str[indexY]);
				strcpy_s(str[indexY+1], "\0");				
				
		}


		for (int i(0); i <= indexY; i++)
			cout << str[i];

	} while (c1 != 'q');



	_getch();
	return 0;
}