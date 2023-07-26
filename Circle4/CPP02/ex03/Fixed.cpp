#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	this->number = 0;
}

Fixed::Fixed(const int number)
{
	this->number = number * (1 << this->fractionBit);
}

Fixed::Fixed(const float number)
{
	this->number = roundf(number * (1 << this->fractionBit));
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
	this->number /= fixed.getRawBits();
	return *this;
}

/*		increment / decrement operators		*/

Fixed	&Fixed::operator++(void) 
{
	this->number++;
	return *this;
}

Fixed	Fixed::operator++(int)  
{
	Fixed	tmp = *this;

	++this->number;
	return tmp;
}

Fixed	&Fixed::operator--(void) 
{
	this->number--;
	return *this;
}

Fixed	Fixed::operator--(int)  
{
	Fixed	tmp = *this;

	--this->number;
	return tmp;
}

/*		min / max method		*/

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return fixed1 < fixed2 ? fixed1 : fixed2;
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return fixed1 < fixed2 ? fixed1 : fixed2;
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return fixed1 > fixed2 ? fixed1 : fixed2;
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return fixed1 > fixed2 ? fixed1 : fixed2;
}
