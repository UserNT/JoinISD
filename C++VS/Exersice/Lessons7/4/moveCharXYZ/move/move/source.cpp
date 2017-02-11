#include<iostream>
#include<conio.h>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL,"Russian");	
	const int N = 100;
	char str[N][N] = {{""},{""}};
	char temp[N] = "";
	int index = 0;
	int indexY = 0;
	bool s = false;
	bool w = false;
	char c = '|', c1;

	do
	{
		
		c1 =(char)_getch();
		system("cls");
		if (c1 == 'd' || c1 == 'D')
		{
			if(s)
			{
				indexY--;
				s = false;
			}
			
			if(w)
			{			
				indexY++;
				w = false;
			}
			for(int i(0); i <= index; i++)
				if(i != index)
					str[indexY][i] = ' ';
				else str[indexY][i] = c;
			str[indexY][index + 1] = '\0';
			index++;	
			strcpy(temp,str[indexY]);
		}
		
		if (c1 == 'a' || c1 == 'A')
		{
			if(s)
				indexY--;
			if(w)
				indexY++;
			s = w = false;
			for(int i(0); i < index; i++)
				if(i != index-1)
					str[indexY][i] = ' ';
				else str[indexY][i] = c;
			str[indexY][index] = '\0';
			index--;
			strcpy(temp,str[indexY]);
		}		


		

		if (c1 == 's' || c1 == 'S')
		{
			
			for(int i(0); i <= indexY; i++)
				if(i != indexY)
				{
					strcpy(str[i],"");
					strcpy(str[i],"\n");
				}
				else strcpy(str[i],temp);
			strcpy(temp,str[indexY]);			
			indexY++;
			s = true;
		}

		if (c1 == 'w' || c1 == 'W')
		{
			
			for(int i(0); i < indexY; i++)
				if(i != indexY-1)
				{
					strcpy(str[i],"");
					strcpy(str[i],"\n");
				}
				else strcpy(str[i],temp);
			strcpy(temp,str[indexY]);
			strcpy(str[indexY],"");
			indexY--;
			w = true;
		}
		
		/*if (c1 == 'a' || c1 == 'A')
		{
			for(int i(0); i < index; i++)
				if(i != index-1)
					str[indexY][i] = ' ';
				else str[indexY][i] = c;
			str[indexY][index] = '\0';
			index--;
		}*/		
		

		for(int i(0); i <= indexY; i++)
			cout << str[i]; 
	}while(c1 != 'q');


	
	_getch();
	return 0;
}