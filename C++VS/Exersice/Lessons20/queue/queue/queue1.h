#pragma once
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



