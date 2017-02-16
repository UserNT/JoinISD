#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;

char* cat(const char str1[], const char str2[])
{
	int length1 = strlen(str1);
	int length2 = strlen(str2);

	char* arr = new char[length1 + length2 +1];

	for (int i(0); i < length1; i++)
		arr[i] = str1[i];
	for (int i(0); i < length2; i++)
		arr[i + length1] = str2[i];
	arr[length1 + length2] = '\0';

	return arr;
}

int main()
{
	char str1[] = "Hello";
	char str2[] = " World\n";
	char* concatination = cat(str1, str2);

	cout << concatination;

	delete[] concatination;

	_getch();
	return 0;
}