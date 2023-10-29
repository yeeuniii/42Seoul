#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>

#include <iostream>
#include <stdio.h>

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

std::vector<int> PmergeMe::sort(const std::vector<int>& seq)
{
	std::vector<Element> mainchain;
	std::vector<Element> pending;
	std::vector<int>::const_iterator itr = seq.begin();
	int idx = 0;

	if (seq.size() == 1)
		return seq;	
	while (mainchain.size() < seq.size() / 2)
	{
		int large = *(itr++);
		int small = *(itr++);
		if (large < small)
			std::swap(large, small);
		Element element(large, idx++);
		mainchain.push_back(element);
		element.number = small;
		pending.push_back(element);
	}
	sortMainchain(mainchain);
	sortPendingElements(mainchain, pending);
	sortFordJohnson(mainchain, pending);
	if (seq.size() % 2)
	{
		Element element(*itr, 0);
		insert(mainchain, element);
	}
	std::vector<int> sorted;
	for (std::vector<Element>::iterator itr = mainchain.begin(); itr != mainchain.end(); itr++)
		sorted.push_back((*itr).number);
	return sorted;
}

void PmergeMe::sortMainchain(std::vector<Element>& seq)
{
	if (seq.size() == 1)
		return ;

	std::vector<Element> mainchain;
	std::vector<Element> pending;
	std::vector<Element>::const_iterator itr = seq.begin();
	
	while (mainchain.size() < seq.size() / 2)
	{
		Element large((*itr++));
		Element small((*itr++));
		
		if (large.number < small.number)
			large.swap(small);
		mainchain.push_back(large);
		pending.push_back(small);
	}
	sortMainchain(mainchain);
	sortFordJohnson(mainchain, pending);
	if (seq.size() % 2) {
		insert(mainchain, *itr);
	}
	seq = mainchain;
}

void PmergeMe::sortPendingElements(std::vector<Element>& mainchain, std::vector<Element>& pending)
{
	std::vector<Element> tmp;
	std::vector<Element>::iterator itr = mainchain.begin();
	
	while (itr != mainchain.end())
	{
		tmp.push_back(getMatchingElement((*itr).index, pending));
		itr++;
	}
	pending = tmp;
}

Element PmergeMe::getMatchingElement(int index, std::vector<Element>& pending)
{
	std::vector<Element>::iterator itr = pending.begin();

	while ((*itr).index != index)
		itr++;
	return *itr;
}

void PmergeMe::sortFordJohnson(std::vector<Element>& mainchain, std::vector<Element>& pending)
{
	int	idx = 0;
	int	n = 2;
	int	JacobsthalNumbers[2];

	JacobsthalNumbers[0] = 0;
	JacobsthalNumbers[1] = 1;
	while (idx + 1 != JacobsthalNumbers[0])
	{
		insert(mainchain, pending[idx]);
		setNextIndex(idx, static_cast<int>(pending.size()), JacobsthalNumbers, n++);
	}
}

void PmergeMe::insert(std::vector<Element>& seq, const Element& value)
{
	std::vector<Element>::iterator itr;

	itr = seq.begin() + searchBinary(seq, value.number);
	seq.insert(itr, value);
}

void PmergeMe::setNextIndex(int& index, const int& size, int JacobsthalNumbers[], const int& n)
{
	index--;
	if (index + 1 != JacobsthalNumbers[0] || size <= JacobsthalNumbers[1])
		return ;
	JacobsthalNumbers[0] = JacobsthalNumbers[1];
	JacobsthalNumbers[1] = getJacobsthalNumber(JacobsthalNumbers[1], n);
	index = JacobsthalNumbers[1] - 1;
	if (size <= JacobsthalNumbers[1])
		index = size - 1;
}

int	PmergeMe::searchBinary(const std::vector<Element>& sorted, const int& value)
{
	int	start = 0;
	int	end = static_cast<int>(sorted.size());
	int	mid = (start + end) / 2;

	while (start < end && sorted[mid].number != value)
	{
		if (value < sorted[mid].number)
			end = mid - 1;
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	int size = static_cast<int>(sorted.size());
	if (mid >= size)
		return size;
	return value < sorted[mid].number ? mid : mid + 1;
}

std::pair<int, int> makePair(int num1, int num2)
{
	std::pair<int, int> pair;
	int large = num1;
	int small = num2;

	if (num2 > num1)
	{
		large = num2;
		small = num1;
	}
	pair.first = large;
	pair.second = small;
	return pair;
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

// void	swap(int& first, int& last)
// {
// 	int	tmp = first;

// 	first = last;
// 	last = tmp;
// }

int		getJacobsthalNumber(const int& prev, const int& n)
{
	return pow(2, n) - prev;
}