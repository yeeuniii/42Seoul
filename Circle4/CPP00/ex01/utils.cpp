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

#include <iostream>

int	is_empty(std::string str)
{
	return (str.size() == 0
			|| ((isspace(str.front()) || str.front() == '\n')
			&& (isspace(str.back()) || str.back() == '\n')));
}
