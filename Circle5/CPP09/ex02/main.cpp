#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int	main(int argc, char* argv[])
{
	try
	{
		if (argc == 1)
			throw (std::invalid_argument("Error: enter at least one number."));

		std::vector<int> vec = setSequence<std::vector<int> >(static_cast<int>(argc - 1), const_cast<const char**>(argv + 1));
		std::deque<int> deq = setSequence<std::deque<int> >(static_cast<int>(argc - 1), const_cast<const char**>(argv + 1));
		PmergeMe pm;
		
		std::clock_t start, end;
		double vectorTime, dequeTime;

		start = clock();
		std::vector<int> vectorSorted= pm.sort(vec);
		end = clock();
		vectorTime = calculateRunningTime(start, end);
		start = clock();
		std::deque<int> dequeSorted= pm.sort(deq);
		end = clock();
		dequeTime = calculateRunningTime(start, end);
		pm.display(vec, vectorSorted, vectorTime, dequeTime);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}