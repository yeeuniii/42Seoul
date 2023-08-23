#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("") {} 

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("presidential pardon", 25, 5)
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
	checkExecute(executor.getGrade());
	std::cout << "Target " << this->target << " has been pardoned by Zamphod Beeblebrox." << std::endl;
}