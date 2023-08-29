#include "utils.hpp"
#include <limits>

bool    isNan(float f)
{
    return f != f;
}

bool    isInfinity(float f)
{
    return f != 0 && f * 2 == f;
}

bool	isPseudo(float f)
{
	return isNan(f) || isInfinity(f);
}

bool    isNan(double d)
{
	return d != d;
}

bool    isInfinity(double d)
{
    return d != 0 && d * 2 == d;
}

bool	isPseudo(double d)
{
	return isNan(d) || isInfinity(d);
}

bool	isInChar(int value)
{
	return value >= 0 && value <= 255;
}

bool	isInInt(double value)
{
	return value >= std::numeric_limits<int>::min()
		&& value <= std::numeric_limits<int>::max();
}
