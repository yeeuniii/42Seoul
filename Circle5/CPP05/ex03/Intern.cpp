#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern &intern)
{
	if (this != &intern)
	{
	}
	return *this;
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &formTarget) const
{
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	idx = 0;

	try
	{
		while (formName != names[idx])
			idx++;
		std::cout << "Intern creates " << names[idx] << std::endl;
		switch (idx)
		{
			case 0:
				return new ShrubberyCreationForm(formTarget);
			case 1:
				return new RobotomyRequestForm(formTarget);
			case 2:
				return new PresidentialPardonForm(formTarget);
		}
	}
	catch (...)
	{
		std::cerr << "Form name is not invalid." << std::endl;
	}
	return 0;
}
