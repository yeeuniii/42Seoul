#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <string>
#include <iostream>
#include "type.hpp"

class ScalarConverter
{
	private:
		ScalarConverter();
	
	public:
		ScalarConverter(const std::string& literal);
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter&);

		static void	convert(std::string literal);
		static void	convertAll(std::string literal, char&, int&, float&, double&);
		static char	convertCharacter(std::string literal);
		static int	convertInteger(std::string literal);
		static float convertFloat(std::string literal);
		static double convertDouble(std::string literal);
		
		static void	display(char, int, float, double);
		static void	displayNoneType();
		static void	displayCharacter(char, bool isPossible);
		static void	displayInteger(int, bool isPossible);
		static void	displayFloat(float, bool hasNotDecimalPoint);
		static void	displayDouble(double, bool hasNotDecimalPoint);
};

#endif