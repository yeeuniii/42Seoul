#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	this->type = "ice";
}

Ice::Ice(const Ice& ice) : AMateria(ice)
{
	*this = ice;
}

Ice::~Ice()
{

}

Ice&	Ice::operator=(const Ice& ice)
{
	if (this != &ice)
	{
		this->type = ice.type;
	}
	return *this;
}

AMateria*	Ice::clone() const
{
	return new Ice();
}
