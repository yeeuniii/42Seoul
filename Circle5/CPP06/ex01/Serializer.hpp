#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include "Data.hpp"
#include <cstdint>

class Serializer
{
	private:

	public:
		Serializer();
		Serializer(const Serializer &serializer);
		~Serializer();
		Serializer&	operator=(const Serializer &serializer);
	
		uintptr_t	serialize(Data* ptr);
		Data		*deserialize(uintptr_t raw);
};

#endif