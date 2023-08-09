#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria()
{
	this->type = "cure";
}

Cure::Cure(const Cure& cure) : AMateria(cure)
{
	*this = cure;
}

Cure::~Cure()
{

}

Cure&	Cure::operator=(const Cure& cure)
{
	if (this != &cure)
	{
	}
	return *this;
}

AMateria*	Cure::clone() const
{
	return new Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "`s wounds *" << std::endl;
}