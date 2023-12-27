#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

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
	checkExecute(executor.getGrade());
	
	std::cout << "Drrrrrrrrrrrr..." << std::endl;
	srand((unsigned int)time(0));
	int	randomNumber = rand() + executor.getGrade();
	std::cout << makeExecuteMessage(randomNumber % 2) << std::endl;
}

std::string			RobotomyRequestForm::makeExecuteMessage(int success) const
{
	std::string message = "Target " + this->target + " has been robotomized "; 
	
	message += success ? "success" : "fail";
	return message;
}