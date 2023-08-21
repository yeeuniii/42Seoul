#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("ShrubberyCreation", 145, 137)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form)
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