#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <string>
#include <vector>
#include <ctime>

struct Element
{
	int number;
	int index;

	Element(int number, int index) : number(number), index(index) {}

	Element(const Element& other)
	{
		this->number = other.number;
		this->index = other.index;
	}

	void swap(Element& other)
	{
		std::swap(this->number, other.number);
		std::swap(this->index, other.index);
	}
};

class PmergeMe
{
private:
	void sortMainchain(std::vector<Element>& seq);
	void sortPendingElements(std::vector<Element>& mainchain, std::vector<Element>& pending);
	Element getMatchingElement(int index, std::vector<Element>& pending);
	void sortFordJohnson(std::vector<Element>& mainchain, std::vector<Element>& pending);
	void insert(std::vector<Element>& seq, const Element& value);
	void setNextIndex(int& index, const int& size, int JacobstalNumbers[], const int& n);
	int	searchBinary(const std::vector<Element>& sorted, const int& value);
	// std::pair<int, int> makePair(int num1, int num2);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	std::vector<int> sort(const std::vector<int> &seq);
};

bool isPositiveIntString(std::string string);
int convertInteger(std::string string);
// void swap(int &first, int &last);
int getJacobsthalNumber(const int& prev, const int& n);

template <typename T>
T setSequence(const unsigned int &size, const char *argv[])
{
	T seq;
	bool isValid = true;

	while (isValid && seq.size() < size)
	{
		isValid = isPositiveIntString(*argv);
		seq.push_back(convertInteger(*argv));
		argv++;
	}
	if (isValid == false)
		throw(std::invalid_argument("Error: not a positive integer."));
	return seq;
}

#endif