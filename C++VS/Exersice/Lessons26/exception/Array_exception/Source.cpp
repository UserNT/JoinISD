
#include<iostream>
#include<conio.h>
#include<stdexcept>

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

template<typename T = int>
class Array
{
	T* arr;
	int Max;
	int current_index;
public:
	class Bad_index
	{
	private:
		int index;
	public:		
		Bad_index(int i)
		{
			index = i;
		}
		void what()
		{
			cout << "Неправильный индекс " << index << endl;
		}

	};
	struct Error
	{		
		char* txt;
		Bad_index bi;
	};
	Array(int size)
	{
		Max = size;
		arr = new T[Max];
		current_index = 0;
	}

	~Array() { delete[] arr; }

	void push(T n)
	{
		if (current_index < Max)
		{
			arr[current_index] = n;
			current_index++;
		}
		else
			{
				Array<T>::Error e{ "При записи, ", Array<T>::Bad_index(current_index) };
				throw e;				
			}
	}

	T operator[](int index);
};

template<typename T> T Array<T>::operator[](int index)
{
	if (index < 0 || index > Max - 1)
	{		
		Array<T>::Error e{ "При чтении, ", Array<T>::Bad_index(current_index) };
		throw e;	
	}
	else return arr[index];
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	/*A* b = new B[1];
	delete[] b;*/
	Array<> a(3);

	a.push(1);
	a.push(2);
	a.push(3);
	cout << a[0];
	cout << a[2];
	cout << endl;
	
	try
	{
		cout << a[5];			
	}	
	catch (Array<int>::Error e)
	{
		cout << e.txt;
		e.bi.what();
	}
	try
	{
		a.push(5);
	}
	catch (Array<int>::Error e)
	{
		cout << e.txt;
		e.bi.what();
	}
		
	cout << a[1];
	_getch();
	return 0;
}
