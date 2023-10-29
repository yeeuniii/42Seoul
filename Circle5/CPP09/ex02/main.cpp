#include "PmergeMe.hpp"
#include <iostream>

#include <algorithm>


int	main(int argc, char* argv[])
{
	try
	{
		if (argc == 1)
			throw (std::invalid_argument("Error: enter at least one number."));

		std::vector<int> vec = setSequence<std::vector<int> >(static_cast<int>(argc - 1), const_cast<const char**>(argv + 1));
		std::deque<int> deq = setSequence<std::deque<int> >(static_cast<int>(argc - 1), const_cast<const char**>(argv + 1));
		PmergeMe pm;

		std::vector<int> sortedVector= pm.sort(vec);
		std::deque<int> sortedDeque= pm.sort(deq);

		std::cout << "vector is well sorted : " << std::boolalpha << std::is_sorted(sortedVector.begin(), sortedVector.end()) << std::endl;
		std::cout << "deque is well sorted : " << std::boolalpha << std::is_sorted(sortedDeque.begin(), sortedDeque.end()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}