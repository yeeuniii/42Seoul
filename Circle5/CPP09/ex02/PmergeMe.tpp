#include "PmergeMe.hpp"

#include <iostream>

template <typename T>
void	PmergeMe::sortMergeInsertion(T sequence)
{
	pushAll(sequence);
	divide(sequence);
	// makeMainChain(sequence);
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
	int		idx = 0;
	bool	isOdd = sequence.size() % 2;

	while (idx + static_cast<int>(isOdd) < static_cast<int>(sequence.size()))
	{
		if (sequence[idx] < sequence[idx + 1])
			swap(sequence[idx], sequence[idx + 1]);
		idx += 2;
	}
}

// template <typename T>
// void	PmergeMe::makeMainChain()
// {

// }