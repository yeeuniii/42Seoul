#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <string>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
private:
	struct Element
	{
		int number;
		int index;

		Element();
		Element(int number, int index);
		Element(const Element& other);
		Element& operator=(const Element& other);
		~Element();

		void swap(Element& other);
	};

	void sortMainchain(std::vector<Element>& seq);
	void insertLast(bool isOdd, std::vector<Element>& mainchain, const Element& element);
	void sortPendingElements(std::vector<Element>& mainchain, std::vector<Element>& pending);
	Element getMatchingElement(int index, std::vector<Element>& pending);
	void sortFordJohnson(std::vector<Element>& mainchain, std::vector<Element>& pending);
	void insert(std::vector<Element>& seq, const Element& value);
	int	searchBinary(const std::vector<Element>& sorted, const int& value);
	
	void sortMainchain(std::deque<Element>& seq);
	void insertLast(bool isOdd, std::deque<Element>& mainchain, const Element& element);
	void sortPendingElements(std::deque<Element>& mainchain, std::deque<Element>& pending);
	Element getMatchingElement(int index, std::deque<Element>& pending);
	void sortFordJohnson(std::deque<Element>& mainchain, std::deque<Element>& pending);
	void insert(std::deque<Element>& seq, const Element& value);
	int	searchBinary(const std::deque<Element>& sorted, const int& value);
	
	void setNextIndex(int& index, const int& size, int JacobstalNumbers[], const int& n);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	std::vector<int> sort(const std::vector<int> &seq);
	std::deque<int> sort(const std::deque<int> &seq);
};

bool isPositiveIntString(std::string string);
int convertInteger(std::string string);
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