#include "RPN.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: reverse polish mathematical expression required." << std::endl;
		return 1;
	}

	std::cout << RPN::run(argv[1]) << std::endl;
	return 0;	
}