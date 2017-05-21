// lect14ex.cpp - ������ �������� ������-������ "�������" � ������-������ "������ ���������",
// ������������ �������-������ �������, � ����� ��������� ������� (PrintList)
//
// class Student - �����-������ "�������". ������������ ������ �� ����� ��������.
//
// class List - �����, �������������� ����������� ������.
//
// void testStudent() - ������������ ������ ��������
// void testList() - ������������ � ������ ������ � ������� ������
//
// Copyright (c) ������ �������, 2009. CodingLessons.ru

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

class Student
{
public:
	Student()
	{
		_number		= 0;
		_name		= strdup("");
		_avgMark	= 0;

	}

	~Student()
	{
		if (_name != NULL)
		{
			delete [] _name;
		}
	}

	Student& operator=(Student& rhv)
	{
		if (_name != NULL)
			delete [] _name;
		
		_name = new char[strlen(rhv._name) + 1];
		strcpy(_name, rhv._name);
		
		_number = rhv._number;
		_avgMark = rhv._avgMark;

		return *this;
	}

	void SetName(const char* name)
	{
		if (_name != NULL)
		{
			delete [] _name;
		}
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
	}

	const char* GetName()
	{
		return _name;
	}

	void SetNumber(int n)
	{
		if (n > 0)
			_number = n;
	}

	int GetNumber()
	{
		return _number;
	}

	void SetMark(float mark)
	{
		if (mark >= 0.0 && mark <= 100.0)
		{
			_avgMark = mark;
		}
	}

	float GetMark()
	{
		return _avgMark;
	}

	void Print()
	{
		cout << _number << ". " << _name;
		cout << " (" << _avgMark << ")\n";
	}

private:
	int		_number;
	char*	_name;
	float	_avgMark;
};

class List
{
	struct ListNode
	{
		Student   s;
		ListNode *next;
	};
public:
	List()
	{
		_first = _cur = NULL;
	}

	List(List& src)
	{
		CopyFrom(src);
	}

	~List()
	{
		Clear();
	}

	void Clear()
	{
		ListNode *node = _first;

		while (node != NULL)
		{
			ListNode *tmp = node;
			node = node->next;

			delete tmp;
		}

		_first = NULL;
		_cur   = NULL;
	}

	List& operator=(List& rhv)
	{
		Clear();
		CopyFrom(rhv);
	}

	bool HasNext()
	{
		if (_cur != NULL 
			&& _cur->next != NULL)
		{
			return true;
		}
		return false;
	}

	Student* GetNext()
	{
		if (_cur)
		{
			_cur = _cur->next;
		}

		if (_cur)
		{
			return &_cur->s;
		}
		
		return NULL;
	}

	Student* GetFirst()
	{
		_cur = _first;

		if (_cur == NULL)
		{
			return NULL;
		}
		return &_cur->s;
	}

	void PushBack(Student* s)
	{
		ListNode *tail = GetTail();

		ListNode *newNode = new ListNode;

		newNode->s    = *s;
		newNode->next = NULL;

		if (tail != NULL)
		{
			tail->next = newNode;
		}
		else
		{
			_first = newNode;
		}
	}

	void RemoveCurrent()
	{
		if (_first == NULL && _cur == NULL)
		{
			return;
		}

		if (_first == _cur)
		{
			_first = _first->next;
			delete _cur;
			_cur = _first;
			return;
		}

		ListNode *left = FindLeftOf(_cur);

		if (left != NULL)
		{
			left->next = _cur->next;
			delete _cur;

			_cur = left->next;
		}
	}

	int GetCount()
	{
		int nCount = 0;
		ListNode *node = _first;
		while (node != NULL)
		{
			nCount = nCount + 1;
			node = node->next;
		}
		return nCount;	
	}
private:
	void CopyFrom(List& list)
	{
		Student* s = NULL;
		for (s = list.GetFirst(); s != NULL; s = list.GetNext())
		{
			PushBack(s);
		}
	}

	ListNode* FindLeftOf(ListNode* node)
	{
		ListNode *tmp = _first;

		while (tmp && tmp->next != node)
		{
			tmp = tmp->next;
		}

		return tmp;
	}


private:
	ListNode* GetTail()
	{
		ListNode *node = _first;
		while (node != NULL 
				&& node->next != NULL)
		{
			node = node->next;
		}
		return node;
	}

private:
	ListNode *_first;
	ListNode *_cur;

};

void PrintList(const char* header, List& list)
{
	cout << header;

	if (list.GetCount() == 0)
	{
		cout << "������ ����...\n";
		return;
	}

	Student *s = NULL;
	for (s = list.GetFirst(); s != NULL; s = list.GetNext())
	{
		s->Print();
	}
}

void testStudent();
void testList();

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "������������ ������ �������:\n";
	testStudent();
	
	cout << "������������ ������:\n";
	testList();
}

void testList()
{
	srand(time(NULL));
	 
	List list;
	 
	for (int i = 0; i < 5; ++i)
	{
		Student st;
		char name[25];
		sprintf(name, "������� %d", i+1);
	
		st.SetNumber(i+1);
		st.SetMark(((rand() % 1000) + 1) / 10);
		st.SetName(name);
		list.PushBack(&st);
	}

	PrintList("��� ��������:\n", list);

	List botchers;

	Student* s = NULL;
	s = list.GetFirst();

	while (s != NULL)
	{
		if (s->GetMark() < 50)
		{
			botchers.PushBack(s);
			list.RemoveCurrent();
			s = list.GetFirst();
		}
		else
		{
			s = list.GetNext();
		}
	}

	PrintList("\n\n���������:\n", botchers);
	PrintList("\n\n���������� ��������:\n", list);

	system("pause");
}

void testStudent()
{
	Student s1, s2;

	cout << "��������� ��������:\n";
	s1.Print();
	s2.Print();

	s1.SetNumber(1);
	s1.SetName("���� ������");
	s1.SetMark(75);
	
	s2.SetMark(90);
	s2.SetNumber(2);
	s2.SetName("���� ������");

	cout << "\n\n����������� ��������:\n";
	s1.Print();
	s2.Print();

	cout << "\n\n������ ��� ��� ���� ������:\n";
	s1.SetName("������ �������");
	s1.Print();

	cout << "\n\n������ ������ ��� ���� ������ (s2):\n";
	s2.SetMark(60);
	s2.Print();

	cout << "\n\n������ ����� � ������ �� ����������������:\n";
	s2.SetNumber(-10);
	s2.SetMark(-50);
	s2.Print();

	cout << "\n\n������� �������� ������������:\n";
 	
	Student s3;
 
 	s3 = s1;
	s2 = s3;


	s1.Print();
	s2.Print();
 	s3.Print();
	
	system("pause");
}