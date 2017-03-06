#include<conio.h>
#include<iostream>
#include "Stack.h"

using namespace std;
using STK::Stack1;
using STK::Stack2;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	
	/*Stack1 st(5);
	
	for (int i(0); !st.Is_Full(); i++)
	{
		st.Push(i + 1);
	}

	for (int i(0);!st.Is_Empty(); i++)
		cout << st.Pop() << endl;*/

	Stack2 st;

	for (int i(0); i < 4; i++)
	{
		st.Push(i + 1);
	}

	for (int i(0);i < 4; i++)
		cout << st.Pop() << endl;

	_getch();
	return 0;
}