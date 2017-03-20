
#include<iostream>
#include<conio.h>

using namespace std;

//class A
//{
//	int* a;
//public:
//	A() { a = new int[10]; cout << "Constructor A" << endl; }
//	virtual~A() { delete[] a; cout << "Destructor A" << endl; }
//};
//
//class B : public A
//{
//	int* a;
//public:
//	B() :A() { a = new int[10]; cout << "Constructor B" << endl; }
//	virtual~B() { delete[] a; cout << "Destructor B" << endl; }
//};
//
//class Abstract
//{
//protected:
//	Point center;
//	double radius;
//public:
//	//
//	virtual void draw() = 0;
//};

template<typename T, typename T2 = int>
class Array
{
	T* arr;
	int Max;
	int current_index;
public:
	Array(int size)
	{
		Max = size;
		arr = new T[Max];
		current_index = 0;
	}

	~Array() { delete[] arr; }

	void push(T n)
	{
		arr[current_index] = n;
		current_index++;
	}
	T2 get()
	{
		T2 a = 2;
		return a;
	}
	
	T operator[](int index);	
};

template<typename T, typename T2> T Array<T, T2>::operator[](int index)
{
	if (index < 0 || index > Max - 1)
	{
		cout << "Wrong index!";
		_getch();
		abort();
	}
	else return arr[index];
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	/*A* b = new B[1];
	delete[] b;*/
	Array<int> a(3);

	a.push(1);
	a.push(2);
	a.push(3);
	cout << a[0];
	cout << a[2];

	cout << a.get();

	_getch();
	return 0;
}
