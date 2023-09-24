#include "PmergeMe.hpp"
#include <cstdlib>
#include <vector>

int	main(int argc, char* argv[])
{
	if (argc == 1)
		return 1;	
	
	PmergeMe	pm(argc - 1, const_cast<const char**>(argv + 1));
	
	std::vector<int> vec;
	pm.sortMergeInsertion(vec);

	// system("leaks PmergeMe");
	return 0;
}