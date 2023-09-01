#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &array)
{
	this->_array = 0;
	*this = array;
}

template <typename T>
Array<T>::~Array()
{
	if (this->_array)
		delete[] this->_array;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array &array)
{
	if (this != &array)
	{
		if (this->_size)
			delete[] this->_array;
		this->_size = array._size;
		this->_array = new T[this->_size];
		for (unsigned int idx = 0; idx < this->_size; idx++)
			this->_array[idx] = array._array[idx];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](const unsigned int &index) const
{
	if (index >= this->_size)
		throw std::exception();
	return this->_array[index];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return this->_size;
}
