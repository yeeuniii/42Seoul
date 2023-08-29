#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <sstream>
#include <limits>
#include <ios>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& scalarConverter)
{
	*this = scalarConverter;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& scalarConverter)
{
	if (this != &scalarConverter)
	{
	}
	return *this;
}

void	ScalarConverter::convert(std::string literal)
{
	char	_char;
	int		_int;
	float	_float;
	double	_double;

	convertAll(literal, _char, _int, _float, _double);
	display(_char, _int, _float, _double);
}

void	ScalarConverter::convertAll(std::string literal, char& _char, int&_int, float& _float, double& _double)
{
	e_type	type = getScalarType(literal);
	
	if (type == none)
		return displayNoneType();
	if (type == CHAR)
	{
		_char = convertCharacter(literal);
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
		return ;
	}
	if (type == INT)
	{
		_int = convertInteger(literal);
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
		return ;
	}
	if (type == FLOAT)
	{
		_float = convertFloat(literal);
		_char = static_cast<char>(_float);
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
		return ;
	}
	if (type == DOUBLE)
	{
		_double = convertDouble(literal);
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
		return ;
	}
}

char	ScalarConverter::convertCharacter(std::string literal)
{
	const char	*str = literal.c_str();
	char		_char;

	_char = str[0];
	if (literal.size() == 3)
		_char = str[1];
	return _char;
}

int	ScalarConverter::convertInteger(std::string literal)
{
	std::stringstream	ss;
	int		_int;

	ss << literal;	
	ss >> _int;
	return _int;
}

float	ScalarConverter::convertFloat(std::string literal)
{
	float	_float;

	if (isInff(literal))
	{
		_float = std::numeric_limits<float>::infinity();
		_float *= isSign(literal[0]) ? (literal[0] == '+') - (literal[0] == '-') : 1;
		return _float;
	}
	if (isNanf(literal))
	{
		_float = std::numeric_limits<float>::quiet_NaN();
		return _float;
	}

	std::stringstream ss;

	ss << literal.substr(0, literal.size() - 1);
	ss >> _float;
	return _float;
}

double	ScalarConverter::convertDouble(std::string literal)
{
	double	_double;

	if (isInf(literal))
	{
		_double = std::numeric_limits<double>::infinity();
		_double *= isSign(literal[0]) ? (literal[0] == '+') - (literal[0] == '-') : 1;
		return _double;
	}
	if (isNan(literal))
	{
		_double = std::numeric_limits<double>::quiet_NaN();
		return _double;
	}
	
	std::stringstream ss;
	
	ss << literal;
	ss >> _double;
	return _double;
}

void	ScalarConverter::display(char _char, int _int, float _float, double _double)
{
	bool	isInfOrNan = isPseudo(_float) || isPseudo(_double);

	displayCharacter(_char, !isInfOrNan && isInChar(_int));
	displayInteger(_int, !isInfOrNan);
	displayFloat(_float, _float - _int == 0);
	displayDouble(_double, _double - _int == 0);
}
	
void	ScalarConverter::displayNoneType()
{
		std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: impossible" << std::endl
			<< "double: impossible" << std::endl;
}

void	ScalarConverter::displayCharacter(char _char, bool isPossible)
{
	std::cout << "char: ";
	if (isPossible == false)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isprint(_char) == false)
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << "'" << _char << "'" << std::endl;
}

void	ScalarConverter::displayInteger(int _int, bool isPossible)
{
	std::cout << "int: ";
	if (isPossible == false)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << _int << std::endl;
}

void	ScalarConverter::displayFloat(float _float, bool notDecimalPoint)
{
	std::cout << "float: ";
	if (notDecimalPoint)
	{
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
	}
	std::cout << _float << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

void	ScalarConverter::displayDouble(double _double, bool notDecimalPoint)
{
	std::cout << "double: ";
	if (notDecimalPoint)
	{
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
	}
	std::cout << _double << std::endl;
	std::cout.unsetf(std::ios::fixed);
}
