#include "RPN.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: reverse polish mathematical expression required." << std::endl;
		return 1;
	}

	try
	{
		std::cout << RPN::getSolution(argv[1]) << std::endl;
	}
	catch(std::exception& e)
	{
	 	std::cout << e.what() << std::endl;
	}
	return 0;	
}