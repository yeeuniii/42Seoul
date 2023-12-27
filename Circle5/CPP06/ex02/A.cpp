#include "A.hpp"

A::A() : type("A") {}

A::~A() {}

const std::string&	A::getType() const
{
	return this->type;
}