#include "C.hpp"

C::C() : type("C") {}

C::~C() {}

const std::string&	C::getType() const
{
	return this->type;
}