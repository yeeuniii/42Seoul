#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form)
{
	*this = form;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
	{
		this->target = form.target;
	}
	return *this;
}

const std::string&	RobotomyRequestForm::getTarget() const
{
	return this->target;
}