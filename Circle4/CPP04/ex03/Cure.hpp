#pragma once
#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		Cure(const Cure& cure);
		~Cure();
		Cure& operator=(const Cure& cure);

		virtual AMateria*	clone() const;
		// virtual void use(ICharacer& target);
};


#endif