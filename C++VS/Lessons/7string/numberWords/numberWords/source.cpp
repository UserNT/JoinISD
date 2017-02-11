#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;

int main()
{
 char str[80];
 bool inWord = false;
 int numberWords = 0;

 cout << "Enter string: ";
 cin.getline(str,80);
 system("cls");

 for (int i(0); str[i] != '\0'; i++)
 {	
	 if(isalpha(str[i]) && !inWord)
	 {
		 numberWords++;
		 inWord = true;
	 }
	 if(!isalpha(str[i]))
		 inWord = false;
 }
	
 cout << numberWords << endl;
_getch();
return 0;
}