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

			if (mes[i] >= 'À' && mes[i] <= 'ß')
			{

				if (char(mes[i] + key) <= 'ß')
				{
					mes[i] = char(mes[i] + key);
					i++;
				}
				else
				{
					mes[i] = char('À' - 1 + (mes[i] + key - 'ß'));
					i++;
				}

			}

			if (mes[i] >= 'à' && mes[i] <= 'ÿ')
			{

				if (char(mes[i] + key) <= 'ÿ')
				{
					mes[i] = char(mes[i] + key);
					i++;
				}
				else
				{
					mes[i] = char('ß' + (mes[i] + key - 'ÿ'));
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

			if (mes[i] >= 'À' && mes[i] <= 'ß')
			{

				if (char(mes[i] + key) >= 'À')
				{
					mes[i] = char(mes[i] - key);
					i++;
				}
				else
				{
					mes[i] = char('ß' - ('À' - (mes[i] - key)));
					i++;
				}

			}

			if (mes[i] >= 'à' && mes[i] <= 'ÿ')
			{

				if (char(mes[i] + key) >= 'à')
				{
					mes[i] = char(mes[i] - key);
					i++;
				}
				else
				{
					mes[i] = char('ÿ' - ('à' - (mes[i] - key)));
					i++;
				}
			}
		}
		else
			i++;


	}
	return mes;
}
