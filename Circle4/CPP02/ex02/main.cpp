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
		Fixed const add(Fixed(5.05f) + Fixed(2));
		Fixed const minus(Fixed(5.05f) - Fixed(2));
		Fixed const multi(Fixed(7.625f) * Fixed(2));
		Fixed const division(Fixed(7.625f) / Fixed(2));
		Fixed const division0(Fixed(5.05f) / Fixed());
		
		std::cout << add << std::endl;
		std::cout << minus << std::endl;
		std::cout << multi << std::endl;
		std::cout << division << std::endl;
		std::cout << division0 << std::endl;
	}

	// Fixed a;
	// Fixed const b(Fixed(5.05f) * Fixed(2));

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}