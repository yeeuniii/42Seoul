#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>
#include <ios>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const std::string& literal)
: literal(literal), isPseudo(false)
{
	this->type = getScalarType(this->literal);
	convert();
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
		this->isPseudo = scalarConverter.isPseudo;
		this->_char = scalarConverter._char;
		this->_int = scalarConverter._int;
		this->_float = scalarConverter._float;
		this->_double = scalarConverter._double;
	}
	return *this;
}

void	ScalarConverter::setLiteral(const std::string& string)
{
	this->literal = string;
	convert();
}

e_type	ScalarConverter::getType() const
{
	return this->type;
}

void	ScalarConverter::convert()
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
	{
		this->_float = std::numeric_limits<float>::infinity();
		this->_float *= (this->literal[0] == '+') - (this->literal[0] == '-');
		this->isPseudo = true;
	}
	if (isNanf(this->literal))
	{
		this->_float = std::numeric_limits<float>::quiet_NaN();
		this->isPseudo = true;
	}
	if (this->isPseudo == true)
		return ;

	std::stringstream ss;

	ss << this->literal.substr(0, this->literal.size() - 1);
	ss >> this->_float;
}

void	ScalarConverter::convertDouble()
{
	if (isInf(this->literal))
	{
		this->_double = std::numeric_limits<double>::infinity();
		this->_double *= (this->literal[0] == '+') - (this->literal[0] == '-');
		this->isPseudo = true;
	}
	if (isNan(this->literal))
	{
		this->_double = std::numeric_limits<double>::quiet_NaN();
		this->isPseudo = true;
	}
	if (this->isPseudo == true)
		return ;
	
	std::stringstream ss;
	
	ss << this->literal;
	ss >> this->_double;
}

void	ScalarConverter::display() const
{
	if (!handleNoneType())
		return ;
	displayCharacter();
	displayInteger();
	displayFloat();
	displayDouble();
}

void	ScalarConverter::displayCharacter() const
{
	std::cout << "char: ";
	if (this->isPseudo == true)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isprint(this->_char) == false)
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << "'" << this->_char << "'" << std::endl;
}

void	ScalarConverter::displayInteger() const
{
	std::cout << "int: ";
	if (this->isPseudo == true)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << this->_int << std::endl;
}

void	ScalarConverter::displayFloat() const
{
	std::cout << "float: ";
	if (this->isPseudo)
		std::cout.setf(std::ios_base::showpos);
	if (this->_float - this->_int == 0)
	{
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
	}
	std::cout << this->_float << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

void	ScalarConverter::displayDouble() const
{
	std::cout << "double: ";
	if (this->isPseudo)
		std::cout.setf(std::ios_base::showpos);
	if (this->_double - this->_int == 0)
	{
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
	}
	std::cout << this->_double << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

e_type		ScalarConverter::handleNoneType() const
{
	if (this->type == none)
	{
		std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: impossible" << std::endl
			<< "double: impossible" << std::endl;
	}
	return this->type;
}