#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <iostream>

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
		double				_time;

		Vector();

		void	divideTwo();
		void	sortMerge(int start, int end);
		void	merge(int start, int mid, int end);
		std::vector<int>	makeMainChain();
		void	insert(std::vector<int>& _seq, const int& value);
		void	sortInsertion();
		void	setNextIndex(int &index, int JacobstalNumbers[], const int &n);
		int		searchBinary(const std::vector<int>& sorted, const int &value);

	public:
		Vector(const std::vector<int>&);
		Vector(const Vector& vector);
		~Vector();
		Vector&	operator=(const Vector& vector);
		
		void	set_time(const std::clock_t& start, const std::clock_t& end);
		std::vector<int>	get_seq() const;
		const int&			get_size() const;
		const double&		get_time() const;

		void sort();
	};
	
	class List
	{
	private:
		std::list<int>	_seq;
		int				_size;
		double			_time;

		List();

		void	divideTwo();
		std::list<int>	sortMerge(std::list<int>& lst);
		std::list<int>	merge(std::list<int> &left, std::list<int> &right);
		void	pushFrontElement(std::list<int>& pushList, std::list<int>& popList, const int& time);
		std::list<int>	makeMainChain();
		void	insert(std::list<int>& _seq, const int& value);
		void	sortInsertion();
		void	setNextIndex(int &index, int JacobstalNumbers[], const int &n);
		int		searchBinary(const std::list<int>& sorted, const int &value);
		int		getElement(std::list<int>& lst, const int& pos);
	
	public:
		List(const std::vector<int>&);
		List(const List& vector);
		~List();
		List&	operator=(const List& vector);

		void	set_time(const std::clock_t& start, const std::clock_t& end);
		std::list<int>	get_seq() const;
		const int&			get_size() const;
		const double&		get_time() const;

		void sort();
	};

	void	display(Vector& vec) const;

public:
	PmergeMe(const int &size, const char *argv[]);
	PmergeMe(const PmergeMe &pm);
	~PmergeMe();
	PmergeMe	&operator=(const PmergeMe &pm);
	
	void	sort();
};

bool	isPositiveIntString(std::string string);
void	swap(int &front, int &back);
int		getJacobstalNumber(const int &prev, const int &n);

template <typename T>
void	displaySequence(T container)
{
	typename T::iterator	itr;

	for (itr = container.begin(); itr != container.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

bool	isWellSorted(std::vector<int> vector);

#endif