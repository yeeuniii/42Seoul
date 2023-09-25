#include "PmergeMe.hpp"
#include <stdexcept>
#include <sstream>
#include <cmath>

#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const int& size, const char* argv[])
{
	checkArgument(size, argv);
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
		this->origin.clear();
		std::vector<int>::iterator	itr = this->origin.begin();
		this->origin.insert(itr, pm.origin.begin(), pm.origin.end());
	}
	return *this;
}

/* parsing */

void	PmergeMe::checkArgument(const int& size, const char* argv[]) const
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
		this->origin.push_back(num);
	}
}

/* sort */

void	PmergeMe::sort()
{
	PmergeMe::Vector	vec(this->origin);

	vec.sort();
}

/* Vector */

PmergeMe::Vector::Vector() {}

PmergeMe::Vector::Vector(const std::vector<int>& origin)
{
	_seq = origin;
	_size = static_cast<int>(_seq.size());
}

PmergeMe::Vector::Vector(const Vector& vector)
{
	*this = vector;
}

PmergeMe::Vector::~Vector() {}

PmergeMe::Vector&	PmergeMe::Vector::operator=(const Vector& vector)
{
	if (this != &vector)
	{
		_seq = vector._seq;
		_size = vector._size;
		_time = vector._time;
	}
	return *this;
}

void	PmergeMe::Vector::Vector::sort()
{
	int					isOdd;
	int					last;

	isOdd = _size % 2;
	divideTwo();
	if (isOdd)
		last = *(--_seq.end());
	sortMainChain(0, _size / 2 - 1);
	sortInsertion();
	if (isOdd)
		insert(_seq, last);

	std::vector<int>::iterator	itr = _seq.begin();
	for (itr = _seq.begin(); itr != _seq.end(); itr++)
		std::cout << *itr << " ";
	std::cout << "\nwell sorted : " << std::boolalpha << isWellSorted(_seq) << std::endl;
}

void	PmergeMe::Vector::divideTwo()
{
	unsigned int	idx = 0;
	unsigned int	size = _size / 2 * 2;

	while (idx < size)
	{
		if (_seq[idx] < _seq[idx + 1])
			swap(_seq[idx], _seq[idx + 1]);
		idx += 2;
	}
}

void	PmergeMe::Vector::sortMainChain(int start, int end)
{
	if (start >= end)
		return ;

	int	mid = (end + start) / 2;

	sortMainChain(start, mid);
	sortMainChain(mid + 1, end);
	sortMerge(start, mid, end);
}

void	PmergeMe::Vector::sortMerge(int start, int mid, int end)
{
	int	i, j, k, l;
	std::vector<int>	sorted(_seq);

	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (_seq[i * 2] < _seq[j * 2])
		{
			sorted[k * 2] = _seq[i * 2];
			sorted[k++ * 2 + 1] = _seq[i++ * 2 + 1];
		}
		else
		{
			sorted[k * 2] = _seq[j * 2];
			sorted[k++ * 2 + 1] = _seq[j++ * 2 + 1];
		}
	}
	l = i <= mid ? i : j;
	while (k <= end)
	{
		sorted[k * 2] = _seq[l * 2];
		sorted[k++ * 2 + 1] = _seq[l++ * 2 + 1];
	}
	_seq = sorted;
}

std::vector<int>	PmergeMe::Vector::makeMainChain()
{
	std::vector<int>	mainChain;
	std::vector<int>::iterator	itr;
	std::vector<int>::iterator	end = _seq.end();

	if (_size % 2)
		end--;
	for (itr = _seq.begin(); itr != end; itr += 2)
		mainChain.push_back(*itr);
	return mainChain;
}

void	PmergeMe::Vector::insert(std::vector<int>& seq, const int& value)
{
	std::vector<int>::iterator itr;

	itr = seq.begin() + searchBinary(seq, value);
	seq.insert(itr, value);
}

void	PmergeMe::Vector::setNextIndex(int& index, int JacobstalNumbers[], const int& n)
{
	index--;
	if (index + 1 != JacobstalNumbers[0] || _size / 2 <= JacobstalNumbers[1])
		return ;
	JacobstalNumbers[0] = JacobstalNumbers[1];
	JacobstalNumbers[1] = getJacobstalNumber(JacobstalNumbers[1], n);
	index = JacobstalNumbers[1] - 1;
	if (_size / 2 <= JacobstalNumbers[1])
		index = _size / 2 - 1;
}

void	PmergeMe::Vector::sortInsertion()
{
	int	idx = 0;
	int	n = 2;
	int	JacobstalNumbers[2];
	std::vector<int>	sorted = makeMainChain();

	JacobstalNumbers[0] = 0;
	JacobstalNumbers[1] = 1;
	while (idx + 1 != JacobstalNumbers[0])
	{
		insert(sorted, _seq[idx * 2 + 1]);
		setNextIndex(idx, JacobstalNumbers, n++);
	}
	_seq = sorted;
}

int	PmergeMe::Vector::getJacobstalNumber(const int& prev, const int& n)
{
	return pow(2, n) - prev;
}

int	PmergeMe::Vector::searchBinary(const std::vector<int>& sorted, const int& value)
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