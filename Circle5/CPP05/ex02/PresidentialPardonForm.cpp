#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("") {} 

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("PresidentialPardon", 25, 5)
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
		throw AForm::NotSignException();
	if (this->executableGrade < executor.getGrade())
		throw AForm::GradeTooHighException("form`s grade is too high than executor.");
}