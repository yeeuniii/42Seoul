#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->number = number * (1 << this->fractionBit);
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->number = roundf(number * (1 << this->fractionBit));
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
	return this->number;
}

void	Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

int		Fixed::getFractionBits(void) const
{
	return this->fractionBit;
}

float	Fixed::toFloat(void) const
{
	return (float)this->number / (1 << this->fractionBit);
}

int		Fixed::toInt(void) const
{
	return this->number >> this->fractionBit;
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}