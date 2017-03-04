#include<iostream>
#include<conio.h>
#include"Header.h"
#include<clocale>


using namespace std;

//inline void F()
//{
//	cout << "Hello";
//}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	/*cout << argc << endl;

	for (int i(0); i < argc; i++)
	{
		cout << argv[i] << endl;
	}*/

	cout << Program::cout();

	_getch();
	return 0;
}