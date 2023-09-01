#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <exception>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &array);
		~Array();
		Array& operator=(const Array &array);

		T& operator[](const unsigned int &index) const;
		unsigned int	size() const;
};

#include "Array.tpp"

#endif