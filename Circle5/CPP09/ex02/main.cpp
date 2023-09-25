#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	if (argc == 1)
		return 1;	
	
	PmergeMe	pm(argc - 1, const_cast<const char**>(argv + 1));
	
	pm.sortByVector();
	return 0;
}