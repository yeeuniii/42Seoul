#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>

/* struct Element */

PmergeMe::Element::Element() {}

PmergeMe::Element::Element(int number, int index) : number(number), index(index) {}

PmergeMe::Element::Element(const Element& other)
{
	*this = other;
}

PmergeMe::Element& PmergeMe::Element::operator=(const Element& other)
{
	if (this != &other)
	{
		this->number = other.number;
		this->index = other.index;
	}
	return *this;
}

PmergeMe::Element::~Element() {}


/* PmergeMe */

void PmergeMe::Element::swap(Element& other)
{
	std::swap(this->number, other.number);
	std::swap(this->index, other.index);
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pm)
{
	*this = pm;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe &pm)
{
	if (this != &pm)
	{
	}
	return *this;
}


/* vector */

std::vector<int> PmergeMe::sort(const std::vector<int>& seq)
{
	std::vector<Element> mainchain;
	std::vector<Element> pending;
	std::vector<int>::const_iterator itr = seq.begin();
	int idx = 0;
	
	if (seq.size() == 1)
		return seq;	
	while (mainchain.size() < seq.size() / 2)
	{
		Element large(*itr++, idx);
		Element small(*itr++, idx++);

		if (large.number < small.number)
			large.swap(small);
		mainchain.push_back(large);
		pending.push_back(small);
	}
	sortMainchain(mainchain);
	sortPendingElements(mainchain, pending);
	sortFordJohnson(mainchain, pending);
	Element element(*itr, 0);
	insertLast(seq.size() % 2, mainchain, element);
	std::vector<int> sorted;
	for (std::vector<Element>::iterator itr = mainchain.begin(); itr != mainchain.end(); itr++)
		sorted.push_back((*itr).number);
	return sorted;
}

void PmergeMe::sortMainchain(std::vector<Element>& seq)
{
	std::vector<Element> mainchain;
	std::vector<Element> pending;
	std::vector<Element>::const_iterator itr = seq.begin();
	
	if (seq.size() == 1)
		return ;
	while (mainchain.size() < seq.size() / 2)
	{
		Element large((*itr++));
		Element small((*itr++));
		
		if (large.number < small.number)
			large.swap(small);
		mainchain.push_back(large);
		pending.push_back(small);
	}
	sortMainchain(mainchain);
	sortFordJohnson(mainchain, pending);
	insertLast(seq.size() % 2, mainchain, *itr);
	seq = mainchain;
}

void PmergeMe::insertLast(bool isOdd, std::vector<Element>& mainchain, const Element& element)
{
	if (isOdd)
		insert(mainchain, element);
}

void PmergeMe::sortPendingElements(std::vector<Element>& mainchain, std::vector<Element>& pending)
{
	std::vector<Element> tmp;
	std::vector<Element>::iterator itr = mainchain.begin();
	
	for (; itr != mainchain.end(); itr++)
		tmp.push_back(getMatchingElement((*itr).index, pending));
	pending = tmp;
}

PmergeMe::Element PmergeMe::getMatchingElement(int index, std::vector<Element>& pending)
{
	std::vector<Element>::iterator itr = pending.begin();

	while ((*itr).index != index)
		itr++;
	return *itr;
}

void PmergeMe::sortFordJohnson(std::vector<Element>& mainchain, std::vector<Element>& pending)
{
	int	idx = 0;
	int	n = 2;
	int	JacobsthalNumbers[2];

	JacobsthalNumbers[0] = 0;
	JacobsthalNumbers[1] = 1;
	while (idx + 1 != JacobsthalNumbers[0])
	{
		insert(mainchain, pending[idx]);
		setNextIndex(idx, static_cast<int>(pending.size()), JacobsthalNumbers, n++);
	}
}

void PmergeMe::insert(std::vector<Element>& seq, const Element& value)
{
	std::vector<Element>::iterator itr;

	itr = seq.begin() + searchBinary(seq, value.number);
	seq.insert(itr, value);
}

void PmergeMe::setNextIndex(int& index, const int& size, int JacobsthalNumbers[], const int& n)
{
	index--;
	if (index + 1 != JacobsthalNumbers[0] || size <= JacobsthalNumbers[1])
		return ;
	JacobsthalNumbers[0] = JacobsthalNumbers[1];
	JacobsthalNumbers[1] = getJacobsthalNumber(JacobsthalNumbers[1], n);
	index = JacobsthalNumbers[1] - 1;
	if (size <= JacobsthalNumbers[1])
		index = size - 1;
}

int	PmergeMe::searchBinary(const std::vector<Element>& sorted, const int& value)
{
	int size = static_cast<int>(sorted.size());
	int	start = 0;
	int	end = size;
	int	mid = (start + end) / 2;

	while (start < end && sorted[mid].number != value)
	{
		if (value < sorted[mid].number)
			end = mid - 1;
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	if (mid >= size)
		return size;
	return value < sorted[mid].number ? mid : mid + 1;
}


/* deque */

std::deque<int> PmergeMe::sort(const std::deque<int>& seq)
{
	std::deque<Element> mainchain;
	std::deque<Element> pending;
	std::deque<int>::const_iterator itr = seq.begin();
	int idx = 0;

	if (seq.size() == 1)
		return seq;	
	while (mainchain.size() < seq.size() / 2)
	{
		Element large(*itr++, idx);
		Element small(*itr++, idx);

		if (large.number < small.number)
			large.swap(small);
		mainchain.push_back(large);
		pending.push_back(small);
	}
	sortMainchain(mainchain);
	sortPendingElements(mainchain, pending);
	sortFordJohnson(mainchain, pending);
	Element element(*itr, 0);
	insertLast(seq.size() % 2, mainchain, element);
	std::deque<int> sorted;
	for (std::deque<Element>::iterator itr = mainchain.begin(); itr != mainchain.end(); itr++)
		sorted.push_back((*itr).number);
	return sorted;
}

void PmergeMe::sortMainchain(std::deque<Element>& seq)
{
	std::deque<Element> mainchain;
	std::deque<Element> pending;
	std::deque<Element>::const_iterator itr = seq.begin();
	
	if (seq.size() == 1)
		return ;
	while (mainchain.size() < seq.size() / 2)
	{
		Element large((*itr++));
		Element small((*itr++));
		
		if (large.number < small.number)
			large.swap(small);
		mainchain.push_back(large);
		pending.push_back(small);
	}
	sortMainchain(mainchain);
	sortFordJohnson(mainchain, pending);
	insertLast(seq.size() % 2, mainchain, *itr);
	seq = mainchain;
}

void PmergeMe::insertLast(bool isOdd, std::deque<Element>& mainchain, const Element& element)
{
	if (isOdd)
		insert(mainchain, element);
}

void PmergeMe::sortPendingElements(std::deque<Element>& mainchain, std::deque<Element>& pending)
{
	std::deque<Element> tmp;
	std::deque<Element>::iterator itr = mainchain.begin();
	
	for (; itr != mainchain.end(); itr++)
		tmp.push_back(getMatchingElement((*itr).index, pending));
	pending = tmp;
}

PmergeMe::Element PmergeMe::getMatchingElement(int index, std::deque<Element>& pending)
{
	std::deque<Element>::iterator itr = pending.begin();

	while ((*itr).index != index)
		itr++;
	return *itr;
}

void PmergeMe::sortFordJohnson(std::deque<Element>& mainchain, std::deque<Element>& pending)
{
	int	idx = 0;
	int	n = 2;
	int	JacobsthalNumbers[2];

	JacobsthalNumbers[0] = 0;
	JacobsthalNumbers[1] = 1;
	while (idx + 1 != JacobsthalNumbers[0])
	{
		insert(mainchain, pending[idx]);
		setNextIndex(idx, static_cast<int>(pending.size()), JacobsthalNumbers, n++);
	}
}

void PmergeMe::insert(std::deque<Element>& seq, const Element& value)
{
	std::deque<Element>::iterator itr;

	itr = seq.begin() + searchBinary(seq, value.number);
	seq.insert(itr, value);
}

int	PmergeMe::searchBinary(const std::deque<Element>& sorted, const int& value)
{
	int size = static_cast<int>(sorted.size());
	int	start = 0;
	int	end = size;
	int	mid = (start + end) / 2;

	while (start < end && sorted[mid].number != value)
	{
		if (value < sorted[mid].number)
			end = mid - 1;
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	if (mid >= size)
		return size;
	return value < sorted[mid].number ? mid : mid + 1;
}


/* utils */

bool isPositiveIntString(std::string string)
{
	int	idx = 0;
	int	size = string.size();

	if (string == "0" || atol(string.c_str()) > std::numeric_limits<int>::max())
		return false;
	while (idx < size && isdigit(string[idx]))
		idx++;
	return idx == size;
}

int convertInteger(std::string string)
{
	std::stringstream ss(string);
	int num;

	ss >> num;
	return num;
}

int getJacobsthalNumber(const int& prev, const int& n)
{
	return pow(2, n) - prev;
}

double calculateRunningTime(const std::clock_t& start, const std::clock_t& end)
{
	return static_cast<double>(end - start) / 1000.0;
}

void displaySequence(std::vector<int>& seq)
{
	std::vector<int>::iterator itr = seq.begin();

	for (; itr != seq.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

void displaySequence(std::deque<int>& seq)
{
	std::deque<int>::iterator itr = seq.begin();

	for (; itr != seq.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}
