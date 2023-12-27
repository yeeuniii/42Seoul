#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	signAndExecuteForm(Bureaucrat *bureaucrats[], AForm *form)
{
	int idx = 3;
	
	std::cout << *form;
	while (form->getIsSigned() == false)
	{
		bureaucrats[idx]->signForm(*form);
		idx--;
	}
	std::cout << *form << std::endl;
	for (int idx = 0; idx < 4; idx++)
	{
		std::cout << *bureaucrats[idx];
		bureaucrats[idx]->executeForm(*form);
		std::cout << std::endl;
	}
}

int main()
{
	Bureaucrat *bureaucrats[4];

	bureaucrats[0] = new Bureaucrat("One", 1);
	bureaucrats[1] = new Bureaucrat("Two", 20);
	bureaucrats[2] = new Bureaucrat("Three", 70);
	bureaucrats[3] = new Bureaucrat("Four", 140);
	
	std::cout << "----------Try to execute not signed form----------" << std::endl;
	{
		AForm	*form = new ShrubberyCreationForm("mountain");
	
		std::cout << *form;
		bureaucrats[0]->executeForm(*form);

		delete form;
	}
	std::cout << std::endl;
	std::cout << "----------Shruberry Creation Form----------" << std::endl;
	{
		AForm	*form = new ShrubberyCreationForm("home");

		signAndExecuteForm(bureaucrats, form);
		delete form;
	}
	std::cout << std::endl;
	std::cout << "----------Robotomy Request Form----------" << std::endl;
	{
		AForm	*form = new RobotomyRequestForm("robot");
		
		signAndExecuteForm(bureaucrats, form);
		delete form;
	}
	std::cout << std::endl;
	std::cout << "----------Presidential Pardon Form----------" << std::endl;
	{
		AForm	*form = new PresidentialPardonForm("tom");
		
		signAndExecuteForm(bureaucrats, form);
		delete form;
	}
	for (int idx = 0; idx < 4; idx++)
		delete bureaucrats[idx];
	// system("leaks form");
	return 0;
}