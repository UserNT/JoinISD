#include "book.h"

namespace Library
{

	book::book(char* title, char* author, char* genre, double price)
	{
		Title = title;
		Author = author;
		Genre = genre;
		Price = price;
	}

	void book::setTitle(char* title)
	{
		Title = title;
	}

	void book::setAuthor(char* author)
	{
		Author = author;
	}
	
	void book::setGenre(char* genre)
	{
		Genre = genre;
	}

	void book::setPrice(double price)
	{
		Price = price;
	}
	char* book::getTitle() const
	{
		return Title;
	}

	char* book::getAuthor() const
	{
		return Author;
	}

	char* book::getGenre() const
	{
		return Genre;
	}

	double book::getPrice() const
	{
		return Price;
	}

	void book::Print(std::ostream &os) const
	{		
		os << "�����: " << Author << std::endl;
		os << "�������� �����: " << Title << std::endl;
		os << "����: " << Genre << std::endl;
		os << "����: " << Price << std::endl;
	}
	book::~book()
	{
	}

}