#include <string>
#include <sstream>
#include <ctype.h>

int	convert_str_to_int(std::string str)
{
	int		num;

	std::stringstream ss(str);
	ss >> num;
	return num;
}

int	is_digit(std::string str)
{
	int idx = 0;

	while (idx < (int)str.size() && isdigit(str[idx]))
		idx++;
	return (idx == (int)str.size());
}

#include <iostream>

int	is_empty(std::string str)
{
	return (str.size() == 0 || (isspace(str.front()) && isspace(str.back())));
}


