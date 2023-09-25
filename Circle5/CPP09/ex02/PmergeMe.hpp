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
		
		void	divideTwo(std::vector<int>& vec);
		void	sortMainChain(std::vector<int>& vec, int start, int end);
		void	sortMerge(std::vector<int>& vec, int start, int mid, int end);
		void	insert(std::vector<int>& vec);
		int		searchBinary(const std::vector<int>& sorted, const int& value);

	public:
		PmergeMe(const int& size, const char* argv[]);
		PmergeMe(const PmergeMe& pm);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& pm);
		
		void	sortByVector();
};

bool	isPositiveIntString(std::string string);
void	swap(int& front, int& back);

#endif