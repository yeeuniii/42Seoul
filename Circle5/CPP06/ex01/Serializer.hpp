#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include "Data.hpp"
#include <cstdint>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &serializer);

	public:
		~Serializer();
		Serializer&	operator=(const Serializer &serializer);
	
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif