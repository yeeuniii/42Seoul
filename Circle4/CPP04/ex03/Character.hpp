#pragma once
#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	const static int	acceptableSize = 4;
	private:
		std::string	name;
		AMateria**	inventory;
		int			size;

	public:
		Character();
		Character(const std::string &name);
		Character(const Character& character);
		virtual ~Character();
		Character& operator=(const Character& character);
		
		virtual std::string const& getName() const;
		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter& target);

};

#endif