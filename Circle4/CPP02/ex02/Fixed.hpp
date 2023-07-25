#pragma once
#ifndef __Fixed_HPP__
#define __Fixed_HPP__

#include <iostream>

class Fixed
{
	private:
		int					number;
		static const int	fractionBit = 8;

	public:
		Fixed(void);
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed& fixed);
		~Fixed(void);
		Fixed& operator=(Fixed const& fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		getFractionBits(void) const;

		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;

		Fixed	&operator+(const Fixed &fixed);
		Fixed	&operator-(const Fixed &fixed);
		Fixed	&operator*(const Fixed &fixed);
		Fixed	&operator/(const Fixed &fixed);
};

std::ostream& operator<<(std::ostream& out, const Fixed &fixed);

#endif