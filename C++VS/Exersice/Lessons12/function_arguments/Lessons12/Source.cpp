#include<iostream>
#include<conio.h>

using namespace std;

void sortbubble(int* ar, int length)
{
	int temp;
	for(int i(1); i < length; i++)
		for(int j(0); j < length - i; j++)
			if (ar[j] > ar[j+1])
			{
				temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
}

int main()
{
	int ar[] = { 3,4,6,7,1,2 };
	
	for (int i(0); i < 6; i++)
		cout << ar[i] << " ";
	cout << endl;
	
	sortbubble(ar, 6);

	for (int i(0); i < 6; i++)
		cout << ar[i] << " ";
	
	_getch();
	return 0;
}