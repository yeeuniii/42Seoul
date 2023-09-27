#include "PmergeMe.hpp"
#include <stdexcept>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const int& size, const char* argv[])
{
	checkArgument(size, argv);
	setSequence(size, argv);
}

PmergeMe::PmergeMe(const PmergeMe &pm)
{
	*this = pm;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& pm)
{
	if (this != &pm)
	{
		this->origin.clear();
		std::vector<int>::iterator	itr = this->origin.begin();
		this->origin.insert(itr, pm.origin.begin(), pm.origin.end());
	}
	return *this;
}

/* parsing */

void	PmergeMe::checkArgument(const int& size, const char* argv[]) const
{
	int		idx = 0;
	bool	isValid = true;

	while (isValid && idx < size)
	{
		std::string	argument(argv[idx]);
		isValid = isPositiveIntString(argv[idx]);
		idx++;
	}
	if (isValid == false)
		throw (std::invalid_argument("Error: not a positive integer."));
}

void	PmergeMe::setSequence(const int& size, const char* argv[])
{
	int	num;
	
	for (int idx = 0; idx < size; idx++)
	{
		std::stringstream	ss(argv[idx]);
		ss >> num;
		this->origin.push_back(num);
	}
}

/* sort */

void	PmergeMe::sort()
{
	PmergeMe::Vector	vec(this->origin);
	PmergeMe::List		lst(this->origin);
	std::clock_t		start, end;

	start = clock();
	vec.sort();
	end = clock();
	vec.set_time(start, end);
	lst.sort();
	display(vec);
}

void	PmergeMe::display(Vector& vec) const
{
	std::vector<int>	tmp = this->origin;

	std::cout << "Before:\t";
	displaySequence(this->origin);
	std::cout << "After:\t";
	displaySequence(vec.get_seq());
	std::cout << "Time to process a range of\t" << vec.get_size()
			<< " elements with std::vector : " << vec.get_time() << " us" << std::endl;
}

/* Vector */

PmergeMe::Vector::Vector() {}

PmergeMe::Vector::Vector(const std::vector<int>& origin)
{
	_seq = origin;
	_size = static_cast<int>(_seq.size());
}

PmergeMe::Vector::Vector(const Vector& vector)
{
	*this = vector;
}

PmergeMe::Vector::~Vector() {}

PmergeMe::Vector&	PmergeMe::Vector::operator=(const Vector& vector)
{
	if (this != &vector)
	{
		_seq = vector._seq;
		_size = vector._size;
		_time = vector._time;
	}
	return *this;
}

void	PmergeMe::Vector::set_time(const std::clock_t& start, const std::clock_t& end)
{
	this->_time = static_cast<double>(end - start) / 1000.0;
}

std::vector<int>	PmergeMe::Vector::get_seq()
{
	return this->_seq;
}

const int&	PmergeMe::Vector::get_size()
{
	return this->_size;
}

const double&	PmergeMe::Vector::get_time()
{
	return this->_time;
}

void	PmergeMe::Vector::sort()
{
	int	isOdd = _size % 2;
	int	last;

	if (_size == 1)
		return ;
	divideTwo();
	if (isOdd)
		last = *(--_seq.end());
	sortMerge(0, _size / 2 - 1);
	sortInsertion();
	if (isOdd)
		insert(_seq, last);
}

void	PmergeMe::Vector::divideTwo()
{
	unsigned int	idx = 0;
	unsigned int	size = _size / 2 * 2;

	while (idx < size)
	{
		if (_seq[idx] < _seq[idx + 1])
			swap(_seq[idx], _seq[idx + 1]);
		idx += 2;
	}
}

void	PmergeMe::Vector::sortMerge(int start, int end)
{
	if (start >= end)
		return ;

	int	mid = (end + start) / 2;

	sortMerge(start, mid);
	sortMerge(mid + 1, end);
	merge(start, mid, end);
}

void	PmergeMe::Vector::merge(int start, int mid, int end)
{
	int	i, j, k, l;
	std::vector<int>	sorted(_seq);

	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (_seq[i * 2] < _seq[j * 2])
		{
			sorted[k * 2] = _seq[i * 2];
			sorted[k++ * 2 + 1] = _seq[i++ * 2 + 1];
		}
		else
		{
			sorted[k * 2] = _seq[j * 2];
			sorted[k++ * 2 + 1] = _seq[j++ * 2 + 1];
		}
	}
	l = i <= mid ? i : j;
	while (k <= end)
	{
		sorted[k * 2] = _seq[l * 2];
		sorted[k++ * 2 + 1] = _seq[l++ * 2 + 1];
	}
	_seq = sorted;
}

std::vector<int>	PmergeMe::Vector::makeMainChain()
{
	std::vector<int>	mainChain;
	std::vector<int>::iterator	itr;
	std::vector<int>::iterator	end = _seq.end();

	if (_size % 2)
		end--;
	for (itr = _seq.begin(); itr != end; itr += 2)
		mainChain.push_back(*itr);
	return mainChain;
}

void	PmergeMe::Vector::insert(std::vector<int>& seq, const int& value)
{
	std::vector<int>::iterator itr;

	itr = seq.begin() + searchBinary(seq, value);
	seq.insert(itr, value);
}

void	PmergeMe::Vector::setNextIndex(int& index, int JacobstalNumbers[], const int& n)
{
	index--;
	if (index + 1 != JacobstalNumbers[0] || _size / 2 <= JacobstalNumbers[1])
		return ;
	JacobstalNumbers[0] = JacobstalNumbers[1];
	JacobstalNumbers[1] = getJacobstalNumber(JacobstalNumbers[1], n);
	index = JacobstalNumbers[1] - 1;
	if (_size / 2 <= JacobstalNumbers[1])
		index = _size / 2 - 1;
}

void	PmergeMe::Vector::sortInsertion()
{
	int	idx = 0;
	int	n = 2;
	int	JacobstalNumbers[2];
	std::vector<int>	sorted = makeMainChain();

	JacobstalNumbers[0] = 0;
	JacobstalNumbers[1] = 1;
	while (idx + 1 != JacobstalNumbers[0])
	{
		insert(sorted, _seq[idx * 2 + 1]);
		setNextIndex(idx, JacobstalNumbers, n++);
	}
	_seq = sorted;
}

int	PmergeMe::Vector::searchBinary(const std::vector<int>& sorted, const int& value)
{
	int	start = 0;
	int	end = static_cast<int>(sorted.size());
	int	mid = (start + end) / 2;

	while (start < end && sorted[mid] != value)
	{
		if (value < sorted[mid])
			end = mid - 1;
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	if (start >= end)
		return mid;
	return value < sorted[mid] ? mid : mid + 1;
}

/* List */

PmergeMe::List::List() {}

PmergeMe::List::List(const std::vector<int>& origin)
{
	_seq.insert(_seq.begin(), origin.begin(), origin.end());
	_size = static_cast<int>(_seq.size());
}

PmergeMe::List::List(const List& list)
{
	*this = list;
}

PmergeMe::List::~List() {}

PmergeMe::List&	PmergeMe::List::operator=(const List& list)
{
	if (this != &list)
	{
		_seq = list._seq;
		_size = list._size;
		_time = list._time;
	}
	return *this;
}

void	PmergeMe::List::set_time(const std::clock_t& start, const std::clock_t& end)
{
	this->_time = static_cast<double>(end - start) / 1000.0;
}

std::list<int>	PmergeMe::List::get_seq() const
{
	return this->_seq;
}

const int&	PmergeMe::List::get_size() const
{
	return this->_size;
}

const double&	PmergeMe::List::get_time() const
{
	return this->_time;
}

void	PmergeMe::List::sort()
{
	int	isOdd = _size % 2;
	int	last;

	if (_size == 1)
		return ;
	if (isOdd)
		last = *(--_seq.end());
	divideTwo();	
	_seq = sortMerge(_seq);
	sortInsertion();
	if (isOdd)
		insert(_seq, last);
}

void	PmergeMe::List::divideTwo()
{
	std::list<int>				lst;
	std::list<int>::iterator	itr;
	int		first, second;

	for (itr = _seq.begin(); lst.size() < _seq.size() / 2 * 2; itr++)
	{
		first = *(itr++);
		second = *itr;
		if (first < second)
			swap(first, second);
		lst.push_back(first);
		lst.push_back(second);
	}
	_seq = lst;
}

std::list<int>	PmergeMe::List::sortMerge(std::list<int>& lst)
{
	if (lst.size() <= 2)
		return lst;

	std::list<int> left, right, sorted;
	std::list<int>::iterator	itr = lst.begin();
	int size = static_cast<int>(lst.size());
	int	idx = 0;

	for (; idx < size / 2; idx += 2)
	{
		left.push_back(*(itr++));
		left.push_back(*(itr++));
	}
	for (; idx < size; idx += 2)
	{
		right.push_back(*(itr++));
		right.push_back(*(itr++));
	}
	left = sortMerge(left);
	right = sortMerge(right);
	sorted = merge(left, right);
	return sorted;
}

std::list<int>	PmergeMe::List::merge(std::list<int> &left, std::list<int> &right)
{
	std::list<int> sorted;

	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
			pushFrontElement(sorted, left, 2);
		else
			pushFrontElement(sorted, right, 2);
	}
	while (!left.empty())
		pushFrontElement(sorted, left, 2);
	while (!right.empty())
		pushFrontElement(sorted, right, 2);
	return sorted;
}

void	PmergeMe::List::pushFrontElement(std::list<int>& pushList, std::list<int>& popList, const int& time)
{
	int	idx = 0;

	while (idx < time)
	{
		pushList.push_back(popList.front());
		popList.pop_front();
		idx++;
	}
}

std::list<int> PmergeMe::List::makeMainChain()
{
	std::list<int> mainChain;
	std::list<int>::iterator itr = _seq.begin();

	for (int idx = 0; idx < _size / 2; idx++)
	{
		mainChain.push_back(*(itr++));
		itr++;
	}
	return mainChain;
}

void PmergeMe::List::insert(std::list<int> &seq, const int &value)
{
	std::list<int>::iterator itr = seq.begin();
	int	pos = searchBinary(seq, value);

	for (int idx = 0; idx < pos; idx++)
		itr++;
	seq.insert(itr, value);
}

void PmergeMe::List::setNextIndex(int &index, int JacobstalNumbers[], const int &n)
{
	index--;
	if (index + 1 != JacobstalNumbers[0] || _size / 2 <= JacobstalNumbers[1])
		return;
	JacobstalNumbers[0] = JacobstalNumbers[1];
	JacobstalNumbers[1] = getJacobstalNumber(JacobstalNumbers[1], n);
	index = JacobstalNumbers[1] - 1;
	if (_size / 2 <= JacobstalNumbers[1])
		index = _size / 2 - 1;
}

void PmergeMe::List::sortInsertion()
{
	int idx = 0;
	int n = 2;
	int JacobstalNumbers[2];
	std::list<int> sorted = makeMainChain();

	JacobstalNumbers[0] = 0;
	JacobstalNumbers[1] = 1;
	while (idx + 1 != JacobstalNumbers[0])
	{
		insert(sorted, getElement(_seq, idx * 2 + 1));
		setNextIndex(idx, JacobstalNumbers, n++);
	}
	_seq = sorted;
}

int PmergeMe::List::searchBinary(const std::list<int> &sorted, const int &value)
{
	int	start = 0;
	int	end = static_cast<int>(sorted.size());
	int	mid = (start + end) / 2;
	int	midValue = getElement(const_cast<std::list<int>&>(sorted), mid);

	while (start < end && midValue != value)
	{
		if (value < midValue)
			end = mid - 1;
		else
			start = mid + 1;
		mid = (start + end) / 2;
		midValue = getElement(const_cast<std::list<int>&>(sorted), mid);
	}
	return value < midValue ? mid : mid + 1;
}

int	PmergeMe::List::getElement(std::list<int>& lst, const int& pos) 
{
	std::list<int>::iterator	itr = lst.begin();

	for (int idx = 0; idx < pos; idx++)
		itr++;
	return *itr;
}

		
/* util functions */

bool	isPositiveIntString(std::string string)
{
	int	idx = 0;
	int	size = string.size();

	if (string == "0" || atol(string.c_str()) > std::numeric_limits<int>::max())
		return false;
	while (idx < size && isdigit(string[idx]))
		idx++;
	return idx == size;
}

void	swap(int& first, int& last)
{
	int	tmp = first;

	first = last;
	last = tmp;
}

int		getJacobstalNumber(const int& prev, const int& n)
{
	return pow(2, n) - prev;
}



bool	isWellSorted(std::vector<int> vector)
{
	std::vector<int>::iterator	itr = vector.begin();
	int	prev = *itr;

	while (++itr != vector.end() && *itr >= prev)
		prev = *itr;
	return itr == vector.end();
}