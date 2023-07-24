#include "Sed.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		Sed::displayManual();
		return 1;
	}
	std::string	stringValue[3] = {argv[1], argv[2], argv[3]};
	Sed	sed(stringValue[0], stringValue[1], stringValue[2]);
	sed.execute();
	return 0;
}

