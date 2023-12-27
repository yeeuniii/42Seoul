#include "Span.hpp"
#include <limits>
#include <string>

const char*	Span::NotUnableSave::what() const throw()
{
	return "Cannot add number since already maximum elements stored.";
}

Span::NotFound::NotFound(const char* message) : message(message) {}

const char*	Span::NotFound::what() const throw()
{
	return this->message;
}

Span::Span() : size(0) {}

Span::Span(unsigned int N) : size(N) {}

Span::Span(const Span &span)
{
	*this = span;
}

Span::~Span() {}

Span &Span::operator=(const Span &span)
{
	if (this != &span)
	{
		this->set = span.set;
		this->size = span.size;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (canStored() == false)
		throw (NotUnableSave());
	this->set.insert(number);
}

bool	Span::canStored() const
{
	return this->set.size() < this->size;
}

unsigned int Span::shortestSpan() const
{
	handleError();	
	
	std::multiset<int>::iterator itr = this->set.begin();
	int			tmp;
	std::set<unsigned int>	gaps;

	tmp = *itr;
	while (++itr != this->set.end())
	{
		tmp -= *itr;
		tmp *= tmp < 0 ? -1 : 1;
		gaps.insert(tmp);
		tmp = *itr;
	}
	return *gaps.begin();
}

unsigned int Span::longestSpan() const
{
	handleError();	

	std::multiset<int>::iterator begin = this->set.begin();
	std::multiset<int>::iterator end = this->set.end();
	return *(--end) - *begin;
}

void	Span::handleError() const
{
	if (this->set.size() == 0)
		throw (NotFound("Cannot find span since there are no numbers stored."));
	if (this->set.size() == 1)
		throw (NotFound("Cannot find span since there exist only one number."));
}
