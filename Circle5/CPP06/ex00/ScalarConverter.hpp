#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <string>
#include "type.hpp"

class ScalarConverter
{
	private:
		std::string literal;
		e_type		type;
		
		ScalarConverter();
		
	public:
		char		_char;
		int			_int;
		float		_float;
		double		_double;
		ScalarConverter(const std::string& literal);
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter&);

		void	setLiteral(const std::string& string);
		e_type	getType() const;

		// void	setCharacter(const char& character);
		// void	setInteger(const int& integer);
		// void	setFloat(const float& floatLiteral);
		// void	setDouble(const double& doubleLiteral);

		void	convert();
		void	convertCharacter();
		void	convertInteger();
		void	convertFloat();
		void	convertDouble();
};

#endif