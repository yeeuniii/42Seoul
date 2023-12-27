#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T& container, const int &value)
{
	typename T::iterator itr;
	
	itr = std::find(container.begin(), container.end(), value);
	if (itr == container.end())
		throw(std::out_of_range("Cannot find element"));
	return itr;
};

#endif