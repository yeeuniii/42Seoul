#include  "Form.hpp"

Form::Form(std::string name, int signableGrade, int executableGrade) :
	name(name), signableGrade(signableGrade), executableGrade(executableGrade)
{
	handleGradeException();
}

Form::Form(const Form& form) :
	name(form.name), signableGrade(form.signableGrade), executableGrade(form.executableGrade)
{
	handleGradeException();	
}

Form::~Form() {}

Form&	Form::operator=(const Form& form)
{
	if (this != &form)
	{
		this->isSigned = form.isSigned;
	}
	return *this;
}

void	Form::handleGradeException() const
{
	handleHighGradeException();
	handleLowGradeException();
}

void	Form::handleHighGradeException() const
{
	if (isHighGrade())
		throw Form::GradeTooHighException();
}

void	Form::handleLowGradeException() const
{
	if (isLowGrade())
		throw Form::GradeTooLowException();
}

bool	Form::isHighGrade() const
{
	return this->signableGrade > 150 || this->executableGrade > 150;
}

bool	Form::isLowGrade() const
{
	return this->signableGrade < 1 || this->executableGrade < 1;
}

