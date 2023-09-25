#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <string>
#include <vector>

class PmergeMe
{
	private:
		std::vector<int>	seq;
		
		PmergeMe();
		
		void	checkargument(const int& size, const char* argv[]) const;
		void	setSequence(const int& size, const char* argv[]);
		
	public:
		PmergeMe(const int& size, const char* argv[]);
		PmergeMe(const PmergeMe& pm);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& pm);
};

bool	isPositiveIntString(std::string string);
void	swap(int& front, int& back);

// #include "PmergeMe.tpp"

#endif