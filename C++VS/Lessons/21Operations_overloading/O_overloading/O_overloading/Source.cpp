#include<iostream>
#include<fstream>
#include<conio.h>
#include"time.h"

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	/*time t1(4500);
	time t2(2,35,21);
	time t3;

	t3 = t1 + t2;

	cout << "Result = " << t3 << " ÷÷:ìì:ññ ";*/

	Vector v1(30, 50);
	Vector v2(6.56, 1.34, Polar);
	cout << v1+v2 << endl;

	
	_getch();
	return 0;
}