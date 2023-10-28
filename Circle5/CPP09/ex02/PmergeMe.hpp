#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <string>
#include <vector>
#include <ctime>

class PmergeMe
{
private:
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	~PmergeMe();

	void sort(std::vector<int> seq);
};

bool	isPositiveIntString(std::string string);
int		convertInteger(std::string string);

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