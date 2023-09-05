#include "Span.hpp"
#include <limits>

Span::NotUnableSave::NotUnableSave(const char* message) : message(message) {}

const char*	Span::NotUnableSave::what() const throw()
{
	return this->message;
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
	if (this->set.size() >= this->size)
		throw (NotUnableSave("Cannot add number since already maximum elements stored."));
	this->set.insert(number);
}

unsigned int Span::shortestSpan() const
{
	handleError();	
	
	std::set<int>::iterator itr = this->set.begin();
	unsigned int			tmp = 0;
	unsigned int			span = std::numeric_limits<unsigned int>::max();
	
	tmp -= *itr;
	while (++itr != this->set.end())
	{
		tmp += *itr;
		span = min<unsigned int>(span, tmp);
		tmp = 0;
		tmp -= *itr;
	}
	return span;
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
	if (this->size == 0)
		throw (NotFound("There are no numbers stored."));
	if (this->size == 1)
		throw (NotFound("There exist only one number."));
}
