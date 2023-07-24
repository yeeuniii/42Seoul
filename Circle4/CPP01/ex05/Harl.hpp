#pragma once
#ifndef __Harl_HPP__
#define __Harl_HPP__

#include <string>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	displayInvalid(void);
		int		getIndex(std::string level);

	public:
		void	complain(std::string level);
};

#endif