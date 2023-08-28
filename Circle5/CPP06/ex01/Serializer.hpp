#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include "Data.hpp"
#include <cstdint>

class Serializer
{
	private:
		Serializer();

	public:
		Serializer(const Serializer &serializer);
		~Serializer();
		Serializer&	operator=(const Serializer &serializer);
	
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif