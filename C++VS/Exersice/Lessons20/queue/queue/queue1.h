#pragma once
#include<iostream>

class queue1
{
private:
	int* arr;
	int last;
public:
	queue1(int n);
	void push(int v);
	int pop();

	~queue1();
};

struct list
{
	int value;
	list* next;
};

class queue2
{
private:
	list* next;	
public:
	queue2();
	void push(int v);
	int pop();

	~queue2();
};

class queueDM1
{
private:
	int* arr;
	int index;
	int top;
	int min;
public:
	queueDM1(int size)
	{
		top = size;
		index = 0;
		min = 0;
		arr = new int[size];
	}
	~queueDM1()
	{
		delete[] arr;
	}
	void Push(int k)
	{
		if (index < top)
		{
			arr[index] = k;
			index++;
		}
	}

	int Pop()
	{
		if (min < index)
		{
			return arr[min++];
		}
	}

	void resize()
	{
		min = 0;
		index = 0;
	}
};

struct queue
{
	int key;
	queue* next;
	queue* back;
};

class queueDM2
{
private:
	queue* begin;
public:
	queueDM2()
	{
		begin = NULL;
	}

	void Push(int d)
	{
		queue* p = new queue;
		p->key = d;
		p->next = NULL;

		if (begin == NULL)
		{
			begin = p;
			begin->back = NULL;
		}
		else		
			while (1)
			{
				if (begin->next == NULL)
				{
					begin->next = p;
					break;
				}
				queue* temp = begin;
				begin = begin->next;
				begin->back = temp;			
			}
		while (1)
		{
			if (begin->back = NULL)
				break;
			begin = begin->back;
		}

	}

	int Pop()
	{
		int temp = begin->key;
		queue* pv = begin;

		begin = begin->next;
		delete pv;
		return temp;
	}


};
