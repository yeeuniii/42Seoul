#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <string>
#include <vector>

class PmergeMe
{
private:
	std::vector<int> origin;

	PmergeMe();

	void checkArgument(const int &size, const char *argv[]) const;
	void setSequence(const int &size, const char *argv[]);

	class Vector
	{
	private:
		std::vector<int>	_seq;
		int					_size;
		long 				_time;

		Vector();
		
		void divideTwo();
		void sortMainChain(int start, int end);
		void sortMerge(int start, int mid, int end);
		std::vector<int>	makeMainChain();
		void insert(std::vector<int>& _seq, const int& value);
		void sortInsertion();
		void setNextIndex(int &index, int JacobstalNumbers[], const int &n);
		int getJacobstalNumber(const int &prev, const int &n);
		int searchBinary(const std::vector<int>& sorted, const int &value);

	public:
		Vector(const std::vector<int>&);
		Vector(const Vector& vector);
		~Vector();
		Vector&	operator=(const Vector& vector);
		
		void sort();
	};

public:
	PmergeMe(const int &size, const char *argv[]);
	PmergeMe(const PmergeMe &pm);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &pm);

	void	sort();
};

bool isPositiveIntString(std::string string);
void swap(int &front, int &back);

bool isWellSorted(std::vector<int> vector);

#endif