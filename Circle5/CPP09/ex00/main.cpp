#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	
	try
	{
		BitcoinExchange::run(argv[1]);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}