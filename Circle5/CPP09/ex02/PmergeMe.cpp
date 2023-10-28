#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pm)
{
	*this = pm;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe &pm)
{
	if (this != &pm)
	{
	}
	return *this;
}

/* utils */

bool	isPositiveIntString(std::string string)
{
	int	idx = 0;
	int	size = string.size();

	if (string == "0" || atol(string.c_str()) > std::numeric_limits<int>::max())
		return false;
	while (idx < size && isdigit(string[idx]))
		idx++;
	return idx == size;
}

int convertInteger(std::string string)
{
	std::stringstream ss(string);
	int num;

	ss >> num;
	return num;
}