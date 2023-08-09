#pragma once
#ifndef __WrongCat_HPP__
#define __WrongCat_HPP__

#include "WrongAnimal.hpp"
#include <string>

#define CAT_COLOR "\e[0;35m"

class WrongCat : public WrongAnimal
{
	private:

	public:
		WrongCat();
		WrongCat(const WrongCat& WrongCat);
		~WrongCat();
		WrongCat& operator=(const WrongCat& WrongCat);
		
		void	makeSound() const;
};

#endif