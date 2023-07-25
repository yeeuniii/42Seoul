#pragma once
#ifndef __Fixed_HPP__
#define __Fixed_HPP__

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

		float	toFloat(void) const;
		int		toInt(void) const;
};

#endif