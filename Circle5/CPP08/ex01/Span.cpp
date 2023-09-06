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

void Span::addNumbers(int *numbers, unsigned int size)
{
	unsigned int idx = 0;

	if (canStored() == false)
		throw (NotUnableSave());
	while (idx < size && this->set.size() < this->size)
	{
		this->set.insert(numbers[idx]);
		idx++;
	}
	if (idx != size)
		throw (NotUnableSave());		
}

bool	Span::canStored() const
{
	return this->set.size() < this->size;
}

unsigned int Span::shortestSpan() const
{
	handleError();	
	
	std::set<int>::iterator itr = this->set.begin();
	unsigned int			tmp = 0;
	std::set<unsigned int>	gaps;

	tmp -= *itr;
	while (++itr != this->set.end())
	{
		tmp += *itr;
		gaps.insert(tmp);	
		tmp = 0;
		tmp -= *itr;
	}
	return *gaps.begin();
}

unsigned int Span::longestSpan() const
{
	handleError();	

	std::set<int>::iterator begin = this->set.begin();
	std::set<int>::iterator end = this->set.end();
	return *(--end) - *begin;
}

void	Span::handleError() const
{
	if (this->set.size() == 0)
		throw (NotFound("Cannot find span since there are no numbers stored."));
	if (this->set.size() == 1)
		throw (NotFound("Cannot find span since there exist only one number."));
}
