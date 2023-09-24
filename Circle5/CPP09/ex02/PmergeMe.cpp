#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const int& size, const char* argv[]) : seq(new int[size]), size(size)
{
	try
	{
		checkargument(size, argv);
		setSequence(size, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

PmergeMe::PmergeMe(const PmergeMe &pm)
{
	*this = pm;
}

PmergeMe::~PmergeMe()
{
	delete[] this->seq;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& pm)
{
	if (this != &pm)
	{
		delete[] this->seq;
		this->seq = new int[pm.size];
		for (unsigned int idx = 0; idx < pm.size; idx++)
			this->seq[idx] = pm.seq[idx];
		this->size = pm.size;
	}
	return *this;
}

void	PmergeMe::checkargument(const int& size, const char* argv[]) const
{
	int		idx = 0;
	bool	isValid = true;

	while (isValid && idx < size)
	{
		std::string	argument(argv[idx]);
		isValid = isPositiveIntString(argv[idx]);
		idx++;
	}
	if (isValid == false)
		throw (std::invalid_argument("Error: not a positive number."));
}

void	PmergeMe::setSequence(const int& size, const char* argv[])
{
	for (int idx = 0; idx < size; idx++)
	{
		std::stringstream ss(argv[idx]);
		ss >> this->seq[idx];
	}
}

/* util functions */

bool	isPositiveIntString(std::string string)
{
	int	idx = 0;
	int	size = string.size();

	while (idx < size && isdigit(string[idx]))
		idx++;
	return idx == size;
}

void	swap(int& first, int& last)
{
	int	tmp = first;

	first = last;
	last = tmp;
}

