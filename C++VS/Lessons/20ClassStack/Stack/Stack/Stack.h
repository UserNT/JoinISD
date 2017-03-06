#pragma once
#include<iostream>
namespace STK
{
	class Stack1
	{
	private:
		int* arr;
		int Max;
		int index;
	public:

		Stack1(int number);	
		bool Push(int n);
		int Pop();
		bool Is_Empty();
		bool Is_Full();
		~Stack1();	
	};

	struct Stack
	{
		int key;
		Stack* next;
	};

	class Stack2
	{
	private:
		Stack* next;
	public:
		Stack2() {};

		void Push(int d)
		{
			Stack* pv = new Stack;
			pv->key = d;
			pv->next = next;
			next = pv;
		}

		int Pop()
		{
			int temp = next->key;
			Stack* pv = next;
			next = next->next;
			delete pv;
			return temp;
		}
	};

	/*class Stack2
	{
	private:
		Stack2* first;
		int value;
		Stack2* next;
		static int level;
	public:		
		Stack2();
		void Push(int n);
		int Pop();
		~Stack2();
	};*/
}