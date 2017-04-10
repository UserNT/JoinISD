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
	if ((mes[i] >= '�' && mes[i] <= '�') && key > 32)
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

			if (mes[i] >= '�' && mes[i] <= '�')
			{

				if ((mes[i] + char(key)) <= '�')
				{
					mes[i] = char(mes[i] + char(key));
					i++;
				}
				else
				{
					mes[i] = char(-65 + (mes[i] + char(key) - '�'));
					i++;
				}

			}




			if (mes[i] >= '�' && mes[i] <= '�')
			{
				if ((mes[i] + char(key)) <= '�')
				{
					mes[i] = char(mes[i] + char(key));
					i++;
				}
				else
				{
					mes[i] = char(char(-33) + (mes[i] + char(key) - '�'));
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

			if (mes[i] >= '�' && mes[i] <= '�')
			{

				if (char(mes[i] - char(key)) >= '�')
				{
					mes[i] = char(mes[i] - char(key));
					i++;
				}
				else
				{
					mes[i] = char('�' - ('�' - (mes[i] - char(key))));
					i++;
				}

			}

			/*if (mes[i] >= '�' && mes[i] <= '�')
			{

				if (char(mes[i] - key) >= '�')
				{
					mes[i] = char(mes[i] - key);
					i++;
				}
				else
				{
					mes[i] = char(176 - ('�' - (mes[i] - key)));
					i++;
				}				
			}
			if (mes[i] >= '�' && mes[i] <= '�')
			{
				if (char(mes[i] - key) >= '�')
				{
					mes[i] = char(mes[i] - key);
					i++;
				}
				else
				{
					mes[i] = char(240 - ('�' - (mes[i] - key)));
					i++;
				}
			}*/

			if (mes[i] >= '�' && mes[i] <= '�')
			{

				if (char(mes[i] - char(key)) >= '�')
				{
					mes[i] = char(mes[i] - char(key));
					i++;
				}
				else
				{
					mes[i] = char(char(0) - ('�' - (mes[i] - char(key))));
					i++;
				}

			}
		}
		else
			i++;


	}
	return mes;
}
