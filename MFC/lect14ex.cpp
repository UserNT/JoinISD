// lect14ex.cpp - пример создания класса-данных "Студент" и класса-списка "Список студентов",
// демонстрация функций-членов классов, а также свободных функций (PrintList)
//
// class Student - класс-данные "Студент". Представляет данные об одном студенте.
//
// class List - класс, представляющий односвязный список.
//
// void testStudent() - тестирование класса студента
// void testList() - тестирование и пример работы с классом списка
//
// Copyright (c) Михаил Русаков, 2009. CodingLessons.ru

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
		cout << "Список пуст...\n";
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

	cout << "Тестирование класса Студент:\n";
	testStudent();
	
	cout << "Тестирование списка:\n";
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
		sprintf(name, "Студент %d", i+1);
	
		st.SetNumber(i+1);
		st.SetMark(((rand() % 1000) + 1) / 10);
		st.SetName(name);
		list.PushBack(&st);
	}

	PrintList("Все студенты:\n", list);

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

	PrintList("\n\nДвоечники:\n", botchers);
	PrintList("\n\nУспевающие студенты:\n", list);

	system("pause");
}

void testStudent()
{
	Student s1, s2;

	cout << "Созданные элементы:\n";
	s1.Print();
	s2.Print();

	s1.SetNumber(1);
	s1.SetName("Иван Петров");
	s1.SetMark(75);
	
	s2.SetMark(90);
	s2.SetNumber(2);
	s2.SetName("Петр Иванов");

	cout << "\n\nЗаполненные элементы:\n";
	s1.Print();
	s2.Print();

	cout << "\n\nМеняем имя для Иван Петров:\n";
	s1.SetName("Кирилл Семенов");
	s1.Print();

	cout << "\n\nМеняем оценку для Петр Иванов (s2):\n";
	s2.SetMark(60);
	s2.Print();

	cout << "\n\nМеняем номер и оценку на недействительные:\n";
	s2.SetNumber(-10);
	s2.SetMark(-50);
	s2.Print();

	cout << "\n\nПробуем оператор присваивания:\n";
 	
	Student s3;
 
 	s3 = s1;
	s2 = s3;


	s1.Print();
	s2.Print();
 	s3.Print();
	
	system("pause");
}