#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testConstructor()
{
	std::cout << "----------Basic Test----------" << std::endl;
	{
		try
		{
			Form basic("basic", 1, 2);
			std::cout << basic;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----------High Test----------" << std::endl;
	{
		try
		{
			Form high("high", 0, 1);
			std::cout << high;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----------Low Test----------" << std::endl;
	{
		try
		{
			Form low("low", 150, 151);
			std::cout << low;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}

void	testSign()
{
	std::cout << "----------Success----------" << std::endl;
	{
		Bureaucrat bureaucrat("tom", 23);
		Form form("form", 25, 1);
	
		std::cout << bureaucrat;
		std::cout << form;

		bureaucrat.signForm(form);
	
		std::cout << bureaucrat;
		std::cout << form;
	}
	std::cout << std::endl;
	std::cout << "----------Fail----------" << std::endl;
	{
		Bureaucrat bureaucrat("brown", 100);
		Form form("form", 25, 1);
	
		std::cout << bureaucrat;
		std::cout << form;

		bureaucrat.signForm(form);
	
		std::cout << bureaucrat;
		std::cout << form;
	}
}

int main()
{
	std::cout << "1. Construct" << std::endl;
	testConstructor();
	std::cout << "2. Bureaucrat try to sign form" << std::endl;
	testSign();	
	return 0;
}