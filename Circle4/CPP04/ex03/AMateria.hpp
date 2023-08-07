#pragma once
#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <string>

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& aMateria);
		virtual ~AMateria();
		AMateria& operator=(const AMateria& aMateria);

		std::string const&	getType() const;
		virtual AMateria*	clone() const = 0;
		// virtual void use(ICharacer& target);
};

#endif