#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;
//определяет колличество слов содержащих букву 'b'
int main()
{
	setlocale(LC_ALL, "Russian");

	bool isWord = false;
	bool isB = false;
	int numberWordB = 0;
	const int N = 50;
	char str[N];
	


	cout << "Введите строку: ";
	cin.getline(str,N);

	for(int i(0); i < strlen(str); i++)
	{
		if(isalpha(str[i]) && !isWord)
			isWord = true;
		if(!isalpha(str[i]))
		{
			isWord = false;
			isB = false;
		}
		if(isWord && (str[i] == 'b'||str[i] == 'B') && isB == false)
		{
			isB = true;
			numberWordB++;
		}

	}
	
	system("cls");

	cout << "В набранном тексте " << numberWordB << " словa с буквой \'b\'.\n";
	_getch();
	return 0;
}