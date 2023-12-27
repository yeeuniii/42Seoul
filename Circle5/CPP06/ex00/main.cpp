#include <iostream>
#include "ScalarConverter.hpp"

int	displayManual()
{
	std::cout << "./convert <string representation of a C++ literal>" << std::endl
			<< "This literal must be one of scalar types(char, int, float, double)" << std::endl;
	return 1;
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return displayManual();
	
	ScalarConverter::convert(argv[1]);
	return 0;
}