#include "Stack.h"
#include<iostream>
using namespace std;
namespace STK
{
	Stack1::Stack1(int number)
	{
		index = 0;
		Max = 1000;
		if (number <= Max)
		{
			arr = new int[number];
			Max = number;
		}
		else std::cout << "Переполнение стека!";
	}

	bool Stack1::Push(int n)
	{
		if (index == Max)
			return false;
		
		arr[index] = n;
		index++;
		return true;
		
	}

	int Stack1::Pop()
	{
		if (index >= 0)
			return arr[--index];
		else return 0;
	}
	Stack1::~Stack1()
	{
		delete[] arr;
	}
	bool Stack1::Is_Empty()
	{
		if (index <= 0)
			return true;
		return false;
	}
	bool Stack1::Is_Full()
	{
		if (index == Max)
			return true;
		else return false;
	}

	

	/*Stack2::Stack2()
	{
		level = 0;
		first = NULL;
		next = NULL;
	}

	void Stack2::Push(int n)
	{
		level++;
		if (level > 1)
		{
			Stack2* prevFirst = first;			
			Stack2* first = new Stack2;
			first->value = n;
			first->next = prevFirst;	
			
		}
		else
		{
			first = this;
			value = n;			
		}
		
	}

	int Stack2::Pop()
	{
		if (level == 0)
		{
			std::cout << "Stack is empty!";
			return 0;
		}
		else
		{
			int temp = first->value;
			Stack2* nextFirst = first->next;
			delete first;
			first = nextFirst;
			return temp;
		}
	}

	Stack2::~Stack2()
	{

	}*/
}