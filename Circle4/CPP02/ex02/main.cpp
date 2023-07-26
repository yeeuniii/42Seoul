#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	std::cout << "-----comparison operators-----" << std::endl;
	{
		Fixed a(5);
		Fixed b(5.05f);

		std::cout << "5 > 5.05f = " << (a > b) << std::endl;
		std::cout << "5 < 5.05f = " << (a < b) << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----arithmetic operators-----" << std::endl;
	{
		std::cout << "5.05f + 2 = " << Fixed(5.05f) + Fixed(2) << std::endl;
		std::cout << "5.05f - 2 = " << Fixed(5.05f) - Fixed(2) << std::endl;
		std::cout << "7.625f * 2 = " << Fixed(7.625f) * Fixed(2) << std::endl;
		std::cout << "7.625f / 2 = " << Fixed(7.625f) / Fixed(2) << std::endl;
		// std::cout << "5.05f / 0 = " << Fixed(5.05f) / Fixed() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----increment/decrement operators-----" << std::endl;
	{
		Fixed a(5);

		std::cout << "a = " << a << std::endl;
		std::cout << "a++ = " << a++ << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a-- = " << a-- << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "++a = " << ++a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "--a = " << --a << std::endl;
		std::cout << "a = " << a << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----min / max methods-----" << std::endl;
	{
		Fixed a(5);
		Fixed b(5.05f);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "min : " << Fixed::min(a, b) << std::endl;
		std::cout << "max : " << Fixed::max(a, b) << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----Subject`s test-----" << std::endl;
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}
	return 0;
}