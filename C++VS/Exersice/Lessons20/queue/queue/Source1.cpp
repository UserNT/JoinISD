#include<iostream>
#include<conio.h>
#include "queue1.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	/*queue1 q(6);

	q.push(1);
	q.push(2);
	q.push(3);

	cout << q.pop() << endl;
	cout << q.pop() << endl;

	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);

	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;*/
	
	/*queue2 q;

	q.push(1);
	q.push(2);
	q.push(3);

	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;

	q.push(4);
	q.push(5);
	q.push(6);
	q.push(6);	
	q.push(6);

	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	*/
	for (int i(0); i < 1000000; i++)
	{
		for (int j(0); j < 100; j++)
		{
			queue2 q;
			q.push(j);
		}
	}

	_getch();
	return 0;
}