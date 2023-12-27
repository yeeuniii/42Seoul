#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("") {}

AMateria::AMateria(std::string const& type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &aMateria)
{
	*this = aMateria;	
}

AMateria::~AMateria()
{

}

AMateria&	AMateria::operator=(const AMateria& aMateria)
{
	if (this != &aMateria)
	{
	}
	return *this;
}

std::string const&	AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* AMaterial " << target.getName() << " *" << std::endl;
}