#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <string>

#define BRAIN_COLOR "\e[0;34m"
#define WHITE  "\e[0;37m"

class Brain
{
	private:
		std::string	ideas[100];
		int	index;

	public:
		Brain();
		Brain(const Brain& brain);
		~Brain();
		Brain&	operator=(const Brain& brain);

		void	setIdeas(const std::string ideas[]);
		void	addIdea(const std::string idea);
		void	displayIdeas() const;
};

#endif