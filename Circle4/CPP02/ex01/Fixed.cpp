#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->number = number << this->fractionBit;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->number = roundf(number * 256);
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
	// std::cout << "getRawBits member functino called" << std::endl;
	return this->number;
}

void	Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->number / 256;
}

int		Fixed::toInt(void) const
{
	return this->number >> this->fractionBit;
}