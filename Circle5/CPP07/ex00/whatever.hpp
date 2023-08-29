#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

template <typename T>
void	swap(T &x, T &y)
{
	T	tmp = x;

	x = y;
	y = tmp;
}

template <typename T>
T	min(T &x, T &y)
{
	return x < y ? x : y;
}

template <typename T>
T	max(T &x, T &y)
{
	return x > y ? x : y;
}

#endif