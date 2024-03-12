#include "B.hpp"

B::B() : type("B") {}

B::~B() {}

const std::string&	B::getType() const
{
	return this->type;
}