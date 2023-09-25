#include "PmergeMe.hpp"
#include <stdexcept>
#include <sstream>
#include <cmath>

#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const int& size, const char* argv[])
{
	checkargument(size, argv);
	setSequence(size, argv);
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

/* parsing */

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

/* sort using vector */

void	PmergeMe::sortByVector()
{
	std::vector<int>	vec;
	int					isOdd;
	int					last;

	vec = this->seq;
	isOdd = vec.size() % 2;
	divideTwo(vec);
	if (isOdd)
		last = *(--vec.end());
	sortMainChain(vec, 0, vec.size() / 2 - 1);
	sortInsertion(vec);
	if (isOdd)
		insert(vec, last);

	std::vector<int>::iterator	itr = vec.begin();
	for (itr = vec.begin(); itr != vec.end(); itr++)
		std::cout << *itr << std::endl;
	std::cout << "well sorted : " << std::boolalpha << isWellSorted(vec) << std::endl;
}

void	PmergeMe::divideTwo(std::vector<int>& vec)
{
	unsigned int	idx = 0;
	unsigned int	size = vec.size() / 2 * 2;

	while (idx < size)
	{
		if (vec[idx] < vec[idx + 1])
			swap(vec[idx], vec[idx + 1]);
		idx += 2;
	}
}

void	PmergeMe::sortMainChain(std::vector<int>& vec, int start, int end)
{
	if (start >= end)
		return ;

	int	mid = (end + start) / 2;

	sortMainChain(vec, start, mid);
	sortMainChain(vec, mid + 1, end);
	sortMerge(vec, start, mid, end);
}

void	PmergeMe::sortMerge(std::vector<int>& vec, int start, int mid, int end)
{
	int	i, j, k, l;
	std::vector<int>	sorted(vec);

	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (vec[i * 2] < vec[j * 2])
		{
			sorted[k * 2] = vec[i * 2];
			sorted[k++ * 2 + 1] = vec[i++ * 2 + 1];
		}
		else
		{
			sorted[k * 2] = vec[j * 2];
			sorted[k++ * 2 + 1] = vec[j++ * 2 + 1];
		}
	}
	l = i <= mid ? i : j;
	while (k <= end)
	{
		sorted[k * 2] = vec[l * 2];
		sorted[k++ * 2 + 1] = vec[l++ * 2 + 1];
	}
	vec = sorted;
}

std::vector<int>	makeMainChain(std::vector<int>& vec)
{
	std::vector<int>	mainChain;
	std::vector<int>::iterator	itr;
	std::vector<int>::iterator	end = vec.end();

	if (vec.size() % 2)
		end--;
	for (itr = vec.begin(); itr != end; itr += 2)
		mainChain.push_back(*itr);
	return mainChain;
}

void	PmergeMe::insert(std::vector<int>& vec, int value)
{
	std::vector<int>::iterator itr;
		
	itr = vec.begin() + searchBinary(vec, value);
	vec.insert(itr, value);
}

void	PmergeMe::setNextIndex(int& index, int JacobstalNumbers[], const int& n, const int& size)
{
	index--;
	if (index + 1 != JacobstalNumbers[0] || size <= JacobstalNumbers[1])
		return ;
	JacobstalNumbers[0] = JacobstalNumbers[1];
	JacobstalNumbers[1] = getJacobstalNumber(JacobstalNumbers[1], n);
	index = JacobstalNumbers[1] - 1;
	if (size <= JacobstalNumbers[1])
		index = size - 1;
}

void	PmergeMe::sortInsertion(std::vector<int>& vec)
{
	int	idx = 0;
	int	n = 2;
	int	JacobstalNumbers[2];
	std::vector<int>	sorted = makeMainChain(vec);
	
	JacobstalNumbers[0] = 0;
	JacobstalNumbers[1] = 1;
	while (idx + 1 != JacobstalNumbers[0])
	{
		insert(sorted, vec[idx * 2 + 1]);
		setNextIndex(idx, JacobstalNumbers, n++, static_cast<int>(vec.size()) / 2);
	}
	vec = sorted;
}

int	PmergeMe::getJacobstalNumber(const int& prev, const int& n)
{
	return pow(2, n) - prev;
}

int	PmergeMe::searchBinary(const std::vector<int>& sorted, const int& value)
{
	int	start = 0;
	int	end = static_cast<int>(sorted.size());
	int	mid = (start + end) / 2;

	while (sorted[mid] != value && start < end)
	{
		if (value < sorted[mid])
			end = mid - 1;
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	return value < sorted[mid] ? mid : mid + 1;
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

bool	isWellSorted(std::vector<int> vector)
{
	std::vector<int>::iterator	itr = vector.begin();
	int	prev = *itr;

	while (++itr != vector.end() && *itr >= prev)
		prev = *itr;
	return itr == vector.end();
}