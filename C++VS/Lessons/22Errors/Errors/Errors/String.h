#pragma once
#include<iostream>
#include<cstring>
class String
{
private:
	char* str;
	int length;
	static int number_Elem;
public:
	String() { str = NULL; length = 0; }
	explicit String(char* s)
	{
		number_Elem++;
		std::cout << "Всего создано " << number_Elem << " объектов класса String\n";
		length = strlen(s);
		str = new char[length+1];
		for (int i(0); i < length; i++)
			str[i] = s[i];
		str[length] = '\0';
	}

	String(const String& s)
	{
		length = strlen(s.str);
		str = new char[length + 1];
		for (int i(0); i < length; i++)
			str[i] = s.str[i];
		str[length] = '\0';
	}

	friend std::ostream& operator<<(std::ostream& os, String& s)
	{
		os << s.str;
		return os;
	}

	String& operator=(const String& s)
	{
		delete[] str;
		
		length = strlen(s.str);
		str = new char[length + 1];
		for (int i(0); i < length; i++)
			str[i] = s.str[i];
		str[length] = '\0';
		return *this;
	}

	operator char*()
	{
		
		length = strlen(str);	
		char* s = new char[length+1];
		for (int i(0); i < length; i++)
			s[i] = str[i];
		s[length] = '\0';

		return s;//*this.str;
	}

	static int f()
	{
		return number_Elem;
	}

	~String()
	{
		number_Elem--;
		std::cout << "Уничтожен объект: " << number_Elem << " осталось\n";
		delete[] str;
	}
};

