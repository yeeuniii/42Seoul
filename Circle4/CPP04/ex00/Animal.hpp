#pragma once
#ifndef __Animal_HPP__
#define __Animal_HPP__

#include <string>

#define ANIMAL_COLOR "\e[0;32m"
#define WHITE  "\e[0;37m"

class Animal
{
	protected:
		std::string	type;
	
	public:
		Animal();
		Animal(const Animal& animal);
		virtual ~Animal();
		Animal& operator=(Animal const& animal);
};

#endif