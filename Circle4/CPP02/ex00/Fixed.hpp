#pragma once
#ifndef __Fixed_HPP__
#define __Fixed_HPP__

class Fixed
{
	private:
		int					number;
		static const int	fracBit = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& fixed);
		~Fixed(void);
		Fixed& operator=(Fixed const& fixed);
};

#endif