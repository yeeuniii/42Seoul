#include "PmergeMe.hpp"
#include <iostream>


int	main(int argc, char* argv[])
{
	try
	{
		if (argc == 1)
			throw (std::invalid_argument("Error: enter at least one number."));

		std::vector<int> seq = setSequence<std::vector<int> >(static_cast<int>(argc - 1), const_cast<const char**>(argv + 1));	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}