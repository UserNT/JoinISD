#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
typedef unsigned int uint;

char* encrypt(const char* message, uint key)
{
	
	char* mes = new char[100];
	strcpy(mes, message);

	int i = 0;	

	while (mes[i] != '\0')
	{
		if (mes[i] != ' ' && mes[i] != '\n')
		{
			if (mes[i] >= 'A' && mes[i] <= 'Z')
			{
			
				if (char(mes[i] + key) <= 'Z')
				{
					mes[i] = char(mes[i] + key);
					i++;
				}
				else
				{
					mes[i] = char('@' + (mes[i] + key - 'Z'));
					i++;
				}
			
			}

			if (mes[i] >= 'a' && mes[i] <= 'z')
			{
			
				if (char(mes[i] + key) <= 'z')
				{
					mes[i] = char(mes[i] + key);
					i++;
				}
				else
				{
					mes[i] = char(char(96) + (mes[i] + key - 'z'));
					i++;
				}
			
			}

			if (mes[i] >= 'Р' && mes[i] <= 'п')
			{
			
				if (char(mes[i] + key) <= 'п')
				{
					mes[i] = char(mes[i] + key);
					i++;
				}
				else
				{
					mes[i] = char('Р' - 1 + (mes[i] + key - 'п'));
					i++;
				}
			
			}

			if (mes[i] >= 'р' && mes[i] <= 'џ')
			{

				if (char(mes[i] + key) <= 'џ')
				{
					mes[i] = char(mes[i] + key);
					i++;
				}
				else
				{
					mes[i] = char('п' + (mes[i] + key - 'џ'));
					i++;
				}
			}		
		}
		else
			i++;

		
	}
	return mes;
}
//char* decrypt(const char* message, uint key) {}

int main()
{
	
	setlocale(LC_ALL, "Russian");
	

	char messeg[] = "РСоп рсўџ ABCD abcd";
	char* temp = encrypt(messeg, 4);
	cout << temp;
	
	delete[] temp;

	/*cout << int('Р') << endl;
	cout << int('п') << endl << endl;
	cout << int('р') << endl;
	cout << int('џ') << endl << endl;
	cout << int('Р'-1) << endl;
	cout << int('р'-1);*/

	_getch();
	return 0;
}