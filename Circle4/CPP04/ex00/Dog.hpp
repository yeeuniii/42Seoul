#pragma once
#ifndef __Dog_HPP__
#define __Dog_HPP__

#include "Animal.hpp"
#include <string>

#define DOG_COLOR "\e[0;33m"

class Dog : public Animal
{
	private:
		std::string	name;

	public:
		Dog();
		Dog(const std::string name);
		Dog(const Dog& dog);
		virtual ~Dog();
		Dog& operator=(Dog const& dog);
};

#endif