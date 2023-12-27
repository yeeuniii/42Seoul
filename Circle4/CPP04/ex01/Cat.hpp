#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

#define CAT_COLOR "\e[0;35m"

class Cat : public Animal
{
	private:
		Brain	*brain;

	public:
		Cat();
		Cat(const Brain& brain);
		Cat(const Cat& cat);
		virtual ~Cat();
		Cat& operator=(const Cat& cat);
		
		void	setBrain(const Brain& brain);

		virtual void	makeSound() const;
		void	think() const;
};

#endif