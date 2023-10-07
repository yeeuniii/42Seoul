#include "Sed.hpp"
#include <iostream>

void	displayManual()
{
	std::cout << "Enter the following, if you execute replace of sed command.\n"
			<< std::string(44, '-') << "\n"
			<< "| ./sed <filename> <old_value> <new_value> |\n"
			<< std::string(44, '-') << std::endl;
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		displayManual();
		return 1;
	}
	std::string	file_name = argv[1];
	std::string	old_value = argv[2];
	std::string	new_value = argv[3];
	Sed	sed(file_name, old_value, new_value);
	sed.execute();
	return 0;
}

