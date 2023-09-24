#include "PmergeMe.hpp"

#include <iostream>

template <typename T>
void	PmergeMe::sortMergeInsertion(T sequence)
{
	pushAll(sequence);
	divide(sequence);
	sortMainChain(sequence, 0, sequence.size() / 2 - 1);
	
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
