#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const int& size, const char* argv[])
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

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& pm)
{
	if (this != &pm)
	{
		this->seq.clear();
		std::vector<int>::iterator	itr = this->seq.begin();
		this->seq.insert(itr, pm.seq.begin(), pm.seq.end());
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
	int	num;
	
	for (int idx = 0; idx < size; idx++)
	{
		std::stringstream	ss(argv[idx]);
		ss >> num;
		this->seq.push_back(num);
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

