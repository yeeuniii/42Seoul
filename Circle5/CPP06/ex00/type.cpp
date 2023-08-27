#include "type.hpp"

bool	isSign(char	c)
{
	return c == '+' || c == '-';
}

bool	isNan(std::string str)
{
	return str == "nan";
}

bool	isInf(std::string str)
{
	if (isSign(str[0]) == false)
		return false;
	return str.substr(1) == "inf";
}

bool	isNanf(std::string str)
{
	return str == "nanf";
}

bool	isInff(std::string str)
{
	if (isSign(str[0]) == false)
		return false;
	return str.substr(1) == "inff";
}

bool	isPseudoDoubleLiteral(std::string str)
{
	return isNan(str) || isInf(str);
}

bool	isPseudoFloatLiteral(std::string str)
{
	return isNanf(str) || isInff(str);
}

bool	isCharLiteral(std::string literal)
{
	int	size = literal.size();

	if (size == 1 && isdigit(literal[0]) == false)
		return true;
	if (size != 3)
		return false;
	return literal[0] == '\'' && literal[2] == '\'';
}

bool	isIntLiteral(std::string literal)
{
	int	idx = 0;
	int	size = literal.size();

	if (isSign(literal[0]))
		idx++;
	while (idx < size && isdigit(literal[idx]))
		idx++;
	return idx == size;
}

bool	isFloatLiteral(std::string literal)
{
	int	idx = 0;
	int	size = literal.size();

	if (literal[size - 1] != 'f')
		return false;
	if (isPseudoFloatLiteral(literal))
		return true;
	if (isSign(literal[0]))
		idx++;
	while (idx < size - 1 && isdigit(literal[idx]))
		idx++;
	if (literal[idx] == '.' && idx != size - 2)
		idx++;
	while (idx < size - 1 && isdigit(literal[idx]))
		idx++;
	return idx == size - 1;
}

bool	isDoubleLiteral(std::string literal)
{
	int	idx = 0;
	int	size = literal.size();

	if (isPseudoDoubleLiteral(literal))
		return true;
	if (isSign(literal[0]))
		idx++;
	while (idx < size && isdigit(literal[idx]))
		idx++;
	if (literal[idx] == '.' && idx != size)
		idx++;
	while (idx < size && isdigit(literal[idx]))
		idx++;
	return idx == size;
}

e_type	getScalarType(std::string literal)
{
	if (literal.size() == 0) 
		return none;
	if (isCharLiteral(literal))
		return CHAR;
	if (isIntLiteral(literal))
		return INT;
	if (isFloatLiteral(literal))
		return FLOAT;
	if (isDoubleLiteral(literal))	
		return DOUBLE;
	return none;
}