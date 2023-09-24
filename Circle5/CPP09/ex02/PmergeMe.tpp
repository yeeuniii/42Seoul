#include "PmergeMe.hpp"

#include <iostream>

template <typename T>
void	PmergeMe::sortMergeInsertion(T sequence)
{
	pushAll(sequence);
	divide(sequence);
	sortMainChain(sequence, 0, sequence.size() / 2 - 1);
	insert(sequence);

	typename T::iterator itr;  
	std::cout << "sequence" << std::endl;
	for (itr = sequence.begin(); itr != sequence.end(); itr++)
		std::cout << *itr << std::endl;
}

template <typename T>
void	PmergeMe::pushAll(T& sequence)
{

	for (unsigned int idx = 0; idx < this->size; idx++)
		sequence.push_back(this->seq[idx]);
}

template <typename T>
void	PmergeMe::divide(T& sequence)
{
	unsigned int		idx = 0;

	while (idx < sequence.size() / 2 * 2)
	{
		if (sequence[idx] < sequence[idx + 1])
			swap(sequence[idx], sequence[idx + 1]);
		idx += 2;
	}
}

template <typename T>
void	PmergeMe::sortMainChain(T& sequence, int start, int end)
{
	if (start >= end)
		return ;

	int	mid = (end + start) / 2;

	sortMainChain(sequence, start, mid);
	sortMainChain(sequence, mid + 1, end);
	sortMerge(sequence, start, mid, end);
}

template <typename T>
void	PmergeMe::sortMerge(T& sequence, int start, int mid, int end)
{
	int			i = start;
	int			j = mid + 1;
	int			k = start;
	T			sorted(sequence);

	while (i <= mid && j <= end)
	{
		if (sorted[i * 2] < sorted[j * 2])
		{
			sorted[k * 2] = sequence[i * 2];
			sorted[k++ * 2 + 1] = sequence[i++ * 2 + 1];
		}
		else
		{
			sorted[k * 2] = sequence[j * 2];
			sorted[k++ * 2 + 1] = sequence[j++ * 2 + 1];
		}
	}
	int	l = i <= mid ? i : j;	
	while (k <= end)
	{
		sorted[k * 2] = sequence[l * 2];
		sorted[k++ * 2 + 1] = sequence[l++ * 2 + 1];
	}
	sequence = sorted;
}

template <typename T>
T	PmergeMe::makeMainChain(T& sequence)
{
	unsigned int	idx = 0;
	T				mainChain;

	while (idx < sequence.size() / 2 * 2)
	{
		mainChain.push_back(sequence[idx]);
		idx += 2;
	}
	return mainChain;
}

template <typename T>
void	PmergeMe::insert(T& sequence)
{
	int	idx = 0;
	int	size = static_cast<int>(sequence.size()) / 2;
	T	sorted = makeMainChain(sequence);

	while (idx < size)
	{
		int			value = sequence[idx * 2 + 1];
		typename T::iterator	itr = sorted.begin();

		itr += searchBinary(sorted, value);
		sorted.insert(itr, value);
		idx++;
	}
	sequence = sorted;
}

template <typename T>
int		PmergeMe::searchBinary(T& sorted, const int& value)
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
