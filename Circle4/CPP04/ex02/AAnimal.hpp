#pragma once
#ifndef __AAnimal_HPP__
#define __AAnimal_HPP__

#include <string>

#define AANIMAL_COLOR "\e[0;31m"
#define WHITE  "\e[0;37m"

class AAnimal
{
	protected:
		std::string	type;
	
	public:
		AAnimal();
		AAnimal(const AAnimal& animal);
		virtual ~AAnimal();
		AAnimal& operator=(const AAnimal& animal);

		const std::string&	getType() const;

		virtual void	makeSound() const = 0;
};

#endif