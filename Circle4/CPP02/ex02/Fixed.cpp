#include "Fixed.hpp"
#include <cmath>
#include <complex>

Fixed::Fixed(void)
{
	this->number = 0;
}

Fixed::Fixed(const int number)
{
	this->number = number << this->fractionBit;
}

Fixed::Fixed(const float number)
{
	this->number = roundf(number * pow(2, this->fractionBit));
}

Fixed::Fixed(const Fixed& fixed)
{
	this->number = fixed.getRawBits();
}

Fixed& Fixed::operator=(Fixed const& fixed)
{
	if (this != &fixed)
	{
		this->number = fixed.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void)
{

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
	return (float)this->number / pow(2, this->fractionBit);
}

int		Fixed::toInt(void) const
{
	return this->number >> this->fractionBit;
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed)
{
	out << (float)fixed.getRawBits() / pow(2, fixed.getFractionBits());
	return out;
}

/*		comparison operators		*/

bool	Fixed::operator>(const Fixed &fixed) const
{
	return this->number > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return this->number < fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return this->number >= fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return this->number <= fixed.getRawBits();
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return this->number == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return this->number != fixed.getRawBits();
}

/*		arithmetic operators		*/

Fixed	&Fixed::operator+(const Fixed &fixed) 
{
	this->number += fixed.getRawBits();
	return *this;
}

Fixed	&Fixed::operator-(const Fixed &fixed) 
{
	this->number -= fixed.getRawBits();
	return *this;
}

Fixed	&Fixed::operator*(const Fixed &fixed) 
{
	this->number *= fixed.getRawBits();
	return *this;
}

Fixed	&Fixed::operator/(const Fixed &fixed) 
{
	if (fixed.getRawBits() == 0)
	{
		std::cout << "CANNOT DO DIVISION BY 0." << std::endl;
		return *this;
	}
	this->number /= fixed.getRawBits();
	return *this;
}
