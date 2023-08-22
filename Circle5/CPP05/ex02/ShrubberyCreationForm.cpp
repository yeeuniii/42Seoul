#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreation", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
: AForm(form)
{
	*this = form;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	if (this != &form)
	{
		this->target = form.target;
	}
	return *this;
}

const std::string&	ShrubberyCreationForm::getTarget() const
{
	return this->target;
}
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned == false)
		throw AForm::NotSignException();
	if (this->executableGrade < executor.getGrade())
		throw AForm::GradeTooHighException("form`s grade is too high than executor.");
}