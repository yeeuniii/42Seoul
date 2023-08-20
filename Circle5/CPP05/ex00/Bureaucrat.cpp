#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat`s grade is too high";
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

Bureaucrat::~Bureaucrat()
{

}

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
	if (isHighGrade())
		throw Bureaucrat::GradeTooHighException();
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

const std::string&	Bureaucrat::getName()
{
	return this->name;
}

const int&	Bureaucrat::getGrade()
{
	return this->grade;
}