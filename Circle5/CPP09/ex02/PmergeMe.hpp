#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <string>

class PmergeMe
{
	private:
		int				*seq;
		unsigned int	size;
		
		PmergeMe();

	public:
		PmergeMe(const int& size, const char* argv[]);
		PmergeMe(const PmergeMe& pm);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& pm);

		void	checkargument(const int& size, const char* argv[]) const;
		void	setSequence(const int& size, const char* argv[]);

		template <typename T>
		void	sortMergeInsertion(T sequence);
		template <typename T>
		void	pushAll(T& sequence);
		template <typename T>
		void	divide(T& sequence);
		template <typename T>
		void	makeMainChain();
};

bool	isPositiveIntString(std::string string);
void	swap(int& front, int& back);

#include "PmergeMe.tpp"

#endif