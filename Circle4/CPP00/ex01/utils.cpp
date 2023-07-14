#include <string>
#include <sstream>

int	convert_str_to_int(std::string str)
{
	int		num;

	std::stringstream ss(str);
	ss >> num;
	return num;
}
