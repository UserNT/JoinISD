#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;

//class A
//{
//private:
//	// при наследовании не передоется
//public:
//	A(int a) {};
//	A() {};
//	void showA() { cout << "A"; }
//protected:
//	void Print() { cout << "Print" << endl; };
//};
//
//class B : protected A
//{
//private:
//	//
//public:
//	void showB() { cout << "B"; A::showA(); A::Print(); }
//protected:
//	//все защищенные члены базового класса
//};
//
//
//class C : public B
//{
//private:
//	//
//public:
//	void showC() { A::Print();}
//};
class A
{
public:
	virtual void show() { cout << "A"; }
};

class B : public A
{
public:
	virtual void show() { cout << "B"; }
};


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	A a;
	B b;

	A* pa = new A[2];
	pa = &a;
	pa->show();
	pa++;
	pa = &b;
	pa->show();
	
	_getch();
	return 0;
}