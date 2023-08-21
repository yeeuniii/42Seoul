#include "Bureaucrat.hpp"
#include <iostream>

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat`s grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat`s grade is too low.";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	handleGradeException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name)
{
	*this = bureaucrat;
	handleGradeException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
	{
		this->grade = bureaucrat.grade;
	}
	return *this;
}

void	Bureaucrat::handleGradeException() const
{
	handleHighGradeException();
	handleLowGradeException();
}

void	Bureaucrat::handleHighGradeException() const
{
	if (isHighGrade())
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::handleLowGradeException() const
{
	if (isLowGrade())
		throw Bureaucrat::GradeTooLowException();
}

bool	Bureaucrat::isHighGrade() const
{
	return this->grade > 150;
}

bool	Bureaucrat::isLowGrade() const
{
	return this->grade < 1;
}

const std::string&	Bureaucrat::getName() const
{
	return this->name;
}

const int&	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::incrementGrade(int grade)
{
	this->grade -= grade;
	handleLowGradeException();
}

void	Bureaucrat::decrementGrade(int grade)
{
	this->grade += grade;
	handleHighGradeException();
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return out;
}
		
void	Bureaucrat::signForm(const Form &form) const
{
	if (form.getIsSigned())
	{
		std::cout << this->name << " signed " << form.getName() << std::endl;
		return ;
	}
	std::cout << this->name << " couldn`t sign " << form.getName() 
		<< " because " << Form::GradeTooLowException().what() << std::endl;
}