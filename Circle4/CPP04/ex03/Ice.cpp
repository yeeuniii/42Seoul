#include "Ice.hpp"
#include <iostream>

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
	}
	return *this;
}

AMateria*	Ice::clone() const
{
	return new Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}