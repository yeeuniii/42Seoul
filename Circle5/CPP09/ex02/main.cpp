#include "PmergeMe.hpp"

#include <iostream>
int	main(int argc, char* argv[])
{
	if (argc == 1)
		return 1;	

	try
	{
		PmergeMe	pm(argc - 1, const_cast<const char**>(argv + 1));
	
		pm.sortByVector();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		
	return 0;
}