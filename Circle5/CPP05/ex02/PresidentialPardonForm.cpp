#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("ShrubberyCreation", 145, 137)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
: AForm(form)
{
	*this = form;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
	{
		this->target = form.target;
	}
	return *this;
}

const std::string&	PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned == false)
		throw AForm::GradeTooLowException();
	if (this->executableGrade < executor.getGrade())
		throw AForm::GradeTooLowException("form`s grade is too high than executor.");
}