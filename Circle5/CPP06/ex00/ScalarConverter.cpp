#include "ScalarConverter.hpp"

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