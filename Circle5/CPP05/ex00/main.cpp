#include <iostream>
#include "Bureaucrat.hpp"

void	testConstructor()
{
	std::cout << "----------Basic Test----------" << std::endl;
	{
		try
		{
			Bureaucrat basic("basic", 150);
			std::cout << basic;
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
			std::cout << high;
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
			std::cout << low;
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

			std::cout << one;
			std::cout << "Try 1 grade increment" << std::endl;
			one.incrementGrade(1);
			std::cout << one;
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

			std::cout << one;
			std::cout << "Try 3 grade increment" << std::endl;
			one.incrementGrade(3);
			std::cout << one;
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

			std::cout << one;
			std::cout << "Try 5 grade decrement" << std::endl;
			one.decrementGrade(5);
			std::cout << one;
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
			Bureaucrat one("one", 141);

			std::cout << one;
			std::cout << "Try 10 grade decrement" << std::endl;
			one.decrementGrade(10);
			std::cout << one;
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
	std::cout << "2. Increment grade" << std::endl;
	testIncrementGrade();
	std::cout << "3. Decrement grade" << std::endl;
	testDecrementGrade();
	return 0;
}