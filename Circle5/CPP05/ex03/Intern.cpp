#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

Intern::MakingFormException::MakingFormException(std::string formName) 
{
	std::string	message(formName + " does not exist");

	this->message = message.c_str();
	this->message = strdup(this->message);
}

Intern::MakingFormException::~MakingFormException() throw()
{
	if (this->message)
		delete this->message;
}

const char*	Intern::MakingFormException::what() const throw()
{
	return this->message;
}

Intern::Intern() {}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &intern)
{
	if (this != &intern)
	{
	}
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) const
{
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int idx = 0;

	while (idx < 3 && formName != names[idx])
		idx++;
	if (idx == 3)
	{
		throw MakingFormException(formName);
	}
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
	return 0;
}
