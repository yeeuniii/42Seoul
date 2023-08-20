#include <iostream>
#include "Bureaucrat.hpp"

void	testConstructor()
{
	std::cout << "----------Basic Test----------" << std::endl;
	{
		try
		{
			Bureaucrat basic("basic", 150);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----------High Test----------" << std::endl;
	{
		try
		{
			Bureaucrat high("high", 151);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----------Low Test----------" << std::endl;
	{
		try
		{
			Bureaucrat low("low", 0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}

void	testIncrementGrade()
{
	std::cout << "----------Normal----------" << std::endl;
	{
		try
		{
			Bureaucrat one("one", 3);

			one.incrementGrade(1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----------Handle exception----------" << std::endl;
	{
		try
		{
			Bureaucrat one("one", 3);

			one.incrementGrade(3);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}	
	std::cout << std::endl;
}

void	testDecrementGrade()
{
	std::cout << "----------Normal----------" << std::endl;
	{
		try
		{
			Bureaucrat one("one", 140);

			one.decrementGrade(5);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----------Handle exception----------" << std::endl;
	{
		try
		{
			Bureaucrat one("one", 149);

			one.decrementGrade(5);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}	
	std::cout << std::endl;
}
int main()
{
	std::cout << "1. Construct" << std::endl;
	testConstructor();
	std::cout << std::endl;
	std::cout << "2. Increment grade" << std::endl;
	testIncrementGrade();
	std::cout << std::endl;
	std::cout << "3. Decrement grade" << std::endl;
	testDecrementGrade();
	std::cout << std::endl;
	return 0;
}