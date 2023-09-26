#include "PmergeMe.hpp"

#include <iostream>
int	main(int argc, char* argv[])
{
	try
	{
		if (argc == 1)
			throw (std::invalid_argument("Error: enter at least one number."));

		PmergeMe	pm(argc - 1, const_cast<const char**>(argv + 1));
	
		pm.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}