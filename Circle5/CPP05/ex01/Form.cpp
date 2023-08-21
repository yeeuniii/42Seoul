#include "Form.hpp"
#include <iostream>

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form`s grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form`s grade is too low.";
}

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

const std::string&	Form::getName() const
{
	return this->name;
}

const bool&	Form::getIsSigned() const
{
	return this->isSigned;
}

const int&	Form::getSignableGrade() const
{
	return this->signableGrade;
}

const int&	Form::getExecutableGrade() const
{
	return this->executableGrade;
}

void	Form::beSigned(Bureaucrat bureaucrat)
{
	this->isSigned = bureaucrat.getGrade() <= this->signableGrade;
	if (this->isSigned == false)
		throw Form::GradeTooLowException();
}

std::ostream&	operator<<(std::ostream &out, const Form &form)
{
	out << form.getName()
		<< ", form signable grade " << form.getSignableGrade()
		<< ", executable grade " << form.getExecutableGrade() << "." << std::endl;
	out << "And it got signed";
	if (form.getIsSigned() == false)
		out << " fail";
	out << "." << std::endl;;
	return out;
}