#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <string>
#include <iostream>
#include "type.hpp"

class ScalarConverter
{
	private:
		std::string literal;
		e_type		type;
		bool		isPseudo;
		
		char		_char;
		int			_int;
		float		_float;
		double		_double;

		ScalarConverter();
		
		void	convertCharacter();
		void	convertInteger();
		void	convertFloat();
		void	convertDouble();
		
		void	displayCharacter() const;
		void	displayInteger() const;
		void	displayFloat() const;
		void	displayDouble() const;
		e_type	handleNoneType() const;
		
	public:
		ScalarConverter(const std::string& literal);
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter&);

		void	setLiteral(const std::string& string);
		e_type	getType() const;

		void	convert();
		void	display() const;
};

std::ostream&	operator<<(std::ostream&, const ScalarConverter&);

#endif