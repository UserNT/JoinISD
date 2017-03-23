#pragma once

template<typename T>

class TemplateStack
{
private:
	struct list { T x; list* next; };
	list* first;
	int topIndex;
public:
	void push(T x);
	T pop();
	bool Is_Empty();
	TemplateStack();
	~TemplateStack();
	class bad_Stack
	{
	private:
		int wrong_index;
	public:
		bad_Stack(int i) {wrong_index = i;}
		void what()
		{
			cout << "In stack type: " << (typeid(T)).name() << ", wrong method Pop with index: "
				<< wrong_index << endl;
		}
	};
};

template<typename T> TemplateStack<T>::TemplateStack()
{
	first = NULL;
	topIndex = 0;
}

template<typename T> void TemplateStack<T>::push(T x)
{
	list* temp = new list;
	temp->x = x;
	temp->next = first;
	first = temp;
	topIndex++;
}

template<typename T> T TemplateStack<T>::pop()
{
	topIndex--;
	if (topIndex >= 0)
	{
		T temp = first->x;
		list* pv = first;

		first = first->next;
		delete pv;
		return temp;
	}
	else
	{
		throw bad_Stack(topIndex);
	}
}

template<typename T> bool TemplateStack<T>::Is_Empty()
{
	if (topIndex <= 0)
		return true;
	else return false;
}

template<typename T> TemplateStack<T>::~TemplateStack()
{
	delete[] first;
}