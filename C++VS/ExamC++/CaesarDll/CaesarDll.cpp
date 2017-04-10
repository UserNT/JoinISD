#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include"CaesarDll.h"

typedef unsigned int uint;

char* encrypt(const char* message, uint key)
{
	
	int i = 0;

	char* mes = new char[100];
	strcpy(mes, message);
	
	if ((mes[i] >= 'A' && mes[i] <= 'z') && key > 26)
		key %= 26;
	if ((mes[i] >= 'À' && mes[i] <= 'ÿ') && key > 32)
		key %= 32;

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

				if (mes[i] + key <= 'z')
				{
					mes[i] = char(mes[i] + key);
					i++;
				}
				else
				{
					mes[i] = char(96 + (mes[i] + key - 'z'));
					i++;
				}

			}

			if (mes[i] >= 'À' && mes[i] <= 'ß')
			{

				if ((mes[i] + char(key)) <= 'ß')
				{
					mes[i] = char(mes[i] + char(key));
					i++;
				}
				else
				{
					mes[i] = char(-65 + (mes[i] + char(key) - 'ß'));
					i++;
				}

			}




			if (mes[i] >= 'à' && mes[i] <= 'ÿ')
			{
				if ((mes[i] + char(key)) <= 'ÿ')
				{
					mes[i] = char(mes[i] + char(key));
					i++;
				}
				else
				{
					mes[i] = char(char(-33) + (mes[i] + char(key) - 'ÿ'));
					i++;
				}
			}

		}
		else
			i++;

	}
	return mes;
}

char* decrypt(const char* message, uint key)
{
	
	int i = 0;

	char* mes = new char[100];
	strcpy(mes, message);

	if ((mes[i] >= 'A' && mes[i] <= 'z') && key > 26)
		key %= 26;
	else
		key %= 32;
	

	while (mes[i] != '\0')
	{
		if (mes[i] != ' ' && mes[i] != '\n')
		{
			if (mes[i] >= 'A' && mes[i] <= 'Z')
			{

				if (char(mes[i] - char(key)) >= 'A')
				{
					mes[i] = char(mes[i] - char(key));
					i++;
				}
				else
				{
					mes[i] = char('[' - ('A' - (mes[i] - char(key))));
					i++;
				}

			}

			if (mes[i] >= 'a' && mes[i] <= 'z')
			{

				if (char(mes[i] - char(key)) >= 'a')
				{
					mes[i] = char(mes[i] - char(key));
					i++;
				}
				else
				{
					mes[i] = char('{' - ('a' - (mes[i] - char(key))));
					i++;
				}

			}

			if (mes[i] >= 'À' && mes[i] <= 'ß')
			{

				if (char(mes[i] - char(key)) >= 'À')
				{
					mes[i] = char(mes[i] - char(key));
					i++;
				}
				else
				{
					mes[i] = char('à' - ('À' - (mes[i] - char(key))));
					i++;
				}

			}

			/*if (mes[i] >= 'à' && mes[i] <= 'ÿ')
			{

				if (char(mes[i] - key) >= 'à')
				{
					mes[i] = char(mes[i] - key);
					i++;
				}
				else
				{
					mes[i] = char(176 - ('à' - (mes[i] - key)));
					i++;
				}				
			}
			if (mes[i] >= 'ð' && mes[i] <= 'ÿ')
			{
				if (char(mes[i] - key) >= 'ð')
				{
					mes[i] = char(mes[i] - key);
					i++;
				}
				else
				{
					mes[i] = char(240 - ('à' - (mes[i] - key)));
					i++;
				}
			}*/

			if (mes[i] >= 'à' && mes[i] <= 'ÿ')
			{

				if (char(mes[i] - char(key)) >= 'à')
				{
					mes[i] = char(mes[i] - char(key));
					i++;
				}
				else
				{
					mes[i] = char(char(0) - ('à' - (mes[i] - char(key))));
					i++;
				}

			}
		}
		else
			i++;


	}
	return mes;
}
