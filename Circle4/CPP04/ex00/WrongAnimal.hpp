#pragma once
#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <string>

#define ANIMAL_COLOR "\e[0;32m"
#define WHITE  "\e[0;37m"

class WrongAnimal
{
	protected:
		std::string	type;
	
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& animal);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& animal);

		const std::string&	getType() const;

		void	makeSound() const;
};

#endif