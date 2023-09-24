#include "PmergeMe.hpp"

#include <iostream>

template <typename T>
void	PmergeMe::sortMergeInsertion(T sequence)
{
	pushAll(sequence);
	divide(sequence);
	T	mainChain = makeMainChain(sequence);
	sortMainChain(sequence, mainChain, 0, mainChain.size() - 1);
	
	typename T::iterator itr;  
	std::cout << "main chain" << std::endl;
	for (itr = mainChain.begin(); itr != mainChain.end(); itr++)
		std::cout << *itr << std::endl;
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
T	PmergeMe::makeMainChain(T& sequence)
{
	T				mainChain;
	unsigned int	idx = 0;

	while (idx < sequence.size() / 2 * 2)
	{
		mainChain.push_back(sequence[idx]);
		idx += 2;
	}
	return mainChain;
}

template <typename T>
void	PmergeMe::sortMainChain(T& sequence, T& mainChain, int start, int end)
{
	if (start >= end)
		return ;

	int	mid = (end + start) / 2;

	sortMainChain(sequence, mainChain, start, mid);
	sortMainChain(sequence, mainChain, mid + 1, end);
	sortMerge(sequence, mainChain, start, mid, end);
}

template <typename T>
void	PmergeMe::sortMerge(T& sequence, T& mainChain, int start, int mid, int end)
{
	int			i = start;
	int			j = mid + 1;
	int			k = start;
	T			sorted(sequence);
	T			sortedChain(mainChain);

	while (i <= mid && j <= end)
	{
		if (mainChain[i] < mainChain[j])
		{
			sorted[k * 2] = sequence[i * 2];
			sorted[k * 2 + 1] = sequence[i * 2 + 1];
			sortedChain[k++] = mainChain[i++];
		}
		else
		{
			sorted[k * 2] = sequence[j * 2];
			sorted[k * 2 + 1] = sequence[j * 2 + 1];
			sortedChain[k++] = mainChain[j++];
		}
	}

	int	l = i <= mid ? i : j;	
	while (k <= end)
	{
		sorted[k * 2] = sequence[l * 2];
		sorted[k * 2 + 1] = sequence[l * 2 + 1];
		sortedChain[k++] = mainChain[l++];
	}
	mainChain = sortedChain;
	sequence = sorted;
}
