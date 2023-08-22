#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), target("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("robotomy request", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
: AForm(form)
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

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned == false)
		throw AForm::NotSignException();
	if (this->executableGrade < executor.getGrade())
		throw AForm::GradeTooHighException("form`s grade is too high than executor.");
}