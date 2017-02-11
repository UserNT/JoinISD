#include<iostream>
#include<conio.h>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ios_base;

int main()
{
	setlocale(LC_ALL,"Russian");
	
	//int i(1);// итерация
	/*while(i <= 10)
	{
		cout << "Цикл выполнился " << i << endl;
		i++;
	}
	
	char quit;

	do 
	{
	  cout << "Продолжить программу(y/n)? ";
	}while(cin >> quit && quit == 'y');
	*/	
	unsigned long long result = 0,stepen;

	
	//Подсчет числа зерен на шахматной доске
	
	for(int n = 0; n < 64; n++)
	{	
		if(n > 0)
			for(int i = 0; i < n; i++)
			{
				stepen *= 2;
			}
		else if(n == 0)
			    stepen = 1;		
		result +=stepen;
		cout << "На " << n << " ячейке " << result << " Зерна\n";
		stepen = 1;
	}
	
	cout << "Число зерна равно = " << result;
	
	
	_getch();
	return 0;
}