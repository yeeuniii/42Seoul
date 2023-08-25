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
	static ScalarConverter converter(argv[1]);

	// std::cout << argv[1] << " : " << converter.getType() << std::endl;
	
	converter.convertScalar();
	converter.display();

	return 0;
}