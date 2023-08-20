#include <iostream>
#include "Bureaucrat.hpp"

int	main()
{
	try 
	{
		Bureaucrat bureaucrat1("name", 150);
		Bureaucrat bureaucrat2(bureaucrat1);
		Bureaucrat bureaucrat3("exception", -151);

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}