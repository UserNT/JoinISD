#include<iostream>
#include<conio.h>

//Односвязный список
using namespace std;

struct A
{
	int key;
};

struct list
{
	A a;
	list* next;
};

void Pprint(list* b)
{
	list* print = b;

	while (print)
	{
		cout << print->a.key << " -> ";
		print = print->next;
	}
	cout << "NULL\n";
}

void Init(list** begin)
{
	*begin = new list;

	A a[5] = { 43,56,86,98,100 };

	(*begin)->a.key = 20;
	(*begin)->next = NULL;

	list* end = *begin;

	for (int i(0); i < 5; i++)
	{
		end->next = new list;
		end = end->next;
		end->a = a[i];
		end->next = NULL;
	}
}

void Add_begin(list** List, const A &a)
{
	list* Listn = new list;
	Listn->a.key = a.key;
	Listn->next = *List;
	*List = Listn;
}

void Add_end(list** end, const A &a)
{
	list* t = *end;
	while (t)
	{
		if (t->next == NULL)
		{
			list* t = new list;
			t->a = a;
			t->next = NULL;
			t->next = t;
			return;
		}
		t = t->next;
	}
}

void Insert(list **begin, const A &a)
{
	list* ins = new list;
	ins->a = a;
	if (*begin == NULL)
	{
		ins->next = NULL;
		*begin = ins;
		return;
	}

	list* t = *begin;

	if (t->a.key >= ins->a.key)
	{
		ins->next = t;
		*begin = ins;
		return;
	}

	list* t1 = t->next;

	while (t1)
	{
		if (t->a.key < ins->a.key && ins->a.key <= t1->a.key)
		{
			t->next = ins;
			ins->next = t1;
			return;
		}

		t = t1;
		t1 = t1->next;
	}
	t->next = ins;
	ins->next = NULL;
}

void Delete(list** begin, const A&a)
{
	if (*begin == NULL)
	{
		return;
	}
	list* t = *begin;
	if (t->a.key == a.key)
	{
		*begin = t->next;
		delete t;
		return;
	}

	list* t1 = t->next;

	while (t1)
	{
		if (t1->a.key == a.key)
		{
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}

void Free(list** begin)
{
	if (*begin == 0)return;
	list* p = *begin;
	list* t;

	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*begin = NULL;

}

int main()
{

	setlocale(LC_ALL, "Russian");

	list* begin = NULL;//зачем?
	A a = { 86 };


	Init(&begin);
	Pprint(begin);
	//Add_begin(&begin, a);
	//Pprint(begin);
	//Add_end(&begin, a);
	//Pprint(begin);
	//Insert(&begin, a);
	//Pprint(begin);
	Delete(&begin, a);
	Pprint(begin);
	Free(&begin);
	Pprint(begin);

	_getch();
	return 0;
}