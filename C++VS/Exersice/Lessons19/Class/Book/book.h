#pragma once
#include<iostream>
namespace Library
{
	typedef unsigned int ui;
	class book
	{
	private:
		char* Title;
		char* Author;
		char* Genre;		
		double Price;		
	public:
		book(char* title = "",char* author = "",char* genre = "",double price = 0.0);
		void setTitle(char* title);
		void setAuthor(char* author);
		void setGenre(char* genre);
		void setPrice(double price);	
		char* getTitle() const;
		char* getAuthor() const;
		char* getGenre() const;
		double getPrice() const;
		void Print(std::ostream &os) const;
		~book();
	};

}