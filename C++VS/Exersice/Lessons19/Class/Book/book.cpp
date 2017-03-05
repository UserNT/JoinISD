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
		os << "Автор: " << Author << std::endl;
		os << "Название книги: " << Title << std::endl;
		os << "Жанр: " << Genre << std::endl;
		os << "Цена: " << Price << std::endl;
	}
	book::~book()
	{
	}

}