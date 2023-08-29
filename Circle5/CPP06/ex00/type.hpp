#ifndef __TYPE_HPP__
#define __TYPE_HPP__

#include <string>

typedef enum Type
{
	none,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
} e_type;

e_type	getScalarType(std::string);
bool	isCharLiteral(std::string);
bool 	isIntLiteral(std::string);
bool 	isFloatLiteral(std::string);
bool 	isDoubleLiteral(std::string);

bool	isSign(char	c);
bool	isNan(std::string str);
bool	isInf(std::string str);
bool	isNanf(std::string str);
bool	isInff(std::string str);

#endif