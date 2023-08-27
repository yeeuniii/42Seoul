#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>
#include <ios>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const std::string& literal) : literal(literal)
{
	this->type = getScalarType(this->literal);
}

ScalarConverter::ScalarConverter(const ScalarConverter& scalarConverter)
{
	*this = scalarConverter;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& scalarConverter)
{
	if (this != &scalarConverter)
	{
		this->literal = scalarConverter.literal;
		this->type = scalarConverter.type;
	}
	return *this;
}

void	ScalarConverter::setLiteral(const std::string& string)
{
	this->literal = string;
}

e_type	ScalarConverter::getType() const
{
	return this->type;
}

void	ScalarConverter::convertScalar()
{
	if (this->type == CHAR)
	{
		convertCharacter();
		this->_int = static_cast<int>(this->_char);
		this->_float = static_cast<float>(this->_char);
		this->_double = static_cast<double>(this->_char);
		return ;
	}
	if (this->type == INT)
	{
		convertInteger();
		this->_char = static_cast<char>(this->_int);
		this->_float = static_cast<float>(this->_int);
		this->_double = static_cast<double>(this->_int);
		return ;
	}
	if (this->type == FLOAT)
	{
		convertFloat();
		this->_char = static_cast<char>(this->_float);
		this->_int = static_cast<int>(this->_float);
		this->_double = static_cast<double>(this->_float);
		return ;
	}
	if (this->type == DOUBLE)
	{
		convertDouble();
		this->_char = static_cast<char>(this->_double);
		this->_int = static_cast<int>(this->_double);
		this->_float = static_cast<float>(this->_double);
		return ;
	}
}

void	ScalarConverter::convertCharacter()
{
	const char	*str = this->literal.c_str();

	this->_char = str[0];
	if (this->literal.size() == 3)
		this->_char = str[1];
}

void	ScalarConverter::convertInteger()
{
	std::stringstream	ss;

	ss << this->literal;	
	ss >> this->_int;
}

void	ScalarConverter::convertFloat()
{
	if (isInff(this->literal))
		this->_float = std::numeric_limits<float>::infinity();
	if (isNanf(this->literal))
		this->_float = std::numeric_limits<float>::quiet_NaN();
	
	std::stringstream ss;

	ss << this->literal;
	ss >> this->_float;
}

void	ScalarConverter::convertDouble()
{
	if (isInff(this->literal))
		this->_double = std::numeric_limits<double>::infinity();
	if (isNanf(this->literal))
		this->_double = std::numeric_limits<double>::quiet_NaN();
	
	std::stringstream ss;

	ss << this->literal;
	ss >> this->_double;
}

void	ScalarConverter::display() const
{
	displayCharacter();
	displayInteger();
	displayFloat();
	displayDouble();
}

void	ScalarConverter::displayCharacter() const
{
	std::cout << "char: ";
	if (isprint(this->_char) == false)
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << "'" << this->_char << "'" << std::endl;
}

void	ScalarConverter::displayInteger() const
{
	std::cout << "int: " << this->_int << std::endl;
}

void	ScalarConverter::displayFloat() const
{
	if (this->_float - this->_int == 0)
	{
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
	}
	std::cout << "float: " << this->_float << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

void	ScalarConverter::displayDouble() const
{
	if (this->_double - this->_int == 0)
	{
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
	}
	std::cout << "double: " << this->_double << std::endl;
	std::cout.unsetf(std::ios::fixed);
}
