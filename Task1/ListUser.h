#pragma once



#include"stdafx.h"
#include<iostream>
#include<string.h>

class User
{
private:
	int _number;
	CString _login;
	//char* _login;
	CString _password;
public:
	User()
	{
		_number = 0;
		_login = L"";
		_password = L"";
	}
	~User()
	{
	}

	User& operator= (User& rhv)
	{
		_login = rhv._login;
		_number = rhv._number;
		_password = rhv._password;

		return *this;
	}

	void Setlogin(const CString login)
	{
		_login = login;
	}

	CString Getlogin()
	{
		return _login;
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

	void SetPassword(CString password)
	{

		_password = password;

	}

	CString GetPassword()
	{
		return _password;
	}

};

class List
{
	struct ListNode
	{
		User u;
		ListNode* next;
	};
private:
	ListNode* _first;
	ListNode* _cur;
public:
	List()
	{
		_first = _cur = NULL;
	}
	List(List& li)
	{
		CopyFrom(li);
	}

	~List()
	{
		Clear();
	}

	bool IsValid(CString login, CString password)
	{
		ListNode *node = _first;
		ListNode* tmp = NULL;
		while (node != NULL)
		{
			tmp = node;
			if(node->u.Getlogin() == login && node->u.GetPassword() == password)
			return true;

			node = node->next;			
		}

		return false;
	}

	void Clear()
	{
		ListNode *node = _first;

		while (node != NULL)
		{
			ListNode* tmp = node;
			node = node->next;

			delete tmp;
		}

		_first = NULL;
		_cur = NULL;
	}

	List& operator= (List& rhv)
	{
		Clear();
		CopyFrom(rhv);
	}

	bool HasNext()
	{
		if (_cur != NULL && _cur->next != NULL)
		{
			return true;
		}
		return false;
	}

	User* GetNext()
	{
		if (_cur)
		{
			_cur = _cur->next;
		}

		if (_cur)
		{
			return &_cur->u;
		}

		return NULL;
	}

	User* GetFirst()
	{
		_cur = _first;
		if (_cur == NULL)
		{
			return NULL;
		}
		return &_cur->u;
	}

	void PushBack(User* u)
	{
		ListNode* tail = GetTail();
		ListNode* newNode = new ListNode;

		newNode->u = *u;
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

		ListNode* left = FindLeftOf(_cur);

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
		ListNode* node = _first;
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
		User* u = NULL;
		for (u = list.GetFirst(); u != NULL; u = list.GetNext())
		{
			PushBack(u);
		}
	}

	ListNode* FindLeftOf(ListNode* node)
	{
		ListNode* tmp = _first;

		while (tmp && tmp->next != node)
		{
			tmp = tmp->next;
		}

		return tmp;
	}
private:
	ListNode* GetTail()
	{
		ListNode* node = _first;
		while (node != NULL && node->next != NULL)
		{
			node = node->next;
		}
		return node;
	}

};