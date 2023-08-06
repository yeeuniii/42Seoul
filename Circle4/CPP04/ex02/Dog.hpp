#pragma once
#ifndef __Dog_HPP__
#define __Dog_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

#define DOG_COLOR "\e[0;33m"

class Dog : public AAnimal
{
	private:
		Brain	*brain;

	public:
		Dog();
		Dog(const Brain& brain);
		Dog(const Dog& dog);
		virtual ~Dog();
		Dog& operator=(const Dog& dog);
		
		void	setBrain(const Brain& brain);
		
		virtual void	makeSound() const;
		void	think() const;
};

#endif