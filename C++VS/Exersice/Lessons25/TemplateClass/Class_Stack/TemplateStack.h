#pragma once

template<typename T>

class TemplateStack
{
private:
	struct list { T x; list* next; };
	list* first;
public:
	void push(T x);	
	T pop();
	bool Is_Empty();
	TemplateStack();
	~TemplateStack();
};

template<typename T> TemplateStack<T>::TemplateStack()
{
	first = NULL;
}

template<typename T> void TemplateStack<T>::push(T x)
{
	list* temp = new list;
	temp->x = x;
	temp->next = first;
	first = temp;	
}

template<typename T> T TemplateStack<T>::pop()
{
	T temp = first->x;
	list* pv = first;
	first = first->next;
	delete pv;
	return temp;
}

template<typename T> bool TemplateStack<T>::Is_Empty()
{
	return first == NULL;
}

template<typename T> TemplateStack<T>::~TemplateStack()
{
	list* temp;
	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
}