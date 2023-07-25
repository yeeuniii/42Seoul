#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->number = fixed.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
	{
		this->number = fixed.getRawBits();
	}
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member functino called" << std::endl;
	return this->number;
}

void	Fixed::setRawBits(int const raw)
{
	this->number = raw;
}