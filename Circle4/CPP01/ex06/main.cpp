#include "Harl.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc == 1)
		return 1;
	harl.complain(std::string(argv[1]));
	return 0;
}