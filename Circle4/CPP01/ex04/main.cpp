#include "Sed.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		Sed::displayManual();
		return 1;
	}
	std::string	file_name = argv[1];
	std::string	old_value = argv[2];
	std::string	new_value = argv[3];
	Sed	sed(file_name, old_value, new_value);
	sed.execute();
	return 0;
}

