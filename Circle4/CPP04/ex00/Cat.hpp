#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"
#include <string>

#define CAT_COLOR "\e[0;35m"

class Cat : public Animal
{
	private:
		std::string	name;

	public:
		Cat();
		Cat(const std::string name);
		Cat(const Cat& cat);
		virtual ~Cat();
		Cat& operator=(Cat const& cat);
};

#endif