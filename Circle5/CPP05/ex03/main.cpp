#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	someRandomIntern;
	
	std::cout << "----------Success----------" << std::endl;
	{
		AForm*	rrf;

		try
		{
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
			std::cout << *rrf;
			delete rrf;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----------Fail----------" << std::endl;
	{
		AForm*	rrf;

		try
		{
			rrf = someRandomIntern.makeForm("random", "tom");
		
			std::cout << *rrf;
			delete rrf;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}