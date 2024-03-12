#pragma once
#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice(const Ice& ice);
		virtual ~Ice();
		Ice& operator=(const Ice& ice);

		virtual AMateria*	clone() const;
		virtual void use(ICharacter& target);
};


#endif