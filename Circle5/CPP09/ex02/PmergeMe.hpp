#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <string>

class PmergeMe
{
	private:
		int				*seq;
		unsigned int	size;
		
		PmergeMe();
		
		void	checkargument(const int& size, const char* argv[]) const;
		void	setSequence(const int& size, const char* argv[]);
		
		template <typename T>
		void	pushAll(T& sequence);
		template <typename T>
		void	divide(T& sequence);
		template <typename T>
		T	makeMainChain(T& sequence);
		template <typename T>
		void	sortMerge(T& sequence, T& mainChahin, int start, int mid, int end);
		template <typename T>
		void	sortMainChain(T& sequence, T& mainChain, int start, int end);

	public:
		PmergeMe(const int& size, const char* argv[]);
		PmergeMe(const PmergeMe& pm);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& pm);

		template <typename T>
		void	sortMergeInsertion(T sequence);
};

bool	isPositiveIntString(std::string string);
void	swap(int& front, int& back);

#include "PmergeMe.tpp"

#endif