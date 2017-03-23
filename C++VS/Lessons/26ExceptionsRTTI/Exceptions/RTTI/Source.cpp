#include<iostream>
#include<conio.h>
#include<stdexcept>

using namespace std;

class A
{
public:
	virtual void Print() {cout << "Print A!";}
	void A1() { cout << "A"; }
};


class B : public A
{
public:
	virtual void Print() { cout << "Print B!"; }
	virtual void B1() { cout << "B"; }
};

class C : public B
{
public:
	virtual void Print() { cout << "Print C!"; }
	virtual void B1() { cout << "C"; }
};
int main()
{
	setlocale(LC_ALL, "Russian");

	/*A* a;
	B* b;

	a = new C;
	
	if(b = dynamic_cast<C*>(a))
		b->B1();*/

	if (typeid(int) == typeid(int))
		cout << "|||||||||||||";
	
	

	_getch();
	return 0;
}