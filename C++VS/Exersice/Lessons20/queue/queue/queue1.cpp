#include "queue1.h"
#include<iostream>
using std::cout;
using std::endl;

queue1::queue1(int n)
{
	arr = new int[n];
	last = 0;
}

int queue1::pop()
{
	int temp = arr[0];
	for (int i(0); i < (last-1); i++)
		arr[i] = arr[i + 1];
	last--;
	return temp;
}

void queue1::push(int v)
{
	arr[last++] = v;
}

queue1::~queue1()
{
	delete[] arr;
}


queue2::queue2()
{
	next = NULL;
}
void queue2::push(int v)
{
	list* top = new list;
	top->value = v;
	top->next = next;
	next = top;
}

int queue2::pop()
{
	list* Next = next;
	if (!next)
	{
		cout << "Stack is empty!" << endl;
		return 0;
	}
	
	if (!(Next->next))
	{
		int temp = Next->value;
		delete Next;
		next = NULL;
		return temp;
	}
	while (Next->next->next)
	{
		Next = Next->next;		
	}
	
	int temp = Next->next->value;
	delete Next->next;
	Next->next = NULL;	
	return temp;
}
queue2::~queue2()
{

}