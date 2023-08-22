#include "AForm.hpp"
#include <iostream>

AForm::GradeTooHighException::GradeTooHighException() : message("form`s grade is too high.") {}

AForm::GradeTooHighException::GradeTooHighException(const char *message) : message(message) {}

const char* AForm::GradeTooHighException::what() const throw()
{
	return this->message;
}

AForm::GradeTooLowException::GradeTooLowException() : message("form`s grade is too low.") {}

AForm::GradeTooLowException::GradeTooLowException(const char *message) : message(message) {}

const char* AForm::GradeTooLowException::what() const throw()
{
	return this->message;
}

AForm::AForm() : name(""), signableGrade(150), executableGrade(150) {} 

AForm::AForm(std::string name, int signableGrade, int executableGrade)
: name(name), signableGrade(signableGrade), executableGrade(executableGrade)
{
	handleGradeException();
}

AForm::AForm(const AForm& form)
: name(form.name), signableGrade(form.signableGrade), executableGrade(form.executableGrade)
{
	handleGradeException();	
}

AForm::~AForm() {}

AForm&	AForm::operator=(const AForm& form)
{
	if (this != &form)
	{
		this->isSigned = form.isSigned;
	}
	return *this;
}

void	AForm::handleGradeException() const
{
	handleHighGradeException();
	handleLowGradeException();
}

void	AForm::handleHighGradeException() const
{
	if (isHighGrade())
		throw AForm::GradeTooHighException();
}

void	AForm::handleLowGradeException() const
{
	if (isLowGrade())
		throw AForm::GradeTooLowException();
}

bool	AForm::isHighGrade() const
{
	return this->signableGrade > 150 || this->executableGrade > 150;
}

bool	AForm::isLowGrade() const
{
	return this->signableGrade < 1 || this->executableGrade < 1;
}

const std::string&	AForm::getName() const
{
	return this->name;
}

const bool&	AForm::getIsSigned() const
{
	return this->isSigned;
}

const int&	AForm::getSignableGrade() const
{
	return this->signableGrade;
}

const int&	AForm::getExecutableGrade() const
{
	return this->executableGrade;
}

void	AForm::beSigned(Bureaucrat bureaucrat)
{
	this->isSigned = bureaucrat.getGrade() <= this->signableGrade;
	if (this->isSigned == false)
		throw AForm::GradeTooLowException();
}

std::ostream&	operator<<(std::ostream &out, const AForm &form)
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