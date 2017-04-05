#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include"CaesarDll.h"

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

			if (mes[i] >= '�' && mes[i] <= '�')
			{

				if (char(mes[i] + key) <= '�')
				{
					mes[i] = char(mes[i] + key);
					i++;
				}
				else
				{
					mes[i] = char('�' - 1 + (mes[i] + key - '�'));
					i++;
				}

			}

			if (mes[i] >= '�' && mes[i] <= '�')
			{

				if (char(mes[i] + key) <= '�')
				{
					mes[i] = char(mes[i] + key);
					i++;
				}
				else
				{
					mes[i] = char('�' + (mes[i] + key - '�'));
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
	char* mes = new char[100];
	strcpy(mes, message);

	int i = 0;

	while (mes[i] != '\0')
	{
		if (mes[i] != ' ' && mes[i] != '\n')
		{
			if (mes[i] >= 'A' && mes[i] <= 'Z')
			{

				if (char(mes[i] - key) >= 'A')
				{
					mes[i] = char(mes[i] - key);
					i++;
				}
				else
				{
					mes[i] = char('Z' - ('A' - (mes[i] - key)));
					i++;
				}

			}

			if (mes[i] >= 'a' && mes[i] <= 'z')
			{

				if (char(mes[i] + key) >= 'a')
				{
					mes[i] = char(mes[i] - key);
					i++;
				}
				else
				{
					mes[i] = char('z' - ('a' - (mes[i] - key)));
					i++;
				}

			}

			if (mes[i] >= '�' && mes[i] <= '�')
			{

				if (char(mes[i] + key) >= '�')
				{
					mes[i] = char(mes[i] - key);
					i++;
				}
				else
				{
					mes[i] = char('�' - ('�' - (mes[i] - key)));
					i++;
				}

			}

			if (mes[i] >= '�' && mes[i] <= '�')
			{

				if (char(mes[i] + key) >= '�')
				{
					mes[i] = char(mes[i] - key);
					i++;
				}
				else
				{
					mes[i] = char('�' - ('�' - (mes[i] - key)));
					i++;
				}
			}
		}
		else
			i++;


	}
	return mes;
}
